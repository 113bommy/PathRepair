#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const int N = 5055;
int n, m, x, y;
double Div, ans[N], f[N][N];
int main() {
  scanf("%d%d%d%d", &m, &n, &y, &x);
  if (n == 1) {
    ans[m] = 0.0;
    for (int i = m - 1; i >= y; i--) ans[i] = ans[i + 1] + 2.0;
    printf("%.10lf", ans[x]);
    return 0;
  }
  for (int p = m - 1; p >= y; p--) {
    f[1][n + 1] = 3.0 / 2.0 + ans[1] / 2.0;
    f[n][n + 1] = 3.0 / 2.0 + ans[n] / 2.0;
    for (int i = 2; i < n; i++) f[i][n + 1] = 4.0 / 3.0 + ans[i] / 3.0;
    for (int i = 1; i <= n; i++) f[i][i] = 1.0;
    f[1][2] = f[n][n - 1] = -1.0 / 2.0;
    for (int i = 2; i < n; i++) f[i][i - 1] = f[i][i + 1] = -1.0 / 3.0;
    for (int i = 1; i <= n; i++) {
      Div = f[i][i];
      if (i == 1) {
        f[1][1] /= Div;
        f[1][2] /= Div;
        f[1][n + 1] /= Div;
        Div = f[2][1];
        f[2][1] -= f[1][1] * Div;
        f[2][2] -= f[1][2] * Div;
        f[2][n + 1] -= f[1][n + 1] * Div;
        continue;
      } else if (i == n) {
        f[n][n] /= Div;
        f[n][n + 1] /= Div;
        continue;
      } else {
        f[i][i] /= Div;
        f[i][i + 1] /= Div;
        f[i][n + 1] /= Div;
        Div = f[i + 1][i];
        f[i + 1][i] -= f[i][i] * Div;
        f[i + 1][i + 1] -= f[i][i + 1] * Div;
        f[i + 1][n + 1] -= f[i][n + 1] * Div;
        continue;
      }
    }
    ans[n] = f[n][n + 1];
    for (int i = n - 1; i > 0; i--) {
      ans[i] = f[i][n + 1];
      ans[i] -= ans[i + 1] * f[i][i + 1];
    }
  }
  printf("%.10lf", ans[x]);
  return 0;
}
