#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, len, u;
int a[60];
double f[60][60][60][60], x, an;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &len);
  f[0][0][0][0] = 1;
  for (i = 0; i <= n - 1; i++)
    for (j = 0; j <= i; j++)
      for (k = 0; k <= i; k++)
        for (u = 0; u <= len; u++)
          if (x = f[i][j][k][u]) {
            if (u + a[i + 1] <= len) f[i + 1][j + 1][k][u + a[i + 1]] += x;
            if (!k) f[i + 1][j][i + 1][u] += x;
            f[i + 1][j][k][u] += x;
          }
  for (j = 0; j <= n; j++)
    for (k = 0; k <= n; k++)
      for (u = 0; u <= len; u++)
        if (x = f[n][j][k][u]) {
          if (j < n && !k) continue;
          if (u + a[k] <= len) continue;
          for (i = 1; i <= j; i++) x *= i;
          for (i = 1; i <= n - j - 1; i++) x *= i;
          an += x * j;
        }
  for (i = 1; i <= n; i++) an /= i;
  printf("%.12lf\n", an);
  return 0;
}
