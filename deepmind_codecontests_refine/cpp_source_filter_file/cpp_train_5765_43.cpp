#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
const int M = 1e3 + 5;
const int mod = 19260817;
int n, m, x, y;
double a[M][M], ans[M];
inline int read() {
  int f = 1, s = 0;
  char ch = getchar();
  while (!isdigit(ch)) (ch == '-') && (f = -1), ch = getchar();
  while (isdigit(ch)) s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
  return f * s;
}
int main() {
  n = read(), m = read(), x = read(), y = read();
  if (m == 1) {
    printf("%.4lf", (n - x) * 2);
    return 0;
  }
  for (int i = n - 1; i >= x; --i) {
    for (int j = 1; j <= m; ++j) {
      if (j == 1)
        a[1][1] = 2.0 / 3, a[1][2] = -1.0 / 3,
        a[1][m + 1] = 1.0 / 3 * ans[j] + 1;
      else if (j == m)
        a[m][m - 1] = -1.0 / 3, a[m][m] = 2.0 / 3,
                 a[m][m + 1] = 1.0 / 3 * ans[j] + 1;
      else {
        a[j][j - 1] = -1.0 / 4, a[j][j] = 3.0 / 4, a[j][j + 1] = -1.0 / 4,
                 a[j][m + 1] = 1.0 / 4 * ans[j] + 1;
      }
    }
    for (int j = 1; j <= m; ++j) {
      double tmp = a[j + 1][j] * 1.0 / a[j][j];
      a[j + 1][j] = 0, a[j + 1][j + 1] -= tmp * a[j][j + 1];
      a[j + 1][m + 1] -= tmp * a[j][m + 1];
    }
    for (int j = m; j >= 1; --j) {
      double tmp = a[j - 1][j] * 1.0 / a[j][j];
      a[j - 1][j] = 0;
      a[j - 1][m + 1] -= tmp * a[j][m + 1];
      ans[j] = a[j][m + 1] * 1.0 / a[j][j];
    }
  }
  printf("%.4lf", ans[y]);
  return 0;
}
