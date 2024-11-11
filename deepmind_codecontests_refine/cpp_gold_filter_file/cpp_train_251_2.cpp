#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, an;
int f[(1 << 20)], h[(1 << 20)];
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &k), f[k]++;
  m = (1 << 20) - 1;
  for (i = 0; i <= 19; i++)
    for (j = 0; j <= m; j++)
      if (!(j & (1 << i))) f[j] += f[j | (1 << i)];
  h[0] = 1;
  for (i = 1; i <= (1 << 20) - 1; i++) h[i] = h[i - 1] * 2 % 1000000007;
  for (i = 0; i <= m; i++) {
    int s = 0;
    for (j = 0; j <= 19; j++) s += i >> j & 1;
    if (f[i]) an = ((s & 1 ? -1 : 1) * (h[f[i]] - 1) + an) % 1000000007;
  }
  if (an < 0) an += 1000000007;
  printf("%d\n", an);
  return 0;
}
