#include <bits/stdc++.h>
using namespace std;
int t[4003], d[4003];
int dp[4003][4003];
int main() {
  int n, k, ans = 0, i, j;
  cin >> n >> k;
  for (i = 1; i <= n; i++) scanf("%d%d", t + i, d + i);
  for (j = 0; j <= k; j++) dp[0][k] = 1;
  for (i = 1; i <= n; i++)
    for (j = 0; j <= k; j++) {
      dp[i][j] = max(dp[i - 1][j], t[i]) + d[i];
      if (j) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
    }
  for (i = 1; i <= n; i++) ans = max(ans, t[i] - dp[i - 1][k]);
  ans = max(ans, 86400 - dp[n][k]);
  cout << ans;
}
