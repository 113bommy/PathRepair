#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
double a[maxn][maxn];
double dp[1 << 20][maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) scanf("%lf", &a[i][j]);
  dp[1][0] = 1;
  for (int stat = 3; stat < (1 << n); stat += 2) {
    for (int i = 0; i < n; ++i)
      if (stat & (1 << i)) {
        for (int j = 0; j < n; ++j)
          if (j != i && (stat & (1 << j))) {
            dp[stat][i] =
                max(dp[stat][i], a[i][j] * dp[stat ^ (1 << j)][i] +
                                     a[j][i] * dp[stat ^ (1 << i)][j]);
          }
      }
  }
  double ans = 0;
  for (int i = 0; i < n; ++i) ans = max(ans, dp[(1 << n) - 1][i]);
  printf("%.10lf", ans);
  return 0;
}
