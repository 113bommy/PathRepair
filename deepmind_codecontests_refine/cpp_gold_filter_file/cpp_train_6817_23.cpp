#include <bits/stdc++.h>
using namespace std;
double dp[105][105][105] = {0}, ans;
int main() {
  int i, j, k, r, s, p;
  cin >> r >> s >> p;
  dp[r][s][p] = 1;
  for (i = r; i >= 0; i--) {
    for (j = s; j >= 0; j--) {
      for (k = p; k >= 0; k--) {
        int wr = k * (i + 1), ws = (j + 1) * i, wp = (k + 1) * j;
        int totr = wr + k * j + j * (i + 1);
        int tots = ws + k * i + k * (j + 1);
        int totp = wp + j * i + i * (k + 1);
        if (totr == 0) totr = 1;
        if (totp == 0) totp = 1;
        if (tots == 0) tots = 1;
        if (i < r) dp[i][j][k] += dp[i + 1][j][k] * wr / totr;
        if (j < s) dp[i][j][k] += dp[i][j + 1][k] * ws / tots;
        if (k < p) dp[i][j][k] += dp[i][j][k + 1] * wp / totp;
      }
    }
  }
  ans = 0;
  for (i = 1; i <= r; i++) ans += dp[i][0][0];
  printf("%.12lf ", ans);
  ans = 0;
  for (j = 1; j <= s; j++) ans += dp[0][j][0];
  printf("%.12lf ", ans);
  ans = 0;
  for (i = 1; i <= p; i++) ans += dp[0][0][i];
  printf("%.12lf\n", ans);
  return 0;
}
