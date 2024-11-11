#include <bits/stdc++.h>
using namespace std;
int n, m, a[1002];
double dp[1002][1002], ans;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (i != j) dp[i][j] = a[i] > a[j];
  int x, y;
  while (m--) {
    scanf("%d%d", &x, &y);
    for (int i = 1; i <= n; ++i)
      if (i != x && i != y) {
        double num = (dp[i][x] + dp[i][y]) / 2;
        dp[i][x] = dp[i][y] = num;
        dp[x][i] = dp[y][i] = 1 - num;
      }
    dp[x][y] = dp[y][x] = 0.5;
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j < i; ++j) ans += dp[i][j];
  printf("%.10lf", ans);
  return 0;
}
