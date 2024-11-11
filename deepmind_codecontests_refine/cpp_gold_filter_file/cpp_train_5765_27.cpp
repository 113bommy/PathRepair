#include <bits/stdc++.h>
using namespace std;
int n, m, n1, m1;
double dp[1002][1002], ans, c[1003][1003];
int main() {
  scanf("%d %d", &n, &m);
  scanf("%d%d", &n1, &m1);
  if (n == n1)
    ans = 0.000000;
  else if (m == 1)
    dp[n1][m1] = 2 * (n - n1);
  else {
    for (int i = n - 1; i >= n1; i--) {
      for (int j = 2; j < m; j++) {
        c[j][j] = 0.75, c[j][j - 1] = -0.25;
        c[j][j + 1] = -0.25;
        c[j][1002] = 1.0 + 0.25 * dp[i + 1][j];
      }
      c[1][1] = 2.0 / 3.0;
      c[1][2] = -1.0 / 3.0;
      c[1][1002] = 1.0 + 1.0 / 3 * dp[i + 1][1];
      c[m][m] = 2.0 / 3.0;
      c[m][m - 1] = -1.0 / 3.0;
      c[m][1002] = 1.0 + 1.0 / 3 * dp[i + 1][m];
      c[1][2] /= c[1][1];
      c[1][1002] /= c[1][1];
      c[1][1] = 1;
      for (int j = 2; j <= m; j++) {
        c[j][j] -= c[j][j - 1] * c[j - 1][j];
        c[j][1002] -= c[j][j - 1] * c[j - 1][1002];
        c[j][j + 1] /= c[j][j];
        c[j][1002] /= c[j][j];
        c[j][j] = 1;
      }
      for (int j = m; j >= 1; j--)
        dp[i][j] = (c[j][1002] - dp[i][j + 1] * c[j][j + 1]);
    }
  }
  printf("%.12lf\n", dp[n1][m1]);
  return 0;
}
