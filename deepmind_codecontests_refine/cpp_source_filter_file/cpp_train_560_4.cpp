#include <bits/stdc++.h>
long long dp[2005][2005];
int a[25], b[25];
int main() {
  memset(dp, -1, sizeof(dp));
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < n; i++) scanf("%d", b + i);
  int l = n * 2;
  dp[0][0] = 0;
  for (int i = 1; i <= l; i++) {
    for (int j = 0; j <= l; j++) {
      if (dp[i - 1][j] == -1) continue;
      if (dp[i][j + 1] == -1 || dp[i][j + 1] > dp[i - 1][j] + a[(i - 1) % n])
        dp[i][j + 1] = dp[i - 1][j] + a[(i - 1) % n];
      if (j > 0 &&
          (dp[i][j - 1] == -1 || dp[i][j - 1] > dp[i - 1][j] + b[(i - 1) % n]))
        dp[i][j - 1] = dp[i - 1][j] + b[(i - 1) % n];
    }
  }
  if (n * m <= l)
    printf("%d\n", dp[n * m][0]);
  else {
    printf("%d\n", dp[l][0] + (dp[l][0] - dp[l - 2 * n][0]) * (m - 2) / 2);
  }
}
