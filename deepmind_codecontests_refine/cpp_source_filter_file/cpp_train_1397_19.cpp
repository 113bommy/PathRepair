#include <bits/stdc++.h>
using namespace std;
int n, k, x, v[10001], w[10001], f[10001], g[10001], ans = -1;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    w[i] = v[i] - x * k;
  }
  for (int i = 1; i <= 10000; i++) f[i] = g[i] = -1 << 30;
  for (int i = 1; i <= n; i++) {
    if (w[i] >= 0)
      for (int j = 10000; j >= w[i]; j--) f[j] = max(f[j - w[i]] + v[i], f[j]);
  }
  for (int i = 1; i <= n; i++) {
    if (w[i] < 0)
      for (int j = 10000; j >= -w[i]; j--) g[j] = max(g[j + w[i]] + v[i], g[j]);
  }
  for (int i = 1; i <= 10000; i++)
    if (f[i] || g[i]) ans = max(ans, f[i] + g[i]);
  printf("%d", ans);
}
