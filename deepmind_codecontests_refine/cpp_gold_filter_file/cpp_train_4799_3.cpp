#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int arr[n + 1], dp[n + 1][n][2];
  for (int i = 1; i <= n; i++) cin >> arr[i];
  if (n == 1) {
    cout << 0 << "\n";
    return 0;
  }
  memset(dp, 63, sizeof dp);
  dp[1][1][1] = dp[2][0][0] = dp[1][0][0] = 0;
  dp[2][1][0] = max(0, arr[2] - arr[1] + 1);
  dp[2][1][1] = max(0, arr[1] - arr[2] + 1);
  for (int i = 3; i <= n; i++) {
    dp[i][0][0] = 0;
    for (int j = 1; j <= (i + 1) / 2; j++) {
      dp[i][j][0] = min(dp[i - 1][j][1] + max(0, arr[i] - arr[i - 1] + 1),
                        dp[i - 1][j][0]);
      dp[i][j][1] = dp[i - 2][j - 1][0] + max(0, arr[i - 1] - arr[i] + 1);
      dp[i][j][1] = min(dp[i][j][1],
                        dp[i - 2][j - 1][1] +
                            max(0, arr[i - 1] - min(arr[i - 2], arr[i]) + 1));
    }
  }
  for (int i = (n + 1) / 2; i >= 1; i--) {
    dp[n][i][0] = min({dp[n][i][0], dp[n][i][1], dp[n][i + 1][0]});
  }
  for (int i = 1; i <= (n + 1) / 2; i++) cout << dp[n][i][0] << " ";
}
