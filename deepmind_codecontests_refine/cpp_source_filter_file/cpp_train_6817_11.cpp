#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int r, s, p;
long double dp[102][102][102][3];
int main() {
  scanf("%d %d %d", &r, &s, &p);
  for (int i = 1; i <= 100; i++)
    dp[i][0][0][0] = dp[0][i][0][1] = dp[0][0][i][2] = 1;
  for (int i = 0; i <= r; i++)
    for (int j = 0; j <= s; j++)
      for (int k = 0; k <= p; k++) {
        int x = i * j + j * k + k * i;
        if (x != 0)
          for (int t = 0; t < 3; t++) {
            if (j) {
              dp[i][j][k][t] += dp[i][j - 1][k][t] * i * j / x;
            }
            if (k) {
              dp[i][j][k][t] += dp[i][j][k - 1][t] * j * k / x;
            }
            if (i) {
              dp[i][j][k][t] += dp[i - 1][j][k][t] * i * k / x;
            }
          }
      }
  for (int t = 0; t < 3; t++) printf("%.12f\n", dp[r][s][p][t]);
}
