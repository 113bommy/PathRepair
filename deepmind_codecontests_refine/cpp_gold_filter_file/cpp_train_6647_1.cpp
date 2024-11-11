#include <bits/stdc++.h>

using namespace std;

long long n, sum, a[100001];

int main () {
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i], sum += a[i];
	if (sum % (n * (n + 1) / 2) != 0) cout << "NO", exit (0);
	sum /= (n * (n + 1) / 2);
	a[n + 1] = a[1];
	for (int i = 1; i <= n; i ++) {
		if (a[i + 1] - a[i] - sum > 0 || (a[i + 1] - a[i] - sum) % n != 0) cout << "NO", exit (0);
	}
	cout << "YES";
}