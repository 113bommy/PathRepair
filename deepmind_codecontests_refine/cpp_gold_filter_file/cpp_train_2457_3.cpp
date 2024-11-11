#include <bits/stdc++.h>
const int maxn = 5000 + 10;
int a[maxn], dp[maxn][maxn], maxm[100000 + 10], maxmod[10];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 0; i <= n; i++) {
    memset(maxm, 0, sizeof(maxm));
    memset(maxmod, 0, sizeof(maxmod));
    for (int j = 1; j <= i; j++) {
      maxm[a[j]] = std::max(maxm[a[j]], dp[i][j]);
      maxmod[a[j] % 7] = std::max(maxmod[a[j] % 7], dp[i][j]);
    }
    for (int j = i + 1; j <= n; j++) {
      dp[i][j] = std::max(dp[i][j], dp[i][0] + 1);
      dp[i][j] = std::max(dp[i][j], maxmod[a[j] % 7] + 1);
      dp[i][j] = std::max(dp[i][j], maxm[a[j] - 1] + 1);
      dp[i][j] = std::max(dp[i][j], maxm[a[j] + 1] + 1);
      maxm[a[j]] = std::max(maxm[a[j] + 1], dp[i][j]);
      maxmod[a[j] % 7] = std::max(maxmod[a[j] % 7], dp[i][j]);
      dp[j][i] = dp[i][j];
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ans = std::max(ans, dp[i][j]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
