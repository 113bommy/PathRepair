#include <bits/stdc++.h>
using namespace std;
const int N = 256;
const int inf = 1000000007;
int x, k, p, zero[N];
double dp[205][N][N][2];
int main() {
  cin >> x >> k >> p;
  if (x < 256) {
    dp[0][x][0][0] = 1.0;
  } else {
    int xx = x / 256;
    if (x & 1) {
      int p = 0;
      while ((1 << p) & xx) p++;
      dp[0][x % 256][p][1] = 1.0;
    } else {
      int p = 0;
      while (!((1 << p) & xx)) p++;
      dp[0][x % 256][p][0] = 1.0;
    }
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < 256; j++) {
      for (int r = 0; r < 256; r++) {
        if (j * 2 >= 256) {
          dp[i + 1][(j * 2) % 256][1][1] += dp[i][j][r][0] * p / 100.0;
          dp[i + 1][(j * 2) % 256][r + 1][1] += dp[i][j][r][1] * p / 100.0;
        } else {
          dp[i + 1][(j * 2) % 256][r + 1][0] += dp[i][j][r][0] * p / 100.0;
          dp[i + 1][(j * 2) % 256][1][0] += dp[i][j][r][1] * p / 100.0;
        }
        if (j + 1 >= 256) {
          dp[i + 1][(j + 1) % 256][1][1] += dp[i][j][r][0] * (100 - p) / 100.0;
          dp[i + 1][(j + 1) % 256][r][0] += dp[i][j][r][1] * (100 - p) / 100.0;
        } else {
          dp[i + 1][(j + 1) % 256][r][0] += dp[i][j][r][0] * (100 - p) / 100.0;
          dp[i + 1][(j + 1) % 256][r][1] += dp[i][j][r][1] * (100 - p) / 100.0;
        }
      }
    }
  }
  double ans = 0.0;
  for (int i = 0; i < 256; i++) {
    for (int j = 0; j < 256; j++) {
      if (i == 0) {
        ans += dp[k][i][j][0] * (8 + j);
        ans += dp[k][i][j][1] * 8;
      } else {
        int p = 0;
        while (!(i & (1 << p))) p++;
        ans += dp[k][i][j][0] * p;
        ans += dp[k][i][j][1] * p;
      }
    }
  }
  printf("%.10f\n", ans);
  return 0;
}
