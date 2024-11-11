#include <bits/stdc++.h>
#pragma GCC optimize("O2,Ofast,inline,unroll-all-loops,-ffast-math")
using namespace std;
template <class T>
inline void in(T &x) {
  x = 0;
  char c = getchar();
  bool f = 0;
  while (!isdigit(c)) f |= (c == '-'), c = getchar();
  while (isdigit(c)) x = x * 10 + (c ^ '0'), c = getchar();
  f ? x = -x : 0;
}
template <class T>
inline void out(T x, const char c = '\n') {
  static short st[40];
  short m = 0;
  if (x < 0) putchar('-'), x = -x;
  do st[++m] = x % 10, x /= 10;
  while (x);
  while (m) putchar(st[m--] | '0');
  putchar(c);
}
template <class T>
inline void err(const T &x, const char c = '\n') {
  cerr << x << c;
}
template <class T, class... Args>
inline void in(T &x, Args &...args) {
  in(x);
  in(args...);
}
template <class T, class... Args>
inline void out(const T &x, const Args &...args) {
  out(x, ' ');
  out(args...);
}
template <class T, class... Args>
inline void err(const T &x, const Args &...args) {
  err(x, ' ');
  err(args...);
}
template <class T>
inline void prt(T a, int n) {
  for (register int i = 0; i < n; ++i) out(a[i], i == n - 1 ? '\n' : ' ');
}
template <class T>
inline void clr(T a[], int n) {
  memset(a, 0, sizeof(T) * n);
}
template <class T>
inline void clr(T *a, T *b) {
  memset(a, 0, sizeof(T) * (b - a));
}
template <class T>
inline bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
inline bool ckmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
namespace i207M {
const int rt = 1;
const long long Inf = 1e16;
int n, cq;
long long P;
int a[1000005];
struct Node {
  long long l, r;
  int k;
  Node() {}
  Node(const long long _l, const long long _r, const int _k) {
    l = _l, r = _r, k = _k;
  }
};
auto cmpl = [](const Node &a, const Node &b) { return a.l < b.l; };
vector<Node> duan[1000005 * 4];
long long sum[1000005 * 4];
void build(int x, int l, int r) {
  if (l == r) {
    sum[x] = a[l];
    duan[x].emplace_back(Node(-Inf, P - sum[x] - 1, 0)),
        duan[x].emplace_back(Node(P - sum[x], Inf, 1));
    return;
  }
  int mid((l + r) / 2);
  build((x << 1), l, mid), build((x << 1 | 1), mid + 1, r);
  sum[x] = sum[(x << 1)] + sum[(x << 1 | 1)];
  const auto &L = duan[(x << 1)], R = duan[(x << 1 | 1)];
  static Node st[1000005];
  int tp = 0, p = 0;
  for (const auto &it : L) {
    long long mn = it.l + sum[(x << 1)] - it.k * P, mx = mn + it.r - it.l;
    while (p == ((int)R.size()) || (p && mn < R[p].l)) --p;
    while (p < ((int)R.size()) && R[p].l <= mx) {
      long long nl = max(R[p].l, mn), nr = min(R[p].r, mx);
      nl = nl - sum[(x << 1)] + it.k * P, nr = nr - sum[(x << 1)] + it.k * P;
      if (st[tp].k == it.k + R[p].k)
        st[tp].r = nr;
      else
        st[++tp] = Node(nl, nr, it.k + R[p].k);
      ++p;
    }
  }
  duan[x].reserve(tp);
  for (register int i = 1; i <= tp; ++i) duan[x].emplace_back(st[i]);
  duan[x][0].l = -Inf, duan[x].back().r = Inf;
}
long long ans;
void ask(int x, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) {
    const auto &it = *(
        upper_bound(duan[x].begin(), duan[x].end(), Node(ans, 0, 0), cmpl) - 1);
    ans = ans + sum[x] - it.k * P;
    return;
  }
  int mid((l + r) / 2);
  if (ql <= mid) ask((x << 1), l, mid, ql, qr);
  if (qr > mid) ask((x << 1 | 1), mid + 1, r, ql, qr);
}
signed main() {
  in(n, cq, P);
  for (register int i = 1; i <= n; ++i) in(a[i]);
  build(rt, 1, n);
  int l, r;
  while (cq--) {
    in(l, r);
    ans = 0;
    ask(rt, 1, n, l, r);
    out(ans);
  }
  return 0;
}
}  // namespace i207M
signed main() {
  i207M::main();
  return 0;
}
