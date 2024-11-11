#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e12;
class {
 public:
  long long dp[111][111];
  void solve() {
    long long n, m;
    string s;
    cin >> n >> m >> s;
    s = " " + s;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 111; j++) dp[i][j] = dp[i - 1][j];
      for (int j = 1; j < 111; j++) dp[i][j] += dp[i - 1][j - 1];
      int k;
      for (k = i - 1; k >= 1; k--) {
        if (s[i] == s[k]) break;
      }
      if (k != 0)
        for (int j = 1; j < 111; j++) dp[i][j] -= dp[k][j];
      for (int j = 0; j <= n; j++)
        if (dp[i][j] >= MOD) dp[i][j] = MOD;
    }
    long long cost = 0;
    for (int i = n; i >= 0 && m; i--) {
      cost += 1LL * min(m, dp[n][i]) * (n - i);
      m -= min(m, dp[n][i]);
    }
    if (m) {
      cout << -1 << endl;
    } else {
      cout << cost;
    }
  }
} NSPACE;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  NSPACE.solve();
}
