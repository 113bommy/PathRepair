#include <bits/stdc++.h>
using namespace std;
int x, K, p;
double dp[205][2][250][256], P;
int vl[256];
int main() {
  scanf("%d%d%d", &x, &K, &p);
  double P = p * 1.0 / 100;
  int pre = x >> 8, suf = x & 255, v = pre & 1, cnt = 0;
  if (pre == 0)
    cnt = 1;
  else
    while ((pre & 1) == v) cnt++, pre >>= 1;
  dp[0][v][cnt][suf] = 1;
  vl[0] = 8;
  for (int i = 1; i < 256; i++) {
    int tmp = i;
    while (!(tmp & 1)) tmp >>= 1, vl[i]++;
  }
  for (int i = 1; i <= K; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < i + 32; k++) {
        for (int l = 0; l < 255; l++) {
          dp[i][(l >> 7) & 1][((l >> 7) & 1) == j ? k + 1 : 1]
            [(l << 1) & 255] += dp[i - 1][j][k][l] * P;
          dp[i][j][k][l + 1] += dp[i - 1][j][k][l] * (1 - P);
        }
        dp[i][(255 >> 7) & 1][((255 >> 7) & 1) == j ? k + 1 : 1]
          [(255 << 1) & 255] += dp[i - 1][j][k][255] * P;
        if (j == 0)
          dp[i][1][1][0] += dp[i - 1][j][k][255] * (1 - P);
        else
          dp[i][0][k][0] += dp[i - 1][j][k][255] * (1 - P);
      }
    }
  }
  double ans = 0;
  for (int i = 1; i <= K + 32; i++) {
    for (int j = 1; j < 256; j++)
      ans += (dp[K][0][i][j] + dp[K][1][i][j]) * vl[j];
    ans += dp[K][0][i][0] * (8 + i);
    ans += dp[K][1][i][0] * 8;
  }
  printf("%.10lf\n", ans);
  return 0;
}
