#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	map<int, int> mp;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		ans += mp[id];
		mp[i + x]++;
	}
	cout << ans;
}