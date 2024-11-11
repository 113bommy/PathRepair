#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
const double epsi = 1e-12;
int m, n;
int a[maxn];
double c[maxn][maxn];
double f[maxn][maxn][maxn];
void init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &a[i]);
  }
}
void solve() {
  for (int i = 0; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  }
  memset(f, 0, sizeof(f));
  f[0][0][0] = 1;
  for (int i = 0; i <= m - 1; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= n; k++)
        if (f[i][j][k] < -epsi || f[i][j][k] > epsi)
          for (int jj = 0; jj <= n - j; jj++)
            f[i + 1][j + jj][max(k, (int)ceil((double)jj / a[i + 1]))] +=
                c[j + jj][j] * f[i][j][k];
  double x, s;
  x = s = 0;
  for (int i = 0; i <= n; i++) {
    x += i * f[m][n][i];
    s += f[m][n][i];
  }
  printf("%.10lf\n", x / s);
}
int main() {
  init();
  solve();
  return 0;
}
