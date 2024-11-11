#include <bits/stdc++.h>
using namespace std;
int n, m, t, a[109];
int main() {
	cin >> n >> m >> t; a[0] = -m, a[n+ 1] = t + m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int ret = 0;
	for(int i = 0; i <= n; i++) ret += max(a[i + 1] - a[i] - 2 * m, 0);
	cout << ret << endl;
	return 0;
}