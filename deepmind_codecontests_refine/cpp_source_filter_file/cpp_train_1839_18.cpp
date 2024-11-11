#include <bits/stdc++.h>
using namespace std;
struct Node {
  long long l, r, f;
  Node() {
    l = -1;
    r = -1;
    f = 0;
  }
};
const long long MAXL = 1e7, MAXN = 1e5 + 7;
Node a[MAXL];
long long ptr = -1;
long long newNode() {
  ++ptr;
  return ptr;
}
struct segmenttree {
  long long root;
  long long get(long long v, long long tl, long long tr, long long l,
                long long r) {
    if (l > tr || tl > r)
      return 0;
    else if (l <= tl && tr <= r)
      return a[v].f;
    else {
      long long tm = (tl + tr) / 2;
      if (a[v].l == -1) a[v].l = newNode();
      if (a[v].r == -1) a[v].r = newNode();
      return get(a[v].l, tl, tm, l, r) + get(a[v].r, tm + 1, tr, l, r);
    }
  }
  void upd(long long v, long long tl, long long tr, long long p,
           long long val) {
    a[v].f = max(a[v].f, val);
    if (tl != tr) {
      long long tm = (tl + tr) / 2;
      if (a[v].l == -1) a[v].l = newNode();
      if (a[v].r == -1) a[v].r = newNode();
      if (p <= tm)
        upd(a[v].l, tl, tm, p, val);
      else
        upd(a[v].r, tm + 1, tr, p, val);
    }
  }
  long long getMax(long long l, long long r) {
    if (l < 0 || l > r)
      return 0;
    else
      return get(root, 0, MAXN - 1, l, r);
  }
  void setMax(long long p, long long v) { upd(root, 0, MAXN - 1, p, v); }
  segmenttree() { root = newNode(); }
};
segmenttree vs[MAXN];
void solve() {
  long long n, m;
  cin >> n >> m;
  long long ans = 0;
  for (long long i = 0; i < m; ++i) {
    long long a, b, w;
    cin >> a >> b >> w;
    --a;
    --b;
    w += 2;
    long long opt = vs[a].getMax(0, w - 1) + 1;
    vs[b].setMax(w, opt);
    ans = max(ans, opt);
  }
  cout << ans;
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cout.precision(40);
  solve();
  return 0;
}
