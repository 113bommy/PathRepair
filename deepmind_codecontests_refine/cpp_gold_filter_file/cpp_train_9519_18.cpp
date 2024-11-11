#include <bits/stdc++.h>
using namespace std;
int dp[100 * 100 + 5];
int main() {
  int c, d, n, m, k;
  cin >> c >> d >> n >> m >> k;
  memset(dp, -0xff, sizeof(dp));
  dp[0] = 0;
  for (int j = 1; j <= n * m; j++) {
    if (j - n >= 0)
      dp[j] = min(dp[j], min(dp[j - n] + c, dp[j - 1] + d));
    else
      dp[j] = min(dp[j], dp[j - 1] + d);
  }
  int ans = 9999999;
  for (int i = n * m - k; i <= n * m; i++) ans = min(dp[i], ans);
  cout << ans;
}
