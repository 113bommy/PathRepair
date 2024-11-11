#include <bits/stdc++.h>
int count(int x) {
  if (x == 0) return 0;
  int ret = 0;
  for (; x % 2 == 0; x /= 2) ++ret;
  return ret;
}
int get(int x) {
  int ret = count(x);
  if (ret > 0)
    return 50 + ret;
  else
    return 51 - count(x + 1);
}
double dp[201][300][256];
int add(int x) {
  if (x > 50)
    return 50;
  else {
    x = 51 - x;
    return x + 50;
  }
}
int mul(int x, int y) {
  y /= 128;
  if (y == 0) {
    if (x <= 50)
      return 51;
    else
      return x + 1;
  } else {
    if (x <= 50)
      return x - 1;
    else
      return 50;
  }
}
int main() {
  int x, k, p;
  scanf("%d%d%d", &x, &k, &p);
  if (x < 256) x += 1 << 20;
  dp[0][get(x / 256)][x % 256] = 1;
  for (int i = 0; i < k; ++i)
    for (int j = 0; j < 300; ++j) {
      for (int l = 0; l < 256; ++l)
        if (dp[i][j][l] > 0) {
          if (l >= 128)
            dp[i + 1][mul(j, l)][l * 2 - 256] += p / 100.0 * dp[i][j][l];
          else
            dp[i + 1][mul(j, l)][l * 2] += p / 100.0 * dp[i][j][l];
          if (l == 255)
            dp[i + 1][add(j)][0] += (100 - p) / 100.0 * dp[i][j][l];
          else
            dp[i + 1][j][l + 1] += (100 - p) / 100.0 * dp[i][j][l];
        }
    }
  double ans = 0;
  for (int j = 0; j <= 50; ++j) ans += dp[k][j][0] * 8;
  for (int j = 51; j < 300; ++j) ans += dp[k][j][0] * (8 + j - 50);
  for (int i = 1; i < 256; ++i) {
    int cnt = count(i);
    for (int j = 0; j < 300; ++j) ans += dp[k][j][i] * cnt;
  }
  printf("%.12f\n", ans);
  return 0;
}
