#include <bits/stdc++.h>
double f[2][256][2][220];
int n, st, p;
double prob;
int main() {
  scanf("%d%d%d", &st, &n, &p);
  prob = p / 100.0;
  if (st < 256)
    f[0][st][0][0] = 1.0;
  else {
    int cnt = 1;
    for (int i = 9; ((st >> i) & 1) == ((st >> 8) & 1); i++, cnt++)
      ;
    f[0][st & 255][(st >> 8) & 1][cnt] = 1.0;
  }
  int cur = 0;
  for (int i = 0; i < n; i++) {
    memset(f[cur ^ 1], 0, sizeof(f[cur ^ 1]));
    for (int j = 0; j < 256; j++) {
      for (int k = 0; k <= 210; k++) {
        if ((j >> 7) & 1)
          f[cur ^ 1][(j << 1) & 255][1][k + 1] += f[cur][j][1][k] * prob;
        else
          f[cur ^ 1][(j << 1) & 255][0][1] += f[cur][j][1][k] * prob;
        if (j == 255)
          f[cur ^ 1][0][0][k] += f[cur][j][1][k] * (1.0 - prob);
        else
          f[cur ^ 1][j + 1][1][k] += f[cur][j][1][k] * (1.0 - prob);
        if ((j >> 7) & 1)
          f[cur ^ 1][(j << 1) & 255][1][1] += f[cur][j][0][k] * prob;
        else
          f[cur ^ 1][(j << 1) & 255][0][k + 1] += f[cur][j][0][k] * prob;
        if (j == 255)
          f[cur ^ 1][0][1][1] += f[cur][j][0][k] * (1.0 - prob);
        else
          f[cur ^ 1][j + 1][0][k] += f[cur][j][0][k] * (1.0 - prob);
      }
    }
    cur ^= 1;
  }
  double ans = 0.0;
  for (int i = 0; i < 256; i++) {
    int s = 0;
    while (!((i >> s) & 1) && s < 8) ++s;
    for (int j = 0; j <= 210; j++)
      for (int k = 0; k < 2; k++) {
        int ss;
        if (k == 0 && s == 8)
          ss = s + j;
        else
          ss = s;
        ans += ss * f[cur][i][k][j];
      }
  }
  printf("%.10f\n", ans);
  return 0;
}
