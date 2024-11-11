#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
long long dp[101][101][101], p[101][101], a[101], ans;
int n, m, k;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> p[i][j];
  for (int i = 1; i < 101; i++)
    for (int j = 0; j < 101; j++)
      for (int l = 0; l < 101; l++) dp[i][j][l] = INF;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= min(i, k); j++) {
      for (int c = 1; c <= m; c++) {
        if (a[i] == 0) {
          for (int col = 1; col <= m; col++)
            dp[i][j][c] =
                (c != col) ? min(dp[i - 1][j - 1][col] + p[i][c], dp[i][j][c])
                           : min(dp[i - 1][j][c] + p[i][c], dp[i][j][c]);
        } else {
          if (c == a[i])
            for (int col = 1; col <= m; col++)
              dp[i][j][c] = (c != col) ? min(dp[i - 1][j - 1][col], dp[i][j][c])
                                       : min(dp[i - 1][j][c], dp[i][j][c]);
          if (c != a[i]) dp[i][j][c] = INF;
        }
      }
    }
  }
  ans = INF;
  for (int i = 1; i <= m; i++) ans = min(ans, dp[n][k][i]);
  if (ans == INF)
    cout << -1;
  else
    cout << ans;
  return -0;
}
