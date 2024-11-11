#include <bits/stdc++.h>
using namespace std;
int dp[21][21][4], ans, n, t;
int main() {
  cin >> n >> t;
  for (int i = 1; i <= 4; i++)
    for (int j = i + 1; j <= 4; j++) dp[2][1][j]++;
  for (int i = 3; i <= n; i++)
    for (int j = 1; j <= t * 2; j++)
      for (int k = 1; k <= 4; k++) {
        if (j & 1)
          for (int l = 1; l < k; l++)
            dp[i][j][k] += dp[i - 1][j][l] + dp[i - 1][j - 1][l];
        else
          for (int l = k + 1; l <= 4; l++)
            dp[i][j][k] += dp[i - 1][j][l] + dp[i - 1][j - 1][l];
      }
  for (int i = 1; i <= 4; i++) ans += dp[n][t * 2][i];
  cout << ans;
  return 0;
}
