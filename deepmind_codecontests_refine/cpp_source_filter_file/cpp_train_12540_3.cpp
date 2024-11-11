#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000;
int d[2100], f[600][600], h[600][600];
char c1[2100], c2[1200];
int i, j, k, n1, n2;
int main() {
  scanf("%s", c1 + 1);
  scanf("%s", c2 + 1);
  n1 = strlen(c1 + 1);
  n2 = strlen(c2 + 1);
  memset(f, 250, sizeof(f));
  f[n2][0] = 0;
  for (i = 1; i <= n1; i++) {
    for (j = 1; j <= n2; j++)
      for (k = 0; k <= n1 / n2; k++) h[j][k] = f[j][k], f[j][k] = -inf;
    for (j = 1; j <= n2; j++)
      for (k = 0; k <= n1 / n2; k++) {
        if (c1[i] == c2[j])
          if ((j == 1) && (k > 0))
            f[j][k] = h[n2][k - 1] + 1;
          else
            f[j][k] = h[j - 1][k] + 1;
        if (j < n2)
          f[j][k] = max(f[j][k], h[j][k]);
        else
          f[j][k] = max(f[j][k], h[j][k] + 1);
      }
  }
  for (k = 1; k <= n1 / n2; k++)
    if (f[n2][k] >= 0) d[n1 - f[n2][k]] = k;
  for (k = 1; k <= n1; k++) d[k] = max(d[k], d[k - 1]);
  for (k = 0; k <= n1; k++) printf("%d ", min(d[k], (n1 - k) / n2));
  return 0;
}
