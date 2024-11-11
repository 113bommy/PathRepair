#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
int n, c[210 * 2], tot, m, b[210], _L[210], _R[210];
;
map<int, int> mp;
double f[2][210][210], ans[210][210];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d%d", &_L[i], &_R[i]), c[++tot] = _L[i], c[++tot] = _R[i];
  sort(c + 1, c + tot + 1);
  c[0] = c[1] - 1;
  m = 0;
  for (int i = 1; i <= tot; i++)
    if (c[i] != c[i - 1]) b[mp[c[i]] = ++m] = c[i];
  for (int i = 1; i <= n; i++) _L[i] = mp[_L[i]], _R[i] = mp[_R[i]];
  for (int i = 1; i <= n; i++) {
    for (int x = _L[i]; x < _R[i]; x++) {
      double cur = (double)(b[x + 1] - b[x]) / (b[_R[i]] - b[_L[i]]);
      for (int x1 = 0; x1 <= n; x1++) {
        for (int x2 = 0; x2 <= n; x2++) {
          f[0][x1][x2] = f[1][x1][x2] = 0;
        }
      }
      int now = 1;
      f[now][0][0] = 1.0;
      for (int j = 1; j <= n; j++) {
        if (i == j) continue;
        int L = b[_L[j]], R = b[_R[j]];
        now = !now;
        if (x < _L[j]) {
          for (int x1 = 0; x1 < j; x1++) {
            for (int x2 = 0; x2 < j - x1; x2++) {
              if (f[!now][x1][x2] > eps) {
                double tmp = f[!now][x1][x2];
                f[!now][x1][x2] = 0;
                f[now][x1][x2] += tmp;
              }
            }
          }
        } else if (_R[j] <= x) {
          for (int x1 = 0; x1 < j; x1++) {
            for (int x2 = 0; x2 < j - x1; x2++) {
              if (f[!now][x1][x2] > eps) {
                double tmp = f[!now][x1][x2];
                f[!now][x1][x2] = 0;
                f[now][x1 + 1][x2] += tmp;
              }
            }
          }
        } else {
          double p1 = (double)(b[x] - L) / (R - L),
                 p2 = (double)(b[x + 1] - b[x]) / (R - L),
                 p3 = (double)(R - b[x + 1]) / (R - L);
          for (int x1 = 0; x1 < j; x1++) {
            for (int x2 = 0; x2 < j - x1; x2++) {
              if (f[!now][x1][x2] > eps) {
                double tmp = f[!now][x1][x2];
                f[!now][x1][x2] = 0;
                f[now][x1 + 1][x2] += tmp * p1;
                f[now][x1][x2 + 1] += tmp * p2;
                f[now][x1][x2] += tmp * p3;
              }
            }
          }
        }
      }
      for (int x1 = 0; x1 < n; x1++) {
        for (int x2 = 0; x2 < n - x1; x2++) {
          if (f[now][x1][x2] > eps) {
            double tmp = f[now][x1][x2], tmp2 = 1.0 / (x2 + 1.0);
            for (int l = 0; l <= x2; l++)
              ans[i][x1 + l + 1] += cur * tmp * tmp2;
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < n; j++) printf("%.10lf", ans[i][j]);
    printf("%.10lf\n", ans[i][n]);
  }
  return 0;
}
