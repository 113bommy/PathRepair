#include <bits/stdc++.h>
using namespace std;
int dp[105][20005], a[105], b[105];
const int c = 10000;
int main() {
  int n, k, i, j;
  cin >> n >> k;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) cin >> b[i];
  for (i = 1; i <= n; i++) {
    for (j = -10000; j <= 10000; j++) {
      dp[i][j + c] = dp[i - 1][j + c];
    }
    dp[i][a[i] - k * b[i] + c] = max(dp[i][a[i] - k * b[i] + c], a[i]);
    for (j = -10000; j <= 10000; j++) {
      if (dp[i - 1][j + c] != 0) {
        dp[i][j + c + a[i] - k * b[i]] =
            max(dp[i - 1][j + c + a[i] - k * b[i]], dp[i - 1][j + c] + a[i]);
      }
    }
  }
  if (dp[n][c])
    cout << dp[n][c];
  else
    cout << -1;
}
