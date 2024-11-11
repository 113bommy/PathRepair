#include <bits/stdc++.h>
using namespace std;
struct node {
  int val, prio, size, rev;
  node *l, *r;
};
inline int size(node *u) { return u ? u->size : 0; }
node *update(node *u) {
  if (u) u->size = 1 + size(u->l) + size(u->r);
  return u;
}
void push(node *u) {
  if (u && u->rev) {
    swap(u->l, u->r);
    if (u->l) u->l->rev ^= 1;
    if (u->r) u->r->rev ^= 1;
    u->rev = 0;
  }
}
node *merge(node *u, node *v) {
  push(u);
  push(v);
  if (!u || !v) return u ? u : v;
  if (u->prio > v->prio) {
    u->r = merge(u->r, v);
    update(u);
    return u;
  } else {
    v->l = merge(u, v->l);
    update(v);
    return v;
  }
}
pair<node *, node *> split(node *u, int k) {
  if (!u) return make_pair(u, u);
  push(u);
  if (size(u->l) >= k) {
    pair<node *, node *> ans = split(u->l, k);
    u->l = ans.second;
    update(u);
    ans.second = u;
    return ans;
  } else {
    pair<node *, node *> ans = split(u->r, k - size(u->l) - 1);
    u->r = ans.first;
    update(u);
    ans.first = u;
    return ans;
  }
}
vector<int> ans;
void p(node *t) {
  if (!t) return;
  push(t);
  p(t->l);
  ans.push_back(t->val);
  p(t->r);
}
int n, m, l, r, q, b, a, t;
node *root;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> q >> m;
  for (int i = 0; i < n; i++) {
    cin >> a;
    root = merge(root, new node{a, rand(), 1, 0, 0, 0});
  }
  int pos = 0;
  while (q--) {
    cin >> t >> l >> r;
    if (t == 1) {
      pair<node *, node *> x = split(root, r);
      pair<node *, node *> y = split(x.first, l - 1);
      pair<node *, node *> z = split(y.second, r - l);
      root = merge(z.second, z.first);
      root = merge(y.first, root);
      root = merge(root, x.second);
    } else {
      pair<node *, node *> x = split(root, r);
      pair<node *, node *> y = split(x.first, l - 1);
      y.second->rev = 1;
      root = merge(y.first, y.second);
      root = merge(root, x.second);
    }
  }
  p(root);
  for (int i = 0; i < m; i++) {
    cin >> b;
    cout << ans[b - 1] << " ";
  }
}
