#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int a = 0, b = 0, c = 0;
	for (char &d : s) {
		if (d == 'a') {
			a++;
		}
		if (d == 'b') {
			b++;
		}
		if (d == 'c') {
			c++;
		}
	}
	cout << (max({a, b, c}) - min({a, b, c}) <= 1 ? "YES" : "NO") << endl;
	return 0;
}