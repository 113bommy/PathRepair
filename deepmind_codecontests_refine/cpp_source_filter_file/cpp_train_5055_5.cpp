#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
struct node {
  long long odd, even, lst;
  int sz;
} it[2][maxn * 4], emp;
int n, m;
long long lzy[2][maxn * 4], a[2][maxn];
node Merge(node a, node b) {
  if (!b.sz) return a;
  if (!a.sz) return b;
  node c;
  c.sz = a.sz + b.sz;
  if (b.sz & 1)
    c.lst = b.lst - a.lst;
  else
    c.lst = b.lst + a.lst;
  if (a.sz & 1) {
    c.odd = min(a.odd, b.even - a.lst);
    c.even = min(a.even, b.odd + a.lst);
  } else {
    c.odd = min(a.odd, b.odd - a.lst);
    c.even = min(a.even, b.even + a.lst);
  }
  return c;
}
void build(int t, int node, int l, int r) {
  if (l > r) return;
  if (l == r) {
    it[t][node].odd = it[t][node].lst = a[t][l] - 1;
    it[t][node].even = 1e18;
    it[t][node].sz = 1;
    return;
  }
  build(t, node * 2, l, (l + r) / 2);
  build(t, node * 2 + 1, (l + r) / 2 + 1, r);
  it[t][node] = Merge(it[t][node * 2], it[t][node * 2 + 1]);
}
void lazy(int t, int node, int l, int r) {
  if (!lzy[t][node]) return;
  it[t][node].odd += lzy[t][node];
  if (it[t][node].sz & 1) it[t][node].lst += lzy[t][node];
  if (l != r) {
    lzy[t][node * 2] += lzy[t][node];
    lzy[t][node * 2 + 1] += lzy[t][node];
  }
  lzy[t][node] = 0;
}
void upd(int t, int node, int l, int r, int ll, int rr, int v) {
  lazy(t, node, l, r);
  if (l > r || l > rr || ll > r) return;
  if (ll <= l && r <= rr) {
    lzy[t][node] = v;
    lazy(t, node, l, r);
    return;
  }
  upd(t, node * 2, l, (l + r) / 2, ll, rr, v);
  upd(t, node * 2 + 1, (l + r) / 2 + 1, r, ll, rr, v);
  it[t][node] = Merge(it[t][node * 2], it[t][node * 2 + 1]);
}
node get(int t, int node, int l, int r, int ll, int rr) {
  lazy(t, node, l, r);
  if (l > r || l > rr || ll > r) return emp;
  if (ll <= l && r <= rr) return it[t][node];
  return Merge(get(t, node * 2, l, (l + r) / 2, ll, rr),
               get(t, node * 2 + 1, (l + r) / 2 + 1, r, ll, rr));
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[0][i];
  for (int i = 1; i <= n; ++i) {
    a[1][i] = a[0][n - i + 1];
  }
  build(0, 1, 1, n);
  build(1, 1, 1, n);
  cin >> m;
  while (m--) {
    int t, x, y, z;
    cin >> t;
    if (t == 2) {
      cin >> x >> y;
      x++, y++;
      bool ok = 0;
      node ans = get(0, 1, 1, n, x, y);
      if (min(ans.odd, ans.even) >= 0 && !ans.lst)
        ok = 1;
      else {
        ans = get(1, 1, 1, n, n - y + 1, n - x + 1);
        if (min(ans.odd, ans.even) >= 0 && !ans.lst) ok = 1;
      }
      cout << ok << '\n';
    } else {
      cin >> x >> y >> z;
      x++, y++;
      upd(0, 1, 1, n, x, y, z);
      upd(1, 1, 1, n, n - y + 1, n - x + 1, z);
    }
  }
}
