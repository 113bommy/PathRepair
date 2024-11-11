#include <bits/stdc++.h>
using namespace std;
double dp[1005][1005], f[1005], a[1005][1006], b[1005];
int main() {
  int n, m, x, y;
  scanf("%d%d%d%d", &n, &m, &x, &y);
  if (m == 1) {
    for (int i = n - 1; i >= x; i--) f[i] = f[i + 1] + 2;
  } else {
    for (int i = n - 1; i >= x; i--) {
      a[1][1] = -2.0 / 3.0, a[1][2] = 1.0 / 3.0;
      b[1] = -1.0 - f[1] / 3.0;
      a[m][m - 1] = 1.0 / 3.0, a[m][m] = -2.0 / 3.0;
      b[m] = -1.0 - f[m] / 3.0;
      for (int j = 2; j < m; j++) {
        a[j][j - 1] = 1.0 / 4.0, a[j][j] = -3.0 / 4.0, a[j][j + 1] = 1.0 / 4.0;
        b[j] = -1.0 - f[j] / 4.0;
      }
      for (int j = 1; j <= m - 1; j++) {
        double rate = a[j + 1][j] / a[j][j];
        a[j + 1][j] -= rate * a[j][j];
        a[j + 1][j + 1] -= rate * a[j][j + 1];
        b[j + 1] -= rate * b[j];
      }
      f[m] = b[m] / a[m][m];
      for (int j = m - 1; j >= 1; j--)
        f[j] = (b[j] - f[j + 1] * a[j][j + 1]) / a[j][j];
    }
  }
  printf("%.10f\n", f[y]);
  return 0;
}
