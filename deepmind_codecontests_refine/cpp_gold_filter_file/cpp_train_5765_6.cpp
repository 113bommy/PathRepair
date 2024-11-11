#include <bits/stdc++.h>
using namespace std;
double dp[1005][1005], f[1005];
int main() {
  int n, m, x, y;
  scanf("%d%d%d%d", &n, &m, &x, &y);
  for (int i = 1; i <= m; i++) {
    f[i] = 2;
    if (i > 1) f[i]++;
    if (i < m) f[i]++;
  }
  for (int i = n - 1; i >= x; i--)
    for (int t = 1; t <= 100; t++)
      for (int j = 1; j <= m; j++)
        dp[i][j] =
            (dp[i][j - 1] + dp[i + 1][j] + dp[i][j + 1] + dp[i][j]) / f[j] +
            1.0;
  printf("%.10lf\n", dp[x][y]);
  return 0;
}
