#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, k;
	cin >> k >> a >> b;

	int res = (b - b % k);
	if (res < a) {
		cout << "NG";
	} else cout << "OK";
}
