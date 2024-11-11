#include <bits/stdc++.h>
using namespace std;
const long long N = 8e5 + 10, inf = 0x3f3f3f3f, llinf = 0x3f3f3f3f3f3f3f3f;
const int M = 2e7 + 5;
long long n, m, q;
long long nn;
int a[N];
struct LCT {
  int c[N][2], fa[N], s[N], r[N], st[N], cir[N], tcir[N];
  inline int lc(int x) { return c[x][0]; }
  inline int rc(int x) { return c[x][1]; }
  void pushup(int x) {
    s[x] = s[lc(x)] ^ s[rc(x)] ^ a[x];
    cir[x] = cir[lc(x)] | cir[rc(x)] | tcir[x];
  }
  void pushr(int x) {
    swap(c[x][0], c[x][1]);
    r[x] ^= 1;
  }
  void pushdown(int x) {
    if (r[x]) {
      if (lc(x)) pushr(lc(x));
      if (rc(x)) pushr(rc(x));
      r[x] = 0;
    }
  }
  int nroot(int x) { return lc(fa[x]) == x || rc(fa[x]) == x; }
  void rotate(int x) {
    int y = fa[x], z = fa[y];
    int ys = c[y][1] == x, zs = c[z][1] == y, w = c[x][!ys];
    if (nroot(y)) c[z][zs] = x;
    c[x][!ys] = y;
    c[y][ys] = w;
    if (w) fa[w] = y;
    fa[x] = z;
    fa[y] = x;
    pushup(x);
    pushup(y);
  }
  void splay(int x) {
    int y = x, tot = 0;
    st[++tot] = y;
    while (nroot(y)) {
      st[++tot] = fa[y];
      y = fa[y];
    }
    while (tot) pushdown(st[tot--]);
    while (nroot(x)) {
      int y = fa[x], z = fa[y];
      if (nroot(y)) {
        rotate((c[y][0] == x) ^ (c[z][0] == y) ? x : y);
      }
      rotate(x);
    }
    pushup(x);
  }
  void access(int x) {
    for (int y = 0; x; y = x, x = fa[x]) {
      splay(x);
      c[x][1] = y;
      pushup(x);
    }
  }
  int findroot(int x) {
    access(x);
    splay(x);
    while (lc(x)) {
      pushdown(x);
      x = lc(x);
    }
    splay(x);
    return x;
  }
  void makeroot(int x) {
    access(x);
    splay(x);
    pushr(x);
  }
  void split(int x, int y) {
    makeroot(x);
    access(y);
    splay(y);
  }
  void link(int x, int y) {
    makeroot(x);
    if (findroot(y) != x) fa[x] = y;
  }
  void cut(int x, int y) {
    makeroot(x);
    if (findroot(y) == x && fa[y] == x && !lc(y)) {
      fa[y] = c[x][1] = 0;
      pushup(x);
    }
  }
  void update(int x) {
    if (x > n) {
      tcir[x] = 1;
    }
    if (lc(x)) update(lc(x));
    if (rc(x)) update(rc(x));
    pushup(x);
  }
  int work(int x, int y, int z) {
    makeroot(x);
    if (findroot(y) != x) {
      ++nn;
      a[x] = z;
      link(x, nn);
      link(nn, y);
      return 1;
    } else {
      if ((s[x] ^ z) == 1 && !cir[x]) {
        update(x);
        return 1;
      } else {
        return 0;
      }
    }
  }
} lct;
void solve() {
  cin >> n >> q;
  nn = n;
  for (int i = 1; i <= q; ++i) {
    int u, v, x;
    cin >> u >> v >> x;
    if (lct.work(u, v, x)) {
      cout << ((1) ? "YES" : "NO") << '\n';
    } else {
      cout << ((0) ? "YES" : "NO") << '\n';
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  int tt = 1;
  while (tt--) {
    solve();
  }
}
