#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T& arr) {
  for (long long i = 0; i < arr.size(); ++i) cin >> arr[i];
}
long long my_pow(long long a, long long b) {
  long long ans = 1;
  for (long long i = 0; i < b; ++i) {
    ans *= a;
  }
  return ans;
}
class treap {
 public:
  long long y;
  double val, mx, x;
  treap *left, *right;
  treap(double c, long long p, double _val) {
    x = c, y = p;
    mx = _val;
    left = right = NULL;
    val = _val;
  }
};
double getm(treap* t) { return t == NULL ? 0. : t->val; }
void recalc(treap*& t) {
  t->val = max(t->mx, max(getm(t->left), getm(t->right)));
}
treap* merge(treap* l, treap* r) {
  if (!l) return r;
  if (!r) return l;
  if (l->y >= r->y) {
    l->right = merge(l->right, r);
    recalc(l);
    return l;
  } else {
    r->left = merge(l, r->left);
    recalc(r);
    return r;
  }
}
void split(treap* t, double x, treap*& l, treap*& r) {
  if (t == NULL) {
    l = r = NULL;
  } else {
    if (t->x > x || abs(t->x - x) < 0.00000001) {
      split(t->left, x, l, t->left);
      r = t;
      recalc(r);
    } else {
      split(t->right, x, t->right, r);
      l = t;
      recalc(l);
    }
  }
}
void print(treap*& t) {
  if (t == NULL) return;
  if (t->left != NULL) print(t->left);
  cout << t->x << " ";
  if (t->right != NULL) print(t->right);
}
void add(treap*& t, double x, double val) {
  treap *l = NULL, *r = NULL;
  split(t, x, l, r);
  treap* v = new treap(x, rand() % 100000000, val);
  t = merge(l, merge(v, r));
}
void solve() {
  int n;
  cin >> n;
  vector<double> a;
  for (int i = 0; i < n; ++i) {
    double r, h;
    cin >> r >> h;
    a.push_back(h * 3.14159265359 * r * r);
  }
  treap* t = NULL;
  add(t, a[0], a[0]);
  double ans = a[0];
  for (int i = 1; i < n; ++i) {
    treap *l, *r;
    l = r = NULL;
    split(t, a[i], l, r);
    double cur = a[i];
    if (l != NULL) {
      cur += l->val;
    }
    t = merge(l, r);
    add(t, a[i], cur);
    ans = max(ans, cur);
  }
  printf("%.8f\n", ans);
}
int main() {
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
