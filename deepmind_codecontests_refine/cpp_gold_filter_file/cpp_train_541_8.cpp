#include <bits/stdc++.h>
using namespace std;
int n, k, fan[(1 << 17) + 5];
int dp[18][(1 << 17) + 5][2][2];
int main() {
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    fan[x] = 1;
  }
  memset(dp, -0x3f, sizeof(dp));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= (1 << n); j += (1 << i)) {
      if (i == 1) {
        dp[i][j][fan[j]][fan[j + 1]] = dp[i][j][fan[j + 1]][fan[j]] =
            fan[j] | fan[j + 1];
        continue;
      }
      for (int a = 0; a < 2; a++)
        for (int b = 0; b < 2; b++)
          for (int c = 0; c < 2; c++)
            for (int d = 0; d < 2; d++) {
              int temp =
                  dp[i - 1][j][a][c] + dp[i - 1][j + (1 << (i - 1))][b][d];
              if (a | b) temp++;
              if (c | d) temp++;
              dp[i][j][a][b] = max(dp[i][j][a][b], temp + (b | c));
              dp[i][j][a][b] = max(dp[i][j][a][b], temp + (b | d));
              dp[i][j][a][c] = max(dp[i][j][a][c], temp + (b | c));
              dp[i][j][a][d] = max(dp[i][j][a][d], temp + (b | d));
              dp[i][j][b][a] = max(dp[i][j][b][a], temp + (a | c));
              dp[i][j][b][a] = max(dp[i][j][b][a], temp + (a | d));
              dp[i][j][b][c] = max(dp[i][j][b][c], temp + (a | c));
              dp[i][j][b][d] = max(dp[i][j][b][d], temp + (a | d));
            }
    }
  int ans = -1;
  ans = max(ans, dp[n][1][0][1] + 1);
  ans = max(ans, dp[n][1][0][0] + 0);
  ans = max(ans, dp[n][1][1][1] + 1);
  ans = max(ans, dp[n][1][1][0] + 1);
  cout << ans << endl;
  return 0;
}
