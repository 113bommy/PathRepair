#include <bits/stdc++.h>
using namespace std;
const int N = 250;
const double eps = 1e-20;
double dp[N][N][2][1 << 8];
int x, k, p;
int getct(int x1) {
  int cnt = 0;
  while (x1 && x1 % 2 == 0) {
    x1 /= 2;
    cnt++;
  }
  return cnt;
}
double getans() {
  double ans = 0;
  int ed = 1 << 8;
  for (int j = 0; j <= k + 32; j++) {
    for (int i1 = 0; i1 < 2; i1++) {
      for (int j1 = 0; j1 < ed; j1++)
        if (dp[k][j][i1][j1] > eps) {
          if (j1 == 0) {
            if (i1 == 0) {
              ans += (8 + j) * dp[k][j][i1][j1];
            } else {
              ans += 8 * dp[k][j][i1][j1];
            }
          } else {
            ans += getct(j1) * dp[k][j][i1][j1];
          }
        }
    }
  }
  return ans;
}
void up(int i, int j, int i1, int j1) {
  double pi = (double)p / 100;
  int i2 = j1 >> 7 & 1;
  double tmp = dp[i][j][i1][j1];
  if (i2 == i1) {
    if (j)
      dp[i + 1][j + 1][i2][j1 << 1 & 255] += tmp * pi;
    else
      dp[i + 1][j][i2][j1 << 1 & 255] += tmp * pi;
  } else {
    dp[i + 1][1][i2][j1 << 1 & 255] += tmp * pi;
  }
  if (j1 != 255) {
    dp[i + 1][j][i1][j1 + 1] += tmp * (1 - pi);
  } else {
    if (i1 == 0)
      dp[i + 1][1][1][0] += tmp * (1 - pi);
    else
      dp[i + 1][j][0][0] += tmp * (1 - pi);
  }
}
void getdp() {
  memset(dp, 0, sizeof(dp));
  int x1 = x >> 8, y1 = x >> 8 & 1;
  if (y1 == 1) x1++;
  dp[0][getct(x1)][y1][x & 255] = 1;
  int ed = 1 << 8;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j <= k + 32; j++) {
      for (int i1 = 0; i1 < 2; i1++) {
        for (int j1 = 0; j1 < ed; j1++)
          if (dp[i][j][i1][j1] > eps) {
            up(i, j, i1, j1);
          }
      }
    }
  }
}
int main() {
  while (scanf("%d%d%d", &x, &k, &p) != EOF) {
    getdp();
    printf("%.10lf\n", getans());
  }
  return 0;
}
