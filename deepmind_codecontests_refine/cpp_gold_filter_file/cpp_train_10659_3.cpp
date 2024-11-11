#include <bits/stdc++.h>
int a[1005], b[1005], f[1005], m;
int main() {
  int n, x, q, p, i, j;
  scanf("%d%d", &n, &x);
  for (i = 1; i <= n; i++) {
    scanf("%d", &f[i]);
    if (f[i] == 0) {
      m++;
      b[i] = m;
      a[m] = 1;
    }
  }
  q = 1;
  while (q) {
    q = 0;
    p = b[x];
    for (i = 1; i <= n; i++)
      if (b[i] == 0 && b[f[i]] != 0 && f[i] != x) {
        q = 1;
        b[i] = b[f[i]];
        a[b[i]]++;
      }
  }
  p = b[x];
  for (i = 1; i <= n; i++) f[i] = 0;
  f[0] = 1;
  for (i = 1; i <= m; i++)
    if (i != p) {
      x = a[i];
      for (j = n; j >= x; j--)
        if (!f[j] && f[j - x]) f[j] = 1;
    }
  for (i = 0; i <= n; i++)
    if (f[i]) printf("%d\n", i + a[p]);
  return 0;
}
