#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
bool Finish_read;
template <class T>
inline void read(T &x) {
  Finish_read = 0;
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    if (ch == EOF) return;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  x *= f;
  Finish_read = 1;
}
template <class T>
inline void print(T x) {
  if (x / 10 != 0) print(x / 10);
  putchar(x % 10 + '0');
}
template <class T>
inline void writeln(T x) {
  if (x < 0) putchar('-');
  x = abs(x);
  print(x);
  putchar('\n');
}
template <class T>
inline void write(T x) {
  if (x < 0) putchar('-');
  x = abs(x);
  print(x);
}
const long long maxn = 200005, mod = 1e9 + 7;
long long n, m, a[maxn], w[maxn], x, y;
namespace {
inline long long Add(const long long &x, const long long &y) {
  return (x + y) % mod;
}
inline long long Sub(const long long &x, const long long &y) {
  return ((x - y) % mod + mod) % mod;
}
inline long long Mul(const long long &x, const long long &y) {
  return 1ll * x * y % mod;
}
}  // namespace
namespace Segtree {
long long sq[maxn << 2];
long long sum[maxn << 2];
inline void Build(long long o, long long l, long long r) {
  if (l == r) {
    sq[o] = Mul(a[l], w[l]), sum[o] = w[l];
    return;
  }
  Build(o << 1, l, ((l + r) >> 1)), Build(o << 1 | 1, ((l + r) >> 1) + 1, r);
  sq[o] = Add(sq[o << 1], sq[o << 1 | 1]),
  sum[o] = sum[o << 1] + sum[o << 1 | 1];
}
inline void Modify(long long o, long long l, long long r, long long x,
                   long long y) {
  if (l == r) {
    sq[o] = Mul(a[l], y), sum[o] = y;
    return;
  }
  if (x <= ((l + r) >> 1))
    Modify(o << 1, l, ((l + r) >> 1), x, y);
  else
    Modify(o << 1 | 1, ((l + r) >> 1) + 1, r, x, y);
  sq[o] = Add(sq[o << 1], sq[o << 1 | 1]),
  sum[o] = sum[o << 1] + sum[o << 1 | 1];
}
inline long long Querys(long long o, long long l, long long r, long long ql,
                        long long qr) {
  if (ql <= l && r <= qr) return sq[o];
  long long res = 0;
  if (ql <= ((l + r) >> 1))
    res = Add(res, Querys(o << 1, l, ((l + r) >> 1), ql, qr));
  if (qr > ((l + r) >> 1))
    res = Add(res, Querys(o << 1 | 1, ((l + r) >> 1) + 1, r, ql, qr));
  return res;
}
inline long long Querya(long long o, long long l, long long r, long long ql,
                        long long qr) {
  if (ql <= l && r <= qr) return sum[o];
  long long res = 0;
  if (ql <= ((l + r) >> 1)) res += Querya(o << 1, l, ((l + r) >> 1), ql, qr);
  if (qr > ((l + r) >> 1))
    res += Querya(o << 1 | 1, ((l + r) >> 1) + 1, r, ql, qr);
  return res;
}
inline void Printa(long long o, long long l, long long r) {
  cout << "Interval:" << l << " -> " << r << " Sum:" << sum[o] << endl;
  if (l == r) return;
  Printa(o << 1, l, ((l + r) >> 1)), Printa(o << 1 | 1, ((l + r) >> 1) + 1, r);
}
}  // namespace Segtree
signed main() {
  read(n), read(m);
  for (long long i = 1; i <= n; ++i) read(a[i]), a[i] -= i;
  for (long long i = 1; i <= n; ++i) read(w[i]);
  Segtree::Build(1, 1, n);
  while (m--) {
    read(x), read(y);
    if (x < 0)
      Segtree::Modify(1, 1, n, -x, y);
    else {
      long long tot = Segtree::Querya(1, 1, n, x, y);
      tot = (tot + 1) >> 1;
      long long l = x, r = n, md;
      while (l < r) {
        md = (l + r) >> 1;
        if (Segtree::Querya(1, 1, n, x, md) < tot)
          l = md + 1;
        else
          r = md;
      }
      long long p = l;
      printf("%lld\n",
             Add(Sub(Mul(Segtree::Querya(1, 1, n, x, p) % mod, a[p]),
                     Segtree::Querys(1, 1, n, x, p)),
                 Sub(Segtree::Querys(1, 1, n, p + 1, y),
                     Mul(Segtree::Querya(1, 1, n, p + 1, y) % mod, a[p]))));
    }
  }
}
