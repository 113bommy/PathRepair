#include <bits/stdc++.h>
const int maxn = 100100;
int n;
double p[maxn], f[maxn], g[maxn];
int main() {
  scanf("%d", &n);
  for (register int i = 1; i <= n; ++i) scanf("%lf", &p[i]);
  for (register int i = 1; i <= n; ++i) {
    f[i] = f[i - 1] + p[i] * (2 * g[i - 1] + 1);
    g[i] = p[i] * (g[i - 1] + 1);
  }
  printf("%.6lf\n", f[n]);
  return 0;
}
