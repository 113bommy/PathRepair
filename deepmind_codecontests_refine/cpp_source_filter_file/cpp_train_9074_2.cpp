#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
namespace IO {
inline long long read() {
  long long s = 0, ww = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') ww = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    s = 10 * s + ch - '0';
    ch = getchar();
  }
  return s * ww;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar('0' + x % 10);
}
};  // namespace IO
using namespace IO;
int n, q;
int a[N + 5], f[N + 5];
set<int> S[N + 5];
struct node {
  int minn, maxn, fl, fr, sum;
  node() { minn = maxn = fl = fr = sum = 0; }
  node(int _minn, int _maxn, int _fl, int _fr, int _sum) {
    minn = _minn, maxn = _maxn, fl = _fl, fr = _fr, sum = _sum;
  }
  inline friend node merge(node a, node b, int l, int m, int r) {
    node c;
    c.minn = min(a.minn, b.minn);
    c.maxn = max(max(a.maxn, b.maxn), f[m + 1]);
    if (a.minn == b.minn) {
      c.fl = a.fl;
      c.fr = b.fr;
      c.sum = a.sum + b.sum - a.fr - b.fl + max(max(a.fr, b.fl), f[m + 1]);
    } else if (a.minn > b.minn) {
      c.fl = max(max(a.maxn, b.fl), f[m + 1]);
      c.fr = b.fr;
      c.sum = b.sum - b.fl + c.fl;
    } else {
      c.fr = max(max(b.maxn, a.fr), f[m + 1]);
      c.fl = b.fl;
      c.sum = a.sum - a.fr + c.fr;
    }
    return c;
  }
};
struct SegTree {
  node d[4 * N + 5];
  int fminn[4 * N + 5];
  inline void pushup(int u, int l, int m, int r) {
    d[u] = merge(d[(u << 1)], d[((u << 1) | 1)], l, m, r);
  }
  inline void pushdown(int u) {
    if (fminn[u] == 0) return;
    int lc = (u << 1), rc = ((u << 1) | 1);
    d[lc].minn += fminn[u];
    fminn[lc] += fminn[u];
    d[rc].minn += fminn[u];
    fminn[rc] += fminn[u];
    fminn[u] = 0;
  }
  inline void build(int u, int l, int r) {
    if (l == r) {
      d[u] = node(0, 0, 0, 0, 0);
      return;
    }
    int m = (l + r) >> 1;
    build((u << 1), l, m);
    build(((u << 1) | 1), m + 1, r);
    pushup(u, l, m, r);
  }
  inline void ud(int u, int l, int r, int ql, int qr, int dx) {
    if (l == ql && r == qr) {
      d[u].minn += dx;
      fminn[u] += dx;
      return;
    }
    int m = (l + r) >> 1;
    pushdown(u);
    if (qr <= m)
      ud((u << 1), l, m, ql, qr, dx);
    else if (ql > m)
      ud(((u << 1) | 1), m + 1, r, ql, qr, dx);
    else
      ud((u << 1), l, m, ql, m, dx),
          ud(((u << 1) | 1), m + 1, r, m + 1, qr, dx);
    pushup(u, l, m, r);
  }
  inline void print(int u, int l, int r) {
    cout << "print; u=" << u << " l=" << l << " r=" << r
         << " minn=" << d[u].minn << " maxn=" << d[u].maxn << " fl=" << d[u].fl
         << " fr=" << d[u].fr << " sum=" << d[u].sum << endl;
    if (l == r) return;
    int m = (l + r) >> 1;
    pushdown(u);
    print((u << 1), l, m);
    print(((u << 1) | 1), m + 1, r);
  }
  inline int query() { return n - d[1].sum; }
} T;
inline void insert(int id) {
  int t = S[id].size(), l, r;
  if (!t) return;
  set<int>::iterator it = S[id].begin();
  l = *it;
  it = S[id].end();
  it--;
  r = *it;
  f[l] = t;
  if (l < r)
    T.ud(1, 0, n, l, r - 1, 1);
  else
    T.ud(1, 0, n, l, r, 0);
}
inline void remove(int id) {
  int t = S[id].size(), l, r;
  if (!t) return;
  set<int>::iterator it = S[id].begin();
  l = *it;
  it = S[id].end();
  it--;
  r = *it;
  f[l] = 0;
  if (l < r) T.ud(1, 0, n, l, r - 1, -1);
}
inline void solve(int pos, int x) {
  remove(a[pos]);
  remove(x);
  S[a[pos]].erase(pos);
  S[x].insert(pos);
  insert(a[pos]);
  insert(x);
  a[pos] = x;
  write(T.query()), putchar('\n');
}
int main() {
  n = read();
  q = read();
  for (register int i = 1; i <= n; i++) {
    a[i] = read();
    S[a[i]].insert(i);
  }
  T.build(1, 1, n);
  for (register int i = 1; i <= N; i++)
    if (S[i].size()) insert(i);
  write(T.query()), putchar('\n');
  for (register int i = 1; i <= q; i++) {
    int pos = read(), x = read();
    solve(pos, x);
  }
  return 0;
}
