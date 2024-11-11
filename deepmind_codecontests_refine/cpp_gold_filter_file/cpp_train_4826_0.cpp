#include <bits/stdc++.h>
using namespace std;
int n, m, t, d[1000005], p[1000005], f[1000005], num[1000005], ans;
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return x * f;
}
inline int gf(register int x) { return f[x] == x ? x : f[x] = gf(f[x]); }
int main() {
  n = read();
  m = read();
  for (register int i = 1; i <= n; ++i) f[i] = i;
  p[1] = 1;
  for (register int i = 1, x, y; i <= m; ++i) {
    x = read();
    y = read();
    d[x] ^= 1;
    d[y] ^= 1;
    x = gf(x);
    y = gf(y);
    if (x != y) f[x] = y;
    p[y] = 1;
  }
  for (register int i = 1; i <= n; ++i)
    if (i == gf(i) && p[gf(i)]) t++;
  if (!p[gf(1)]) t++;
  for (register int i = 1; i <= n; ++i)
    if (d[i]) num[gf(i)]++;
  if (t == 1) {
    printf("%d", num[gf(1)] / 2);
    return 0;
  }
  for (register int i = 1; i <= n; ++i)
    if (gf(i) == i && p[i]) {
      ans += num[i] >> 1;
      if (!num[i]) ans++;
    }
  printf("%d", ans);
  return 0;
}
