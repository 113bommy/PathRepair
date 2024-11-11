#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main() {
	int n; cin >> n;
	ll ans = 0;
	map<int, int> cnt;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		ans += x, cnt[x]++;
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int b, c; cin >> b >> c;
		ans += 1LL * (c - b) * cnt[b];
		cout << ans << "\n";
		cnt[c] += cnt[b], cnt[b] = 0;
	}
}