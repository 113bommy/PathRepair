#include<bits/stdc++.h>
#define rep(i,n) for(int (i) = 0;(i) < (n);(i)++)
using namespace std;
typedef long long ll;

int main(void) {
	ll n, k;
	cin >> n >> k;
	vector<int> a(n), f(n);
	rep (i, n) cin >> a[i];
	rep (i, n) cin >> f[i];

	sort(a.begin(), a.end());
	sort(f.rbegin(), f.rend());


	ll l = -1, r = 1e12;
	while (r - l > 1) {
		ll c = (r + l) / 2;
		bool ok = [&]{
			ll sum = 0;
			rep (i, n) {
				sum += max(0ll, a[i] - c / f[i]);
			}
			return s <= k;
		}();
		if (ok) r = c; else l = c;
	}
	cout << r << endl;
	return 0;
}
