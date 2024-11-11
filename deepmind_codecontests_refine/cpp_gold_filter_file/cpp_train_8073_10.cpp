#include <bits/stdc++.h>
using namespace std;
int L, n, p, t, g[200000], f[200000], x, y;
int main() {
  scanf("%d%d%d%d", &L, &n, &p, &t);
  g[0] = -t;
  for (int j = 1, i = 1; i <= n; ++i) {
    scanf("%d%d", &x, &y);
    for (--j; g[j] + t <= y && j < i; ++j) {
      int L = max(x, g[j] + t), now = f[j] + (y - L) / p;
      if (f[i] < now || (f[i] == now && L + (y - L) / p * p < g[i]))
        f[i] = now, g[i] = L + (y - L) / p * p;
    }
    if (f[i - 1] > f[i] || (f[i - 1] == f[i] && g[i - 1] < g[i]))
      f[i] = f[i - 1], g[i] = g[i - 1];
  }
  return printf("%d", f[n]), 0;
}
