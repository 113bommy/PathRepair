#include <bits/stdc++.h>
int i, j, u, v, n, k, a[1024], b, g[120000], C = 100000;
int main() {
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; ++i) scanf("%d", &a[i]);
  g[u = v = C] = 1;
  for (i = 0; i < n; ++i) {
    scanf("%d", &b);
    b = a[i] - b * k;
    if (b < 0) {
      for (j = u; j <= v; ++j)
        if (g[j])
          if (g[j] + a[i] > g[j + b]) g[j + b] = g[j] + a[i];
    } else {
      for (j = v; j >= u; --j)
        if (g[j])
          if (g[j] + a[i] > g[j + b]) g[j + b] = g[j] + a[i];
    }
    if (v + b > v) v += b;
    if (u + b < u) u += b;
  }
  printf("%d\n", g[C] > 0 ? (g[C] - 1) : -1);
}
