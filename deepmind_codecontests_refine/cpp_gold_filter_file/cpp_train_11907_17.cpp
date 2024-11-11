#include <bits/stdc++.h>
using namespace std;
int n, T, x, y;
double ans;
int a[1005];
double dp[1005][1005];
int main() {
  scanf("%d%d", &n, &T);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (a[j] > a[i])
        dp[j][i] = 1;
      else
        dp[i][j] = 1;
  while (T--) {
    scanf("%d%d", &x, &y);
    for (int i = 1; i <= n; i++)
      if (i != x && i != y) {
        dp[i][x] = dp[i][y] = (dp[i][x] + dp[i][y]) / 2;
        dp[x][i] = dp[y][i] = (dp[x][i] + dp[y][i]) / 2;
      }
    dp[x][y] = dp[y][x] = 0.5;
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) ans += dp[i][j];
  printf("%.10f\n", ans);
  return 0;
}
