#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

using namespace std;
using ll = long long;
const ll mod = 998244353;
int main() {
	ll n, k;
	cin >> n >> k;
	vector<int> l(k), r(k);
	rep (i, k) {
		cin >> l[i] >> r[i];
	}
	vector<int> dp(n + 10);
	dp[1] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] += dp[i-1];
		dp[i] %= mod;
		rep(j, k) {
			int num = min(i + r[j] + 1, (int)(n + 1));
			int nu = min (i + l[j], (int)(n + 1));
			dp[nu] += dp[i];
			dp[nu] %= mod;
			dp[num] -= dp[i];
			if (dp[num] < 0) dp[num] += mod;
		}
	}
	dp[n] %= mod;
	cout << dp[n] << endl;
	return 0;
}
