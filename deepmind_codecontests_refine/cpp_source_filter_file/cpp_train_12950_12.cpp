#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, a[40][40], b[40][40], u, an;
int main() {
  scanf("%d", &n);
  m = n / 2 + 1;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) scanf("%d", &a[i][j]);
  an = -1 << 30;
  for (u = 0; u <= (1 << n) - 1; u++) {
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++) b[i][j] = a[i][j];
    for (i = 1; i <= n; i++)
      if (u >> i - 1 & 1)
        for (j = m; j <= n; j++)
          for (k = i; k <= i + m - 1; k++) b[j][k] *= -1;
    int s = 0;
    for (i = 1; i <= n; i++) s += b[m][i];
    for (i = 1; i <= m - 1; i++)
      for (j = 1; j <= n; j++) b[i][j] += b[i + m][j];
    for (i = 1; i <= m - 1; i++) {
      int a1 = b[i][m], a2 = -a1;
      for (j = 1; j <= m - 1; j++) {
        int b1 = b[i][j], b2 = b[i][j + m];
        a1 += max(b1 + b2, -b1 - b2);
        a2 += max(b1 - b2, b2 - b1);
      }
      s += max(a1, a2);
    }
    an = max(an, s);
  }
  printf("%d\n", an);
  return 0;
}
