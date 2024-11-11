#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1e9 + 9;
const long long N = 300005;
long long n, q, a[N], f[N];
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
long long Add(long long x, long long y) { return (x + y + Mod) % Mod; }
long long mul(long long x, long long y) { return x * y % Mod; }
struct Seg {
  long long l, r;
  long long sum, ff, gg, len;
} tr[N << 2];
void spread(long long x) {
  if ((!tr[x].ff) && (!tr[x].gg)) return;
  tr[x << 1].ff = Add(tr[x << 1].ff, tr[x].ff) % Mod;
  tr[x << 1].gg = Add(tr[x << 1].gg, tr[x].gg) % Mod;
  tr[x << 1].sum =
      Add(tr[x << 1].sum, Add(mul(f[tr[x << 1].len], tr[x].ff),
                              mul(f[tr[x << 1].len + 1] - 1, tr[x].gg)));
  tr[x << 1 | 1].ff =
      Add(tr[x << 1 | 1].ff, Add(mul(f[tr[x << 1].len], tr[x].gg),
                                 mul(f[tr[x << 1].len - 1], tr[x].ff)));
  tr[x << 1 | 1].gg =
      Add(tr[x << 1 | 1].gg, Add(mul(f[tr[x << 1].len], tr[x].gg),
                                 mul(f[tr[x << 1].len - 1], tr[x].ff)));
  tr[x << 1 | 1].sum = Add(tr[x << 1 | 1].sum,
                           Add(Add(Add(mul(tr[x].gg, f[tr[x].len + 1] - 1),
                                       mul(tr[x].ff, f[tr[x].len])),
                                   mul(-tr[x].gg, f[tr[x << 1].len + 1] - 1)),
                               mul(-tr[x].ff, f[tr[x << 1].len])));
  tr[x].ff = tr[x].gg = 0;
  return;
}
void pushup(long long x) {
  tr[x].sum = (tr[x << 1].sum + tr[x << 1 | 1].sum) % Mod;
  return;
}
void build(long long x, long long l, long long r) {
  tr[x].l = l, tr[x].r = r;
  tr[x].len = r - l + 1;
  if (l == r) {
    tr[x].sum = a[l];
    tr[x].ff = tr[x].gg = 0;
    return;
  }
  long long mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  pushup(x);
}
inline long long query(long long x, long long l, long long r) {
  if (l <= tr[x].l && tr[x].r <= r) return tr[x].sum;
  long long mid = (tr[x].l + tr[x].r) >> 1;
  spread(x);
  long long val = 0;
  if (l <= mid) val = (val + query(x << 1, l, r)) % Mod;
  if (mid < r) val = (val + query(x << 1 | 1, l, r)) % Mod;
  return val;
}
void change(long long x, long long l, long long r) {
  if (l <= tr[x].l && tr[x].r <= r) {
    tr[x].ff = (tr[x].ff + f[tr[x].l - l + 1]) % Mod;
    tr[x].gg = (tr[x].gg + f[tr[x].l - l + 2]) % Mod;
    tr[x].sum = ((tr[x].sum + f[tr[x].len] * f[tr[x].l - l + 1] % Mod) % Mod +
                 (f[tr[x].len + 1] - 1) * f[tr[x].l - l + 2] % Mod) %
                Mod;
    return;
  }
  spread(x);
  long long mid = (tr[x].l + tr[x].r) >> 1;
  if (l <= mid) change(x << 1, l, r);
  if (mid < r) change(x << 1 | 1, l, r);
  pushup(x);
  return;
}
signed main() {
  n = read();
  q = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  f[1] = f[2] = 1;
  for (long long i = 3; i <= n + 2; i++) f[i] = (f[i - 1] + f[i - 2]) % Mod;
  build(1, 1, n);
  while (q--) {
    long long opt;
    opt = read();
    if (opt == 1) {
      long long l, r;
      l = read();
      r = read();
      change(1, l, r);
    }
    if (opt == 2) {
      long long x, y;
      x = read();
      y = read();
      printf("%lld\n", query(1, x, y) % Mod);
    }
  }
  return 0;
}
