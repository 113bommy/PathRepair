#include <bits/stdc++.h>
using namespace std;
double dp[222][256][2][255], p, q;
int X, K;
int main() {
  while (~scanf("%d%d%lf", &X, &K, &p)) {
    p /= 100.0;
    q = 1.0 - p;
    int a[33], res = 0, n = X % 256;
    while (X) a[res] = X % 2, X /= 2;
    memset(dp, 0, sizeof(dp));
    if (res < 9)
      dp[0][n][0][0] = 1;
    else {
      int cnt = 1;
      for (int i = 9; i < res; i++)
        if (a[i] == a[i - 1])
          cnt++;
        else
          break;
      dp[0][n][a[8]][cnt] = 1;
    }
    for (int i = 0; i < K; i++)
      for (int j = 0; j <= 255; j++)
        for (int k = 0; k <= 240; k++) {
          if (j & 128) {
            dp[i + 1][(j << 1) % 256][1][1] += dp[i][j][0][k] * p;
            dp[i + 1][(j << 1) % 256][1][k + 1] += dp[i][j][1][k] * p;
          } else {
            dp[i + 1][(j << 1) % 256][0][k + 1] += dp[i][j][0][k] * p;
            dp[i + 1][(j << 1) % 256][0][1] += dp[i][j][1][k] * p;
          }
          if (j == 255) {
            dp[i + 1][0][1][1] += dp[i][j][0][k] * q;
            dp[i + 1][0][0][k] += dp[i][j][1][k] * q;
          } else {
            dp[i + 1][j + 1][0][k] += dp[i][j][0][k] * q;
            dp[i + 1][j + 1][1][k] += dp[i][j][1][k] * q;
          }
        }
    double ans = 0;
    for (int k = 0; k <= 240; k++)
      ans += dp[K][0][0][k] * (8 + k) + dp[K][0][1][k] * 8;
    for (int i = 1; i <= 255; i++) {
      int temp = i, cnt = 0;
      while (temp % 2 == 0) cnt++, temp /= 2;
      for (int j = 0; j < 2; j++)
        for (int k = 0; k <= 240; k++) ans += dp[K][i][j][k] * cnt;
    }
    printf("%.10f\n", ans);
  }
  return 0;
}
