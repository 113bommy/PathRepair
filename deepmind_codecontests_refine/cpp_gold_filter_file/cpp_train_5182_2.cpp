#include "bits/stdc++.h"
using namespace std;

#define ll long long

int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> p(n+1);
	vector<ll> c(n+1);
	vector<ll> q;
	ll i, j;
	ll buf;
	ll total;
	ll ans = -1e10;
	for (i = 1; i <= n; i++) {
		cin >> p[i];
	}
	for (i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (i = 1; i <= n; i++) {
		buf = i;
		total = 0;
		while (1) {
			buf = p[buf];
			total += c[buf];
			q.push_back(c[buf]);
			if (buf == i)break;
		}
		buf = 0;
		for (j = 0; j < q.size(); j++) {
			buf += q[j];
			if (total > 0)ans = max(ans, buf + total * ((k - j - 1) / (ll)q.size()));
			else ans = max(ans, buf);
			if (j + 1 == k)break;
		}
		q.clear();
	}
	cout << ans << endl;

	return 0;
}
