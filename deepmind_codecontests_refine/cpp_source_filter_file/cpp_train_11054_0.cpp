#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const long long inf = 0x3f3f3f3f3f3f3f3fll;
int n, a[N], c[N], b[N], nb;
long long g[20][20], f[1 << 20];
void bin(int x) {
  for (int i = 0; i < nb; ++i) printf("%d", x >> i & 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) b[nb++] = a[i];
  sort(b, b + nb), nb = unique(b, b + nb) - b;
  for (int i = 1; i <= n; ++i) a[i] = lower_bound(b, b + nb, a[i]) - b;
  for (int x = 0; x < nb; ++x)
    for (int y = 0; y < nb; ++y) {
      g[x][y] = 0;
      for (int i = 1; i <= n; ++i) c[i] = c[i - 1] + (a[i] == y);
      for (int i = 1; i <= n; ++i)
        if (a[i] == x) g[x][y] += c[i - 1];
    }
  for (int S = 0; S < (1 << nb); ++S) f[S] = inf;
  f[0] = 0;
  for (int S = 0; S < (1 << nb); ++S)
    for (int x = 0; x < nb; ++x)
      if (!(S >> x & 1)) {
        long long t = 0;
        for (int y = 0; y < nb; ++y)
          if (S >> y & 1) t += g[x][y];
        f[S ^ (1 << x)] = min(f[S ^ (1 << x)], f[S] + t);
      }
  printf("%lld\n", f[(1 << nb) - 1]);
  return 0;
}
