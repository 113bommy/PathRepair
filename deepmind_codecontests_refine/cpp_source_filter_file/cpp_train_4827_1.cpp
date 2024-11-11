#include <bits/stdc++.h>
const int maxn = 100100;
int n;
long double p[maxn], f[maxn], g[maxn];
int main() {
  scanf("%d", &n);
  for (register int i = 1; i <= n; ++i) scanf("%Lf", &p[i]);
  for (register int i = 1; i <= n; ++i) {
    f[i] = f[i - 1] + p[i] * (2 * g[i - 1] + 1);
    g[i] = p[i] * (g[i - 1] + 1);
  }
  printf("%.10Lf\n", f[n]);
  return 0;
}
