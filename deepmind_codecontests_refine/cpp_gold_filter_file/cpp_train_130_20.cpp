#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int res = 0;
  register char c = getchar(), f = 1;
  while (c < 48 || c > 57) {
    if (c == '-') f = 0;
    c = getchar();
  }
  while (c >= 48 && c <= 57)
    res = (res << 3) + (res << 1) + (c & 15), c = getchar();
  return f ? res : -res;
}
inline void write(int x) {
  register char c[21], len = 0;
  if (!x) return putchar('0'), void();
  if (x < 0) x = -x, putchar('-');
  while (x) c[++len] = x % 10, x /= 10;
  while (len) putchar(c[len--] + 48);
}
const int N = 2e5 + 10;
int n, d, a[N], c[N], q, f[N * 2], c1[N], c2[N], ans = 0;
inline void upd(int x, int v) { --c2[c1[x]], c1[x] += v, ++c2[c1[x]]; }
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) a[i] = read(), ++c[a[i]];
  q = sqrt(n);
  for (int i = 1; i <= n; ++i)
    if (c[i] > c[d]) d = i;
  for (int i = 1; i <= n; ++i)
    if (c[i] > q && i != d) {
      int s = 0;
      memset(f, -1, sizeof(int) * (n * 2 + 1));
      f[n] = 0;
      for (int j = 1; j <= n; ++j) {
        s += a[j] == i ? 1 : (a[j] == d ? -1 : 0);
        if (~f[n + s])
          ans = max(ans, j - f[n + s]);
        else
          f[n + s] = j;
      }
    }
  for (int i = 1; i <= q; ++i) {
    memset(c1, 0, sizeof(int) * (n + 1));
    memset(c2, 0, sizeof(int) * (n + 1));
    int l = 1, r = 0;
    while (r < n) {
      upd(a[++r], 1);
      while (c1[a[r]] > i) upd(a[l++], -1);
      if (c2[i] > 1) ans = max(ans, r - l + 1);
    }
  }
  write(ans), putchar('\n');
}
