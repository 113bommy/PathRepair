#include <bits/stdc++.h>
long long f[1 << 16], y;
int g[16], ans[16], i, k, z, Z, n, m, a, b;
bool mark[16 + 1];
int main() {
  scanf("%d%I64d%d", &n, &y, &m);
  y -= 2001;
  while (m--) {
    scanf("%d%d", &a, &b);
    g[--b] |= (1 << (--a));
  }
  Z = (1 << (n)) - 1;
  memset(ans, -1, sizeof(ans));
  for (i = 0; i < n; ++i) {
    for (ans[i] = 0;; ++ans[i])
      if (!mark[ans[i]]) {
        if (ans[i] >= n) return puts("The times have changed");
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (z = 0; z <= Z; ++z)
          if (f[z]) {
            b = __builtin_popcount(z);
            for (k = 0; k < n; ++k)
              if (!(z & (1 << (k))))
                if ((ans[k] == -1 || ans[k] == b) && ((z & g[k]) == g[k]))
                  f[z | (1 << (k))] += f[z];
          }
        if (y >= f[Z])
          y -= f[Z];
        else {
          mark[ans[i]] = true;
          break;
        }
      }
  }
  for (i = 0; i < n; ++i) printf("%d%c", ans[i] + 1, i + 1 == n ? '\n' : ' ');
  return 0;
}
