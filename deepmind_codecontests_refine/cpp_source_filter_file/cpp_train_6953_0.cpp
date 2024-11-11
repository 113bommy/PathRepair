#include <iostream>
using namespace std;

int n;

int main() {
	cin >> n;
	for (int i=1; i<=9; i++) {
		if (a % i == 0 && a / i <= 9) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
}