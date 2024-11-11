#include <bits/stdc++.h>
using namespace std;
double f[2003][2003];
int r[2003], c[2003], n, m;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    r[x]++;
    c[y]++;
  }
  int R = 0, C = 0;
  for (int i = 1; i <= n; i++)
    if (r[i]) R++;
  for (int j = 1; j <= n; j++)
    if (c[j]) C++;
  f[n][n] = 0;
  for (int i = n; i >= R; i--)
    for (int j = n; j >= C; j--) {
      if (i == n && j == n) continue;
      double p = 1.0 * i / n, q = 1.0 * j / n;
      f[i][j] = (f[i + 1][j + 1] + 1) * (1.0 - p) * (1.0 - q) +
                (f[i + 1][j] + 1) * (1.0 - p) * q +
                (f[i][j + 1] + 1) * p * (1.0 - q);
      f[i][j] /= (1.0 - p * q);
    }
  printf("%.10lf\n", f[R][C]);
}
