#include <bits/stdc++.h>
using namespace std;
const int N = 61;
const int oo = 1 << 20;
int a[N][N][N], f[N][N][N];
int n, m, r;
int main() {
  int i, j, k, p;
  scanf("%d%d%d", &n, &m, &r);
  for (p = 0; p < m; p++) {
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++) scanf("%d", &a[p][i][j]);
    for (k = 0; k < n; k++)
      for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
          a[p][i][j] = min(a[p][i][j], a[p][i][k] + a[p][k][j]);
  }
  for (k = 0; k < n; k++)
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++) f[k][i][j] = oo;
  for (i = 0; i <= n; i++)
    for (j = 0; j < n; j++)
      for (p = 0; p < m; p++) f[0][i][j] = min(f[0][i][j], a[p][i][j]);
  for (k = 1; k <= n; k++)
    for (i = 0; i <= n; i++)
      for (j = 0; j < n; j++)
        for (p = 0; p < n; p++)
          f[k][i][j] = min(f[k][i][j], f[k - 1][i][p] + f[0][p][j]);
  while (r--) {
    scanf("%d%d%d", &i, &j, &k);
    k = min(k, n);
    printf("%d\n", f[k][i - 1][j - 1]);
  }
}
