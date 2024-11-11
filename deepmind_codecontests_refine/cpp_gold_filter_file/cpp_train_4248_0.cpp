#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, ans = 0, f = 10;
	cin >> n;
	if (n % 2 == 0) {
		while (n >= f) {
			ans += (n / f);
			f *= 5;
		}
	}
	cout << ans << endl;
	return(0);
}
