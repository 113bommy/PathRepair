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
inline void write(long long x) {
  register char c[21], len = 0;
  if (!x) return putchar('0'), void();
  if (x < 0) x = -x, putchar('-');
  while (x) c[++len] = x % 10, x /= 10;
  while (len) putchar(c[len--] + 48);
}
const int N = 3e5 + 10;
int n, q, a[N], l, r;
struct mat {
  long long a[4];
  inline mat() {}
  inline mat operator*(const mat& b) {
    mat c;
    c.a[0] = max(a[0] + b.a[0], a[1] + b.a[2]);
    c.a[1] = max(a[0] + b.a[1], a[1] + b.a[3]);
    c.a[2] = max(a[2] + b.a[0], a[3] + b.a[2]);
    c.a[3] = max(a[2] + b.a[1], a[3] + b.a[3]);
    return c;
  }
} tr[N * 4], I;
void bld(int x, int l, int r) {
  if (l == r) {
    tr[x].a[1] = -a[l];
    tr[x].a[2] = a[l];
    return;
  }
  bld((x << 1), l, ((l + r) >> 1)), bld((x << 1 | 1), ((l + r) >> 1) + 1, r);
  tr[x] = tr[(x << 1)] * tr[(x << 1 | 1)];
}
void upd(int x, int l, int r, int p, int k) {
  if (l == r) {
    tr[x].a[1] = -k;
    tr[x].a[2] = k;
    return;
  }
  if (p <= ((l + r) >> 1))
    upd((x << 1), l, ((l + r) >> 1), p, k);
  else
    upd((x << 1 | 1), ((l + r) >> 1) + 1, r, p, k);
  tr[x] = tr[(x << 1)] * tr[(x << 1 | 1)];
}
void solve() {
  n = read(), q = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  bld(1, 1, n);
  I.a[0] = -1e9, I.a[1] = 0;
  mat ans = I * tr[1];
  write(max(ans.a[0], ans.a[1])), putchar('\n');
  while (q--) {
    l = read(), r = read();
    upd(1, 1, n, l, a[r]);
    upd(1, 1, n, r, a[l]);
    swap(a[l], a[r]);
    ans = I * tr[1];
    write(max(ans.a[0], ans.a[1])), putchar('\n');
  }
  memset(tr, 0, sizeof(mat) * (n * 4 + 1));
}
int main() {
  int T = read();
  while (T--) solve();
}
