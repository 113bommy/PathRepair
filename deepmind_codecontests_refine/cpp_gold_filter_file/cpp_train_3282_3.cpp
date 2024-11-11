#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
struct node {
  int l, r;
  node *lc, *rc;
  int val;
};
int n;
map<int, int> ma;
int cnt;
node *ns[maxn];
void create_sons(node *nd) {
  int md = nd->l + (nd->r - nd->l) / 2;
  if (!nd->lc) {
    nd->lc = new node{nd->l, md, nullptr, nullptr, 0};
  }
  if (!nd->rc) {
    nd->rc = new node{md, nd->r, nullptr, nullptr, 0};
  }
}
void modify(node *nd, int pos, int val) {
  if (pos < nd->l || pos >= nd->r) {
    return;
  }
  if (nd->l + 1 == nd->r) {
    nd->val = val;
    return;
  }
  create_sons(nd);
  modify(nd->lc, pos, val);
  modify(nd->rc, pos, val);
  nd->val = nd->lc->val + nd->rc->val;
}
int query(node *nd, int l, int r) {
  if (!nd || r <= nd->l || l >= nd->r) {
    return 0;
  }
  if (l <= nd->l && r >= nd->r) {
    return nd->val;
  }
  return query(nd->lc, l, r) + query(nd->rc, l, r);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a, t, x;
    cin >> a >> t >> x;
    int p;
    if (ma.count(x) == 0) {
      p = cnt;
      ma[x] = p;
      ns[p] = new node{0, 2000000000, nullptr, nullptr, 0};
      ++cnt;
    } else {
      p = ma[x];
    }
    if (a == 1) {
      modify(ns[p], t, 1);
    } else if (a == 2) {
      modify(ns[p], t, -1);
    } else {
      cout << query(ns[p], 0, t) << '\n';
    }
  }
  return 0;
}
