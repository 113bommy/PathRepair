#include <bits/stdc++.h>
using namespace std;
const int C = 48;
const int MOD = 95542721;
int cube(long long int x) { return x * x % MOD * x % MOD; }
struct node {
  int a, b;
  node *l, *r;
  int ind, sum[C];
  node(int a, int b, int v) : a(a), b(b), l(NULL), r(NULL), ind(0) {
    sum[0] = v % MOD;
    for (int i = (int)(1); i < ((int)C); i++) sum[i] = cube(sum[i - 1]);
  }
  int val(int i) { return sum[(i + ind) % C]; }
  void push() {
    static int nsum[C];
    for (int i = 0; i < (int)(C); i++) nsum[i] = val(i);
    memcpy(sum, nsum, sizeof sum);
    if (l) l->ind = (l->ind + ind) % C;
    if (r) r->ind = (r->ind + ind) % C;
    ind = 0;
  }
  void pull() {
    ind = 0;
    for (int i = 0; i < (int)(C); i++) {
      sum[i] = l->val(i) + r->val(i);
      if (sum[i] >= MOD) sum[i] -= MOD;
    }
  }
};
const int MAXN = 1e5 + 10;
int n, A[MAXN];
struct lazy {
  node *root;
  void init(int n) { root = build(0, n); }
  node *build(int a, int b) {
    node *res;
    if (a + 1 == b) {
      res = new node(a, b, A[a]);
    } else {
      res = new node(a, b, 0);
      int m = (a + b) / 2;
      res->l = build(a, m);
      res->r = build(m, b);
      res->pull();
    }
    return res;
  }
  void _update(node *x, int a, int b, int delta) {
    if (x->a >= b || x->b <= a) return;
    if (a <= x->a && x->b <= b)
      x->ind = (x->ind + 1) % C;
    else {
      x->push();
      _update(x->l, a, b, delta);
      _update(x->r, a, b, delta);
      x->pull();
    }
  }
  void update(int a, int b, int delta) { _update(root, a, b, delta); }
  int _query(node *x, int a, int b) {
    if (x->a >= b || x->b <= a) return 0;
    if (a <= x->a && x->b <= b)
      return x->val(0);
    else {
      x->push();
      int res = _query(x->l, a, b) + _query(x->r, a, b);
      if (res >= MOD) res -= MOD;
      return res;
    }
  }
  int query(int a, int b) { return _query(root, a, b); }
};
lazy st;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < (int)(n); i++) cin >> A[i];
  st.init(n);
  int q;
  cin >> q;
  while (q--) {
    int op, l, r;
    cin >> op >> l >> r;
    l--;
    if (op == 1)
      cout << st.query(l, r) << '\n';
    else
      st.update(l, r, 1);
  }
  return 0;
}
