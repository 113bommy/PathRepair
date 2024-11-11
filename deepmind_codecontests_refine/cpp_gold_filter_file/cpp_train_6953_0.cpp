#include <iostream>
using namespace std;

int n;

int main() {
	cin >> n;
	for (int i=1; i<=9; i++) {
		if (n % i == 0 && n / i <= 9) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
}