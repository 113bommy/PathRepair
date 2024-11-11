#include <bits/stdc++.h>
using namespace std;
double P[20][20];
double dp[20][270000];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) scanf("%lf", &P[i][j]);
  }
  dp[0][1] = 1;
  for (int i = 1; i < n; i++) dp[i][1 << i] = 0;
  for (int u = 2; u < (1 << n); u++) {
    for (int i = 0; i < n; i++) {
      if (u & (1 << i)) {
        for (int j = 0; j < n; j++) {
          if (i == j) continue;
          if (u & (1 << j)) {
            dp[i][u] = max(dp[i][u], P[i][j] * dp[i][u ^ (1 << j)] +
                                         P[j][i] * dp[j][u ^ (1 << i)]);
          }
        }
      }
    }
  }
  double ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, dp[i][(1 << n) - 1]);
  }
  printf("%.16f\n", ans);
  return 0;
}
