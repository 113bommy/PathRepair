#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll MOD = 1e9 + 7, N = 3e3 + 10;
string s, t;
ll dp[N][N];
ll n, m;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s >> t;
  n = s.length();
  m = t.length();
  s = '*' + s;
  t = '*' + t;
  for (ll i = m; i <= n; i++) {
    if (i > m or s[i] == t[m]) {
      dp[i][0] = 1;
    }
    if (s[i] == t[1]) {
      dp[i][1] = 1;
    }
  }
  for (ll i = n; i > 1; i--) {
    for (ll j = 0; j <= n - i + 1; j++) {
      if (j + 1 > m or s[i - 1] == t[j + 1]) {
        dp[i - 1][j + 1] += dp[i][j];
        dp[i - 1][j + 1] %= MOD;
      }
      ll one = j + i - 1;
      if (one > m or s[i - 1] == t[one]) {
        dp[i - 1][j] += dp[i][j];
        dp[i - 1][j] %= MOD;
      }
    }
  }
  ll ans = 0;
  for (ll j = 0; j <= n; j++) {
    ans += dp[1][j];
    ans %= MOD;
  }
  cout << ans << '\n';
  return 0;
}
