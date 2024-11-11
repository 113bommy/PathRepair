#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, hgs = 1e9 + 7;
struct _line {
  int u, l, r, s;
} a[N];
struct node {
  int hi, l, r, op, id;
  friend bool operator<(node A, node B) {
    return (A.hi == B.hi ? A.op < B.op : A.hi < B.hi);
  }
};
struct _eve {
  int id;
  friend bool operator<(_eve A, _eve B) { return a[A.id].u < a[B.id].u; }
};
int las_on, w, h, n, ans[N];
set<_eve> g[N << 2];
set<_eve>::iterator it;
vector<node> b;
void modify(int k, int l, int r, int x, int y, _eve v, int op) {
  if (x <= l && r <= y) {
    if (op == 1)
      g[k].insert(v);
    else
      g[k].erase(g[k].find(v));
    return;
  }
  int mid = l + r >> 1;
  if (x <= mid) modify(k << 1, l, mid, x, y, v, op);
  if (mid < y) modify(k << 1 | 1, mid + 1, r, x, y, v, op);
  return;
}
void query(int k, int l, int r, int x) {
  if (g[k].size()) {
    it = g[k].begin();
    if (las_on == -1) las_on = it->id;
    if (a[las_on].u < a[it->id].u) las_on = it->id;
  }
  if (l == r) return;
  int mid = l + r >> 1;
  if (x <= mid)
    query(k << 1, l, mid, x);
  else
    query(k << 1 | 1, mid + 1, r, x);
}
int ask(int p) {
  las_on = -1;
  query(1, 1, w, p);
  return (las_on == -1 ? 1 : ans[las_on]);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> h >> w >> n;
  for (register int i = (1); i <= (n); ++i) {
    cin >> a[i].u >> a[i].l >> a[i].r >> a[i].s;
    b.push_back((node){a[i].u, a[i].l, a[i].r, 1, i});
    if (a[i].u + a[i].s + 1 <= h + 1)
      b.push_back((node){a[i].u + a[i].s + 1, a[i].l, a[i].r, -1, i});
  }
  sort(b.begin(), b.end());
  int l = b.size() - 1;
  for (register int i = (0); i <= (l); ++i) {
    node t = b[i];
    if (t.op == 1) {
      if (t.l == 1) ans[t.id] = 2ll * ask(t.r + 1) % hgs;
      if (t.r == w) ans[t.id] = 2ll * ask(t.l - 1) % hgs;
      if (t.l != 1 && t.r != w) ans[t.id] = (ask(t.l - 1) + ask(t.r + 1)) % hgs;
      modify(1, 1, w, t.l, t.r, (_eve){t.id}, 1);
    } else
      modify(1, 1, w, t.l, t.r, (_eve){t.id}, -1);
  }
  int _ans = 0;
  for (register int i = (1); i <= (w); ++i) _ans = (_ans + ask(i)) % hgs;
  cout << _ans << '\n';
  return 0;
}
