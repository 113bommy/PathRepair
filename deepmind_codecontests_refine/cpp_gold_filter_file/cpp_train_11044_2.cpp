#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e6 + 100;
const int mod = (int)1e9 + 7;
const int M = (int)5e5 + 100;
int n, a[maxn], q, pr[maxn], lst[maxn];
struct node {
  pair<int, int> val;
  node *l, *r;
  node(int x, int pos) {
    val = make_pair(x, pos);
    l = r = NULL;
  }
  node(node *_l, node *_r) {
    l = _l;
    r = _r;
    val = make_pair(INT_MAX, INT_MAX);
    if (l) val = l->val;
    if (r) val = min(val, r->val);
  }
};
typedef node *pnode;
pnode build(int tl = 1, int tr = n) {
  if (tl == tr) return new node(INT_MAX, tl);
  int tm = (tl + tr) >> 1;
  return new node(build(tl, tm), build(tm + 1, tr));
}
pair<int, int> get(pnode t, int l, int r, int tl = 1, int tr = n) {
  if (!t || l > r || tr < l || tl > r) return make_pair(INT_MAX, INT_MAX);
  if (l <= tl && tr <= r) return t->val;
  int tm = (tl + tr) >> 1;
  return min(get(t->l, l, r, tl, tm), get(t->r, l, r, tm + 1, tr));
}
pnode upd(pnode t, int pos, int val, int tl = 1, int tr = n) {
  if (tl == tr)
    return new node(val, pos);
  else {
    int tm = (tl + tr) >> 1;
    if (pos <= tm)
      return new node(upd(t->l, pos, val, tl, tm), t->r);
    else
      return new node(t->l, upd(t->r, pos, val, tm + 1, tr));
  }
}
pnode root[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    if (!lst[a[i]])
      pr[i] = -1;
    else
      pr[i] = lst[a[i]];
    lst[a[i]] = i;
  }
  root[0] = build();
  for (int i = 1; i <= n; i++) {
    pnode cur = root[i - 1];
    if (pr[i] != -1) cur = upd(cur, pr[i], INT_MAX);
    cur = upd(cur, i, pr[i]);
    root[i] = cur;
  }
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    pair<int, int> cur = get(root[r], l, r);
    if (cur.first < l)
      cout << a[cur.second] << "\n";
    else
      cout << "0\n";
  }
}
