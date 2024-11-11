#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 998244353;
const int MAXN = 5e5 + 5;
const ll INF = 2e18;
void add(ll &a, ll b) {
  a += b;
  a %= MOD;
  if (a < 0) a += MOD;
}
ll dp[MAXN][2];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) dp[i][0] = dp[i][1] = 0;
    vector<int> v(n);
    for (int &x : v) cin >> x;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] == 0) {
        add(ans, dp[1][0] + 1);
        add(ans, dp[1][1]);
        add(dp[1][0], dp[1][0] + 1);
        add(dp[1][1], dp[1][1]);
      } else if (v[i] == 1) {
        add(ans, dp[0][1] + 1);
        add(ans, dp[1][0]);
        add(ans, dp[2][1]);
        add(ans, dp[2][0]);
        add(dp[2][0], dp[2][0]);
        add(dp[2][1], dp[2][1]);
        add(dp[0][1], dp[0][1] + 1);
        add(dp[2][0], dp[1][0]);
      } else {
        add(ans, dp[v[i] - 1][1]);
        add(ans, dp[v[i]][0]);
        add(ans, dp[v[i] - 1][0]);
        add(ans, dp[v[i] + 1][1]);
        add(ans, dp[v[i] + 1][0]);
        add(dp[v[i] + 1][0], dp[v[i] + 1][0]);
        add(dp[v[i] + 1][1], dp[v[i] + 1][1]);
        add(dp[v[i] - 1][1], dp[v[i] - 1][1]);
        add(dp[v[i] - 1][1], dp[v[i] - 1][0]);
        add(dp[v[i] + 1][0], dp[v[i]][0]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
