#include <bits/stdc++.h>
using namespace std;
int n, dp[85][85][6500], a[65], s, m, p[100];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 1) p[++s] = i;
  }
  m = (n - 1) * n / 2;
  memset(dp, 128, sizeof(dp));
  dp[0][0][0] = 0;
  for (int i = 0; i <= n - 1; i++) {
    for (int j = 0; j <= min(s - 1, i); j++) {
      for (int k = 0; k <= m; k++) {
        if (dp[i][j][k] < 0) continue;
        for (int x = i + 1; x <= n; x++)
          dp[x][j + 1][k + abs(p[j + 1] - x)] =
              max(dp[x][j + 1][k + abs(p[j + 1] - x)],
                  dp[i][j][k] + (i - j) * (x - i - 1));
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++)
      ans = max(ans, dp[j][s][i] + (n - j) * (j - s));
    printf("%d ", ans);
  }
  return 0;
}
