#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, c[510], s[510], f[510];
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> c[i] >> s[i] >> f[i];
	}
	for (int i = 0; i < n; i++) {
		int b = 0;
		for (int j = i; j < n - 1; j++) {
			if (b < s[j]) {
				b = s[j];
			} else if (b % f[j] == 0) {
			} else {
				b = b + f[j] - b % f[j];
			}
			b += c[j];
		}
		cout << b << endl;
	}
	return 0;
}