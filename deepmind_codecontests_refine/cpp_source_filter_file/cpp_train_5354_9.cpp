#include <bits/stdc++.h>
using namespace std;
int n, m, z, x, y;
double f[1005][1005], p;
bool c1[1005], c2[1005];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    c1[x] = true;
    c2[y] = true;
  }
  x = y = 0;
  for (int i = 1; i <= n; ++i) x += c1[i];
  for (int i = 1; i <= n; ++i) y += c2[i];
  f[n][n] = 0;
  for (int i = n; i >= x; --i)
    for (int j = n; j >= y; --j)
      if (i != n || j != n) {
        p = n * n - i * j;
        f[i][j] = n * n / p + f[i + 1][j + 1] * (n - i) * (n - j) / p +
                  f[i + 1][j] * (n - i) * j / p + f[i][j + 1] * i * (n - j) / p;
      }
  printf("%.10lf", f[x][y]);
}
