#include <bits/stdc++.h>
using namespace std;
int dp[30001][802];
int num[30001];
int main() {
  int n, d, x;
  scanf("%d%d", &n, &d);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    num[x]++;
  }
  memset(dp, -1, sizeof(dp));
  dp[d][400] = num[d];
  int ans = 0;
  for (int i = d + 1; i <= 30000; i++) {
    for (int j = 0; j <= 800; j++) {
      int tmp = d + (j - 400);
      if (tmp <= 0) continue;
      if (i < tmp) {
        break;
      }
      if (tmp - 1 > 0 && dp[i - tmp][tmp - 1 - d + 400] >= 0)
        dp[i][j] = max(dp[i][j], dp[i - tmp][tmp - 1 - d + 400]);
      if (dp[i - tmp][tmp - d + 400] >= 0)
        dp[i][j] = max(dp[i][j], dp[i - tmp][tmp - d + 400]);
      if (dp[i - tmp][tmp + 1 - d + 400] >= 0)
        dp[i][j] = max(dp[i][j], dp[i - tmp][tmp + 1 - d + 400]);
      if (dp[i][j] >= 0) dp[i][j] += num[i];
      ans = max(ans, dp[i][j]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
