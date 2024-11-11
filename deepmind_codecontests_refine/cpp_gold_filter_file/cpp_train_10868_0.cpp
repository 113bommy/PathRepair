#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, b[3], a[30], f[1 << 24], h[1 << 24];
unsigned int g[1 << 24];
int main() {
  scanf("%d", &n);
  m = (1 << n) - 1;
  for (i = 0; i <= n - 1; i++) scanf("%d", &a[i]);
  scanf("%d", &k);
  b[1] = b[2] = -1;
  for (i = 1; i <= k; i++) scanf("%d", &b[i]);
  for (i = 0; i <= n - 1; i++) h[1 << i] = i;
  f[0] = 1;
  for (i = 1; i <= m; i++) {
    g[i] = g[i - (i & -i)] + a[h[i & -i]];
    if (g[i] != b[1] && g[i] != b[2]) {
      for (j = i; j; j -= j & -j) {
        f[i] += f[i - (j & -j)];
        if (f[i] >= 1000000007) f[i] -= 1000000007;
      }
    }
  }
  printf("%d\n", f[m]);
  return 0;
}
