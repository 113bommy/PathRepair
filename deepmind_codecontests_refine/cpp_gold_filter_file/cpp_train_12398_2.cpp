#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int k = n / 2 + n % 2;
  int a[n + 1];
  int dp[n + 1][n + 1][2];
  a[0] = 100002;
  memset(dp, 63, sizeof(dp));
  dp[0][0][0] = dp[0][0][1] = dp[1][0][0] = dp[1][1][1] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    dp[i][0][0] = 0;
    for (int j = 1; j <= k; j++) {
      dp[i][j][0] =
          min(dp[i - 1][j][0], dp[i - 1][j][1] + max(a[i] - a[i - 1] + 1, 0));
      dp[i][j][1] =
          min(dp[i - 2][j - 1][1] + max(a[i - 1] - min(a[i - 2], a[i]) + 1, 0),
              dp[i - 2][j - 1][0] + max(0, a[i - 1] - a[i] + 1));
    }
  }
  for (int i = 1; i <= k; i++) {
    cout << min(dp[n][i][0], dp[n][i][1]) << " ";
  }
  return 0;
}
