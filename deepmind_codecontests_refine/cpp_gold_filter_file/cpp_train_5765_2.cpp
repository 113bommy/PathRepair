#include <bits/stdc++.h>
using namespace std;
double jz[1005][1005], dp[1005][1005];
int main() {
  int n, m, x, y;
  scanf("%d%d%d%d", &n, &m, &x, &y);
  if (m == 1) {
    printf("%.10lf", (n - x) * 2.0);
    return 0;
  }
  for (int i(n - 1), j, k; i; --i) {
    jz[1][0] = -1 - dp[i + 1][1] / 3, jz[1][1] = -2.0 / 3, jz[1][2] = 1.0 / 3;
    jz[m][0] = -1 - dp[i + 1][m] / 3, jz[m][m] = -2.0 / 3,
    jz[m][m - 1] = 1.0 / 3;
    for (j = 2; j < m; ++j)
      jz[j][0] = -1 - dp[i + 1][j] / 4, jz[j][j] = -3.0 / 4,
      jz[j][j - 1] = jz[j][j + 1] = 1.0 / 4;
    for (j = 1; j <= m; ++j) {
      jz[j][j + 1] /= jz[j][j], jz[j][0] /= jz[j][j], jz[j][j] = 1;
      jz[j + 1][j + 1] -= jz[j][j + 1] * jz[j + 1][j],
          jz[j + 1][0] -= jz[j][0] * jz[j + 1][j], jz[j + 1][j] = 0;
    }
    for (j = m; j; --j)
      jz[j - 1][0] -= jz[j][0] * jz[j - 1][j], jz[j - 1][j] = 0;
    for (j = 1; j <= m; ++j) dp[i][j] = jz[j][0];
  }
  printf("%.10lf", dp[x][y]);
  return 0;
}
