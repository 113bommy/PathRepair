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
const int maxn = 200005, mod = 1e9 + 7;
int n, m, a[maxn], w[maxn], x, y;
namespace {
inline int Add(const int &x, const int &y) {
  int res = x + y;
  return res >= mod ? res - mod : res;
}
inline int Sub(const int &x, const int &y) {
  int res = x - y;
  return res < 0 ? res + mod : res;
}
inline int Mul(const int &x, const int &y) { return 1ll * x * y % mod; }
}  // namespace
namespace Segtree {
int sq[maxn << 2];
long long sum[maxn << 2];
inline void Build(int o, int l, int r) {
  if (l == r) {
    sq[o] = Mul(a[l], w[l]), sum[o] = w[l];
    return;
  }
  Build(o << 1, l, ((l + r) >> 1)), Build(o << 1 | 1, ((l + r) >> 1) + 1, r);
  sq[o] = Add(sq[o << 1], sq[o << 1 | 1]),
  sum[o] = sum[o << 1] + sum[o << 1 | 1];
}
inline void Modify(int o, int l, int r, int x, int y) {
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
inline int Querys(int o, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return sq[o];
  int res = 0;
  if (ql <= ((l + r) >> 1))
    res = Add(res, Querys(o << 1, l, ((l + r) >> 1), ql, qr));
  if (qr > ((l + r) >> 1))
    res = Add(res, Querys(o << 1 | 1, ((l + r) >> 1) + 1, r, ql, qr));
  return res;
}
inline long long Querya(int o, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return sum[o];
  long long res = 0;
  if (ql <= ((l + r) >> 1)) res += Querya(o << 1, l, ((l + r) >> 1), ql, qr);
  if (qr > ((l + r) >> 1))
    res += Querya(o << 1 | 1, ((l + r) >> 1) + 1, r, ql, qr);
  return res;
}
inline void Printa(int o, int l, int r) {
  cout << "Interval:" << l << " -> " << r << " Sum:" << sum[o] << endl;
  if (l == r) return;
  Printa(o << 1, l, ((l + r) >> 1)), Printa(o << 1 | 1, ((l + r) >> 1) + 1, r);
}
}  // namespace Segtree
int main() {
  read(n), read(m);
  for (int i = 1; i <= n; ++i) read(a[i]), a[i] -= i;
  for (int i = 1; i <= n; ++i) read(w[i]);
  Segtree::Build(1, 1, n);
  while (m--) {
    read(x), read(y);
    if (x < 0)
      Segtree::Modify(1, 1, n, -x, y);
    else {
      long long tot = Segtree::Querya(1, 1, n, x, y);
      tot = (tot + 1) >> 1;
      int l = x, r = n, md;
      while (l < r) {
        md = (l + r) >> 1;
        if (Segtree::Querya(1, 1, n, x, md) < tot)
          l = md + 1;
        else
          r = md;
      }
      int p = l;
      printf("%d\n",
             Add(Sub(Mul(Segtree::Querya(1, 1, n, x, p) % mod, a[p]),
                     Segtree::Querys(1, 1, n, x, p)),
                 Sub(Segtree::Querys(1, 1, n, p + 1, y),
                     Mul(Segtree::Querya(1, 1, n, p + 1, y) % mod, a[p]))));
    }
  }
}
