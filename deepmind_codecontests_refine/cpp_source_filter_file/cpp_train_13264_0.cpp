#include <bits/stdc++.h>
using namespace std;
const long long N = 8;
long long dp[N][N][N][N];
void solve() {
  long long n, m, q;
  cin >> n >> m >> q;
  long long pre[n + 2][m + 2];
  memset(pre, 0, sizeof pre);
  for (long long i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    for (long long j = 1; j <= m; ++j) {
      if (s[j - 1] == '0') pre[i][j] = pre[i - 1][j] + 1;
    }
  }
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 1; j <= m; ++j) {
      for (long long k = i; k <= n; ++k) {
        for (long long l = j; l <= m; ++l) {
          if (i != k) dp[i][j][k][l] += dp[i][j][k - 1][l];
          if (j != l) dp[i][j][k][l] += dp[i][j][k][l - 1];
          if (i != k && l != j) dp[i][j][k][l] -= dp[i][j][k - 1][l - 1];
          long long mx = k - i + 1;
          for (long long x = l; x >= j; --x) {
            mx = min(mx, pre[k][x]);
            dp[i][j][k][l] += mx;
            if (mx == 0) break;
          }
        }
      }
    }
  };
  while (q--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << dp[a][b][c][d] << '\n';
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t = 1;
  while (t--) solve();
}
