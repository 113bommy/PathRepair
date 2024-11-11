#include <bits/stdc++.h>
using namespace std;
int rnd() { return (rand() << 16) ^ rand(); }
struct node {
  int min, max, x, y, val;
  node *l, *r;
  node(int x, int val)
      : min(val), max(val), x(x), val(val), y(rnd()), l(NULL), r(NULL) {}
};
typedef node* treap;
int get_min(treap t) {
  if (t == NULL) return 2000000000;
  return t->min;
}
int get_max(treap t) {
  if (t == NULL) return -2000000000;
  return t->max;
}
void up_min(treap t) {
  if (t != NULL) t->min = min(t->val, min(get_min(t->l), get_min(t->r)));
}
void up_max(treap t) {
  if (t != NULL) {
    t->max = max(t->val, max(get_max(t->l), get_max(t->r)));
  }
}
treap merge(treap a, treap b) {
  if (a == NULL) return b;
  if (b == NULL) return a;
  if (a->y > b->y) {
    a->r = merge(a->r, b);
    up_min(a);
    up_max(a);
    return a;
  } else {
    b->l = merge(a, b->l);
    up_min(b);
    up_max(b);
    return b;
  }
}
pair<treap, treap> split(treap t, int x) {
  if (t == NULL) return make_pair(t, t);
  if (x <= t->x) {
    pair<treap, treap> p = split(t->l, x);
    t->l = p.second;
    up_min(t);
    up_max(t);
    return make_pair(p.first, t);
  } else {
    pair<treap, treap> p = split(t->r, x);
    t->r = p.first;
    up_min(t);
    up_max(t);
    return make_pair(t, p.second);
  }
}
treap add(treap t, int x, int val) {
  treap p = new node(x, val);
  return merge(t, p);
}
int dif(treap t, int l, int r) {
  pair<treap, treap> p = split(t, l);
  pair<treap, treap> q = split(p.second, r + 1);
  int x = q.first->max - q.first->min;
  t = merge(p.first, merge(q.first, q.second));
  return x;
}
int main() {
  int n, k, i, l = 1, r = 1, a = 0, h;
  vector<int> ans;
  cin >> n >> k;
  treap t = NULL;
  for (i = 1; i <= n; i++) {
    cin >> h;
    t = add(t, i, h);
  }
  while (l <= n) {
    r++;
    if (r > n || dif(t, l, r) > k) {
      if (r - l > a) a = r - l;
      l = r;
    }
  }
  for (i = 1; i <= n - a + 1; i++) {
    if (dif(t, i, i + a - 1) <= k) ans.push_back(i);
  }
  cout << a << ' ' << ans.size();
  for (i = 0; i < ans.size(); i++) {
    cout << endl << ans[i] << ' ' << ans[i] + a - 1;
  }
  return 0;
}
