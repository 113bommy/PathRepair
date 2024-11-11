#include <bits/stdc++.h>
using namespace std;
constexpr int INF = (numeric_limits<int>::max()) / 2;
constexpr long long INFLL = (numeric_limits<long long>::max()) / 2;
template <class T>
istream &operator>>(istream &is, vector<T> &a) {
  for (auto &i : a) {
    is >> i;
  }
  return is;
}
constexpr int mod = 998244353;
struct segtree {
  struct line {
    int k = -INF, b = -INF;
    line() = default;
    line(int k, int b) : k(k), b(b){};
    bool operator==(line p) const { return k == p.k && b == p.b; }
  };
  struct Node {
    int sum = 0;
    line push;
    Node *l = nullptr, *r = nullptr;
    Node() = default;
  };
  Node *root = nullptr;
  int n = 1e9 + 1;
  void creatend(Node *&v) {
    if (v == nullptr) {
      v = new Node();
    }
  }
  void push(Node *v, int l, int r) {
    if (v->push == line()) {
      return;
    }
    if (l + 1 < r) {
      creatend(v->l);
      if (v->l->push == line()) {
        v->l->push = v->push;
      } else {
        v->l->push = {
            (int)((v->push.k * 1ll * v->l->push.k) % mod),
            (int)((v->push.k * 1ll * v->l->push.b + v->push.b) % mod)};
      }
      creatend(v->r);
      if (v->r->push == line()) {
        v->r->push = v->push;
      } else {
        v->r->push = {
            (int)((v->push.k * 1ll * v->r->push.k) % mod),
            (int)((v->push.k * 1ll * v->r->push.b + v->push.b) % mod)};
      }
    }
    v->sum = (v->sum * 1ll * v->push.k) % mod;
    v->sum = (v->sum + (r - l) * 1ll * v->push.b) % mod;
    v->sum = (v->sum + mod) % mod;
    v->push = line();
  }
  void update(Node *&v, int l, int r, int li, int ri, line f) {
    creatend(v);
    push(v, l, r);
    if (li >= r || l >= ri) {
      return;
    }
    if (li <= l && r <= ri) {
      v->push = f;
      push(v, l, r);
      return;
    }
    int m = (l + r) / 2;
    update(v->l, l, m, li, ri, f);
    update(v->r, m, r, li, ri, f);
    v->sum = (v->l->sum + v->r->sum) % mod;
  }
  void update(int li, int ri, line f) { update(root, 1, n, li, ri, f); }
  int get() {
    creatend(root);
    push(root, 1, n);
    return root->sum;
  }
};
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  segtree t;
  t.update(1, a[0] + 1, {0, 1});
  for (int i = 1; i < n; ++i) {
    int sum = t.get();
    t.update(1, a[i] + 1, {-1, sum});
    t.update(a[i] + 1, t.n, {0, 0});
  }
  cout << t.get();
}
