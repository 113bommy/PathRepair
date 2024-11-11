#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

#define frep(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, n) frep(i, 0, (n))
#define rrep(i, n) for(int i = (n - 1); i >= 0; i--)
#define all(i, x) for(typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define pb push_back

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int MAX = 100010;
const int INF = 1e9;
const int MOD = 1000000007;
const ll M = 998244353;
const string END = "\n";

ll dp[301][90001];
ll dp2[301][90001];

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n; cin >> n;
	ll a[301] = {};
	int sum = 0;
	ll ans = 1;
	rep(i, n) {
		cin >> a[i];
		sum += a[i];
		ans = (ans * 3) % M;
	}
	int s = (sum+1) / 2;
	dp[0][0] = 1;
	dp2[0][0] = 1;
	rep(i, n){
		rep(j, 90001){
			(dp[i+1][j] += 2 * dp[i][j]) %= M;
			(dp2[i+1][j] += dp2[i][j]) %= M;
			if(j >= a[i]) {
				(dp[i+1][j] += dp[i][j-a[i]]) %= M;
				(dp2[i+1][j] += dp2[i][j-a[i]]) %= M;
			}
		}
	}
	if(sum % 2 == 0){
		(ans += 3 * dp2[n][sum/2]) %= M;
	}
	frep(i, s, sum+1){
		(ans -= 3 * dp[n][i] - M) %= M;
	}
	cout << (ans + M) % M << END;

	return 0;
}
