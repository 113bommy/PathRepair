#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline void chkmin(T1 &x, T2 y) {
  if (y < x) x = y;
};
template <typename T1, typename T2>
inline void chkmax(T1 &x, T2 y) {
  if (y > x) x = y;
};
struct node {
  int x, y, val;
  int mx;
  node *l, *r;
  node() {}
  node(int _x, int _val) : x(_x), val(_val) {
    y = RAND_MAX * rand() + rand();
    l = r = nullptr;
    mx = val;
  }
};
int mxv(node *t) { return (t == nullptr ? -2e9 : t->mx); }
void upd(node *&t) {
  if (t != nullptr) {
    t->mx = t->val;
    chkmax(t->mx, mxv(t->l));
    chkmax(t->mx, mxv(t->r));
  }
}
node *merge(node *a, node *b) {
  if (a == nullptr) return b;
  if (b == nullptr) return a;
  if (a->y > b->y) {
    a->r = merge(a->r, b);
    upd(a);
    return a;
  } else {
    b->l = merge(a, b->l);
    upd(b);
    return b;
  }
}
pair<node *, node *> split(node *t, int x) {
  if (t == nullptr) return {t, t};
  if (t->x < x) {
    auto p = split(t->r, x);
    t->r = p.first;
    upd(t);
    return {t, p.second};
  } else {
    auto p = split(t->l, x);
    t->l = p.second;
    upd(t);
    return {p.first, t};
  }
}
void add(node *&t, int x, int val) {
  auto p = split(t, x);
  t = merge(p.first, merge(new node(x, val), p.second));
}
int ans;
node *tr[100005];
void go(int v, int u, int w) {
  int d = 1;
  auto p = split(tr[u], w);
  chkmax(d, mxv(p.first) + 1);
  tr[u] = merge(p.first, p.second);
  chkmax(ans, d);
  add(tr[v], w, d);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  ans = 0;
  fill(tr, tr + n + 1, nullptr);
  for (int e = 0; e < m; ++e) {
    int v, u, w;
    cin >> v >> u >> w;
    go(v, u, w);
  }
  cout << ans << endl;
  return 0;
}
