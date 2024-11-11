#include <bits/stdc++.h>
using namespace std;
class segtree {
 public:
  struct node {
    int pre[2] = {0, 0};
    int suf[2] = {0, 0};
    int ans[2] = {0, 0};
    int segL = 0;
    bool lazyVal = false;
    void apply(int l, int r) {
      swap(pre[0], pre[1]);
      swap(suf[0], suf[1]);
      swap(ans[0], ans[1]);
      lazyVal = !lazyVal;
    }
    void apply(int l, int r, char v) {
      segL = 1;
      if (v == '>') {
        pre[0] = 1, pre[1] = -1;
        suf[0] = 1, suf[1] = -1;
      } else {
        pre[0] = -1, pre[1] = 1;
        suf[0] = -1, suf[1] = 1;
      }
      ans[0] = ans[1] = 1;
    }
    void PR() {
      cout << "node: " << pre[0] << " " << pre[1] << " " << suf[0] << " "
           << suf[1] << " " << ans[0] << " " << ans[1] << " " << segL << endl;
    }
  };
  bool sameSign(const int a, const int b) const { return (a > 0) == (b > 0); }
  bool absEq(const int a, const int b) const { return abs(a) == abs(b); }
  node unite(const node &a, const node &b) const {
    node res{};
    if (a.segL == 0) return b;
    if (b.segL == 0) return a;
    res.segL = a.segL + b.segL;
    for (int i : {0, 1}) {
      res.pre[i] = a.pre[i];
      if (a.pre[i] > 0) {
        if (absEq(a.segL, a.pre[i]) && (a.suf[i] == a.segL || b.pre[i] < 0))
          res.pre[i] = a.pre[i] + abs(b.pre[i]);
      } else {
        if (absEq(a.segL, a.pre[i]) && sameSign(a.pre[i], b.pre[i])) {
          res.pre[i] = a.pre[i] + b.pre[i];
        }
      }
      res.suf[i] = b.suf[i];
      if (b.suf[i] < 0) {
        if (absEq(b.segL, b.suf[i]) && (-b.pre[i] == b.segL || a.suf[i] > 0))
          res.suf[i] = -abs(a.suf[i]) + b.suf[i];
      } else {
        if (absEq(b.segL, b.suf[i]) && sameSign(a.suf[i], b.suf[i])) {
          res.suf[i] = a.suf[i] + b.suf[i];
        }
      }
      res.ans[i] = max(a.ans[i], b.ans[i]);
      if (a.suf[i] > 0 || b.pre[i] < 0)
        res.ans[i] = max(res.ans[i], abs(a.suf[i]) + abs(b.pre[i]));
    }
    return res;
  }
  inline void push(int x, int l, int r) {
    int mid = (l + r) >> 1;
    if (!tree[x].lazyVal) return;
    if (l != r) {
      tree[2 * x].apply(l, mid);
      tree[2 * x + 1].apply(mid + 1, r);
    }
    tree[x].lazyVal = false;
  }
  inline void pull(int x) { tree[x] = unite(tree[2 * x], tree[2 * x + 1]); }
  int n;
  vector<node> tree;
  void build(int x, int l, int r, const string &v) {
    if (l == r) {
      tree[x].apply(l, r, v[l]);
      return;
    }
    int mid = (l + r) >> 1;
    build(2 * x, l, mid, v);
    build(2 * x + 1, mid + 1, r, v);
    pull(x);
  }
  segtree(const string &v) {
    n = v.length();
    assert(n > 0);
    tree.resize(4 * n);
    build(1, 0, n - 1, v);
  }
  node get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return get(1, 0, n - 1, ll, rr);
  }
  template <typename... M>
  void modify(int ll, int rr, const M &...v) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    modify(1, 0, n - 1, ll, rr, v...);
  }

 private:
  node get(int x, int l, int r, int ll, int rr) {
    node res{};
    if (ll > r || l > rr) return res;
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int mid = (l + r) >> 1;
    push(x, l, r);
    res = unite(get(2 * x, l, mid, ll, rr), get(2 * x + 1, mid + 1, r, ll, rr));
    pull(x);
    return res;
  }
  template <typename... M>
  void modify(int x, int l, int r, int ll, int rr, const M &...v) {
    if (ll > r || l > rr) return;
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
      return;
    }
    int mid = (l + r) >> 1;
    push(x, l, r);
    modify(2 * x, l, mid, ll, rr, v...);
    modify(2 * x + 1, mid + 1, r, ll, rr, v...);
    pull(x);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  if (fopen("input.in", "r")) {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
  }
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  segtree st(s);
  for (int i = 0, l, r; i < q; i++) {
    cin >> l >> r;
    l--, r--;
    st.modify(l, r);
    cout << st.get(l, r).ans[0] << "\n";
  }
}
