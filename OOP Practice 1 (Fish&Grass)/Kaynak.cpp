#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

class fish {
private:
	int fishNumber;
	int eatingPerDay;

	int calculateEating() {
		return fishNumber * eatingPerDay;
	}

	int dailyNeed() {
		return calculateEating();
	}

public:
	fish() {
		fishNumber = 100;
		eatingPerDay = 5;
	}

	int getFishNumber() {
		return fishNumber;
	}

	int eat(int availableGrass) {
		int need = dailyNeed();
		int eaten = min(need, availableGrass);

		if (availableGrass >= need) {
			fishNumber = (fishNumber * 3) / 2;
		}
		else {
			fishNumber = (fishNumber * 2) / 3;
		}
		return eaten;
	}
};

class grass {
private:
	int grassNumber;
	int growthPerDay;

public:
	grass() {
		grassNumber = 1000;
		growthPerDay = 300;
	}

	int grow() {
		grassNumber += growthPerDay;
		return grassNumber;
	}

	int getGrassNumber() {
		return grassNumber;
	}

	int consume(int amount) {
		if (amount < 0) {
			amount = grassNumber = 0;
			return grassNumber;
		}
		if (amount > grassNumber) {
			amount = grassNumber;
		}
			grassNumber -= min(amount, grassNumber);
			return grassNumber;
		
	}
};

int simulateDay(fish& fishObj, grass& grassObj, int days) {

	cout << "Before the simulation start, we have 100 Fish and 1000 units of grass." << endl << "Grass grows 300 units per day." << endl << endl;

	for (int i = 0; i < days; i++) {
		cout << "Day  " << i + 1 << endl;

		grassObj.grow();
		int available = grassObj.getGrassNumber();
		cout << "Initial grass after groth: " << available << endl;

		int initialFish = fishObj.getFishNumber();

		int eaten = fishObj.eat(available);
		grassObj.consume(eaten);
		int remainingGrass = available - eaten;

		int lastFish = fishObj.getFishNumber();

		cout << "Fish number: " << fishObj.getFishNumber() << endl;

		int difference = initialFish - lastFish;
		if (difference < 0) {
			cout << abs(difference) << " new fish were born. " << endl;
		}
		else if (difference > 0) {
			cout << difference << " fish were died." << endl;
		}
		else {
			cout << "There was no change in the number of fish." << endl;
		}

		
		cout << "Eaten Grass: " << eaten << endl;
		cout << "Remaining Grass number: " << remainingGrass << endl;
		cout << endl;

	}
	return 0;

}

int main() {
	int days;

	fish myFish;
	grass myGrass;

	simulateDay(myFish, myGrass, 15);
	return 0;
}
