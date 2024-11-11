#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, hang[2005], lie[2005];
double f[2005][2005];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    hang[x] = 1, lie[y] = 1;
  }
  x = 0, y = 0;
  for (int i = 1; i <= n; ++i) x += hang[i], y += lie[i];
  for (int i = n; i >= 1; --i)
    for (int j = n; j >= 1; --j) {
      if (i == n && j == n) continue;
      double I = (double)i / (double)n, J = (double)j / (double)n;
      f[i][j] += (f[i][j + 1] + 1.0) * I * (1.0 - J);
      f[i][j] += (f[i + 1][j] + 1.0) * (1.0 - I) * J;
      f[i][j] += (f[i + 1][j + 1] + 1.0) * (1.0 - I) * (1.0 - J);
      f[i][j] += I * J;
      f[i][j] /= (1.0 - I * J);
    }
  printf("%.10lf\n", f[x][y]);
}
