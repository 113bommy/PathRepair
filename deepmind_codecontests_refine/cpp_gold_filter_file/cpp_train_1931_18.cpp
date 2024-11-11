#include <bits/stdc++.h>
using namespace std;
const int N = 1057;
int a[N], b[N], n, m, kk;
char ch;
int dp[N][N][12][2];
int ans;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> kk;
  for (int i = 1; i <= n; ++i) cin >> ch, a[i] = ch - 'a';
  for (int i = 1; i <= m; ++i) cin >> ch, b[i] = ch - 'a';
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      for (int k = 0; k <= kk; ++k) {
        dp[i][j][k][0] = max(dp[i][j][k][0], dp[i][j][k][1]);
        if (a[i] == b[j]) {
          if (dp[i][j][k][1] != 0)
            dp[i + 1][j + 1][k][1] =
                max(dp[i + 1][j + 1][k][1], dp[i][j][k][1] + 1);
          dp[i + 1][j + 1][k + 1][1] =
              max(dp[i + 1][j + 1][k][1], dp[i][j][k][0] + 1);
        }
        dp[i + 1][j][k][0] = max(dp[i + 1][j][k][0], dp[i][j][k][0]);
        dp[i][j + 1][k][0] = max(dp[i][j + 1][k][0], dp[i][j][k][0]);
      }
  for (int i = 1; i <= n + 1; ++i)
    for (int j = 1; j <= m + 1; ++j)
      for (int z = 0; z <= 1; ++z) {
        ans = max(ans, dp[i][j][kk][z]);
        if (ans == 2) {
        }
      }
  cout << ans;
}
