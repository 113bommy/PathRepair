#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void in(T &x) {
  x = 0;
  char c = getchar();
  bool f = 0;
  while (c < '0' || c > '9') f |= (c == '-'), c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + (c ^ '0'), c = getchar();
  f ? x = -x : 0;
}
template <class T>
inline void out(T x) {
  static short st[30];
  short tp = 0;
  if (x < 0) putchar('-'), x = -x;
  do st[++tp] = x % 10, x /= 10;
  while (x);
  while (tp) putchar('0' | st[tp--]);
}
template <class T, class... Args>
inline void in(T &x, Args &...args) {
  in(x);
  in(args...);
}
template <class T, class... Args>
inline void out(const T &x, const Args &...args) {
  out(x), putchar(' ');
  out(args...);
}
template <class... Args>
inline void outn(const Args &...args) {
  out(args...);
  putchar('\n');
}
namespace i207M {
int tot, val[1000005], dat[1000005], ls[1000005], rs[1000005], tag[1000005];
inline int cre(int v) {
  val[++tot] = v, dat[tot] = rand();
  return tot;
}
inline void down(int x) {
  if (tag[x]) {
    if (ls[x]) tag[ls[x]] += tag[x];
    if (rs[x]) tag[rs[x]] += tag[x];
    val[x] += tag[x];
    tag[x] = 0;
  }
}
void split(int &x, int v, int &a, int &b) {
  if (!x) {
    a = b = 0;
    return;
  }
  down(x);
  if (val[x] < v) {
    a = x;
    split(rs[x], v, rs[x], b);
  } else {
    b = x;
    split(ls[x], v, a, ls[x]);
  }
}
int merge(int x, int y) {
  if (!x || !y) return x | y;
  down(x), down(y);
  if (dat[x] < dat[y]) {
    rs[x] = merge(rs[x], y);
    return x;
  } else {
    ls[y] = merge(x, ls[y]);
    return y;
  }
}
int findmin(int x) {
  down(x);
  if (!ls[x]) return val[x];
  return findmin(ls[x]);
}
const int inf = 2e9;
int count(int x) {
  if (!x) return 0;
  down(x);
  return count(ls[x]) + (val[x] < inf) + count(rs[x]);
}
int n;
int ql[1000005], qr[1000005];
signed main() {
  in(n);
  for (register int i = 1; i <= n; ++i) in(ql[i], qr[i]);
  int rt = cre(0);
  for (register int i = 1; i <= n; ++i) rt = merge(rt, cre(inf + i));
  for (register int i = 1; i <= n; ++i) {
    int a, b, c, t;
    split(rt, ql[i], a, b);
    split(b, qr[i], b, c);
    if (b) ++tag[b];
    t = findmin(c);
    split(c, t + 1, t, c);
    rt = merge(merge(merge(a, cre(ql[i])), b), c);
  }
  int ans = count(rt) - 1;
  outn(ans);
  return 0;
}
}  // namespace i207M
int main() {
  i207M::main();
  return 0;
}
