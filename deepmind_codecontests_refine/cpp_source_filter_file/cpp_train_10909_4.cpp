#include <iostream>
using namespace std;


int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	int res = 0;

	char pin_s[4] = "000";
	for (int pin = 0; pin < 1000; ++pin) {
		vsprintf(pin_s, "%03d", pin);
		int state = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == pin_s[state]) {
				state++;
				if (state == 3) {
					res++;
					break;
				}
			}
		}
	}

	cout << res << endl;

	return 0;
}