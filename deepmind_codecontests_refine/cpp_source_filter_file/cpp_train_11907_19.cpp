#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1111;
int n, m;
double p[MAXN][MAXN];
int a[MAXN];
int main() {
  while (cin >> n >> m) {
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    memset(p, 0, sizeof p);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        if (a[i] > a[j]) p[i][j] = 1;
    for (int c = 0; c < m; ++c) {
      int x, y;
      scanf("%d%d", &x, &y);
      p[x][y] = p[y][x] = 1.0 / 2;
      for (int i = 1; i <= n; ++i)
        if (i != x && i != y) {
          double pxi = p[x][i], pyi = p[y][i], pix = p[i][x], piy = p[i][y];
          p[x][i] = 0.5 * pxi + 0.5 * pyi, p[i][x] = 0.5 * pix + 0.5 * piy,
          p[y][i] = 0.5 * pyi + 0.5 * pxi;
          p[i][y] = 0.5 * piy + 0.5 * pix;
        }
    }
    double ans = .0;
    for (int i = 2; i <= n; ++i)
      for (int j = 1; j < i; ++j) ans += p[i][j];
    printf("%.10f\n", ans);
  }
  return 0;
}
