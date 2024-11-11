#include <bits/stdc++.h>
using namespace std;
const int dr[]{-1, -1, 0, 1, 1, 1, 0, -1};
const int dc[]{0, 1, 1, 1, 0, -1, -1, -1};
void run() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
const int MOD = 998244353;
struct modint {
  int val;
  modint() { val = 0; }
  modint(const long long &a) {
    val = a % MOD;
    if (val < 0) val += MOD;
  }
  modint &operator+=(const modint &a) {
    if ((val += a.val) >= MOD) val -= MOD;
    return (*this);
  }
  modint operator+(const modint &a) const {
    modint c = (*this);
    c += a;
    return c;
  }
  modint &operator-=(const modint &a) {
    if ((val -= a.val) < 0) val += MOD;
    return (*this);
  }
  modint operator-(const modint &a) const {
    modint c = (*this);
    c -= a;
    return c;
  }
  modint operator*(const modint &a) const {
    return modint(1LL * this->val * a.val);
  }
  modint &operator*=(const modint &a) {
    (*this) = (*this) * a;
    return (*this);
  }
  modint operator/(const modint &a) { return (*this) * power(a, MOD - 2); }
  modint &operator/=(const modint &a) {
    (*this) = (*this) / a;
    return (*this);
  }
  static modint power(modint x, long long y) {
    modint res = 1;
    while (y > 0) {
      if (y & 1) res *= x;
      x *= x;
      y >>= 1;
    }
    return res;
  }
  friend ostream &operator<<(ostream &out, const modint &a) {
    out << a.val;
    return out;
  }
};
struct segtree {
  segtree *left = nullptr, *right = nullptr;
  modint sum = 0, lazy = 0, sign = 1;
  segtree() {}
  void extend() {
    if (left == nullptr) {
      left = new segtree();
      right = new segtree();
    }
  }
  void pushdown(int start, int end) {
    if (lazy.val == 0 && sign.val == 1) return;
    sum = lazy * (end - start + 1) + sign * sum;
    if (start != end) {
      extend();
      left->sign *= sign;
      left->lazy = lazy - sign * left->lazy;
      right->sign *= sign;
      right->lazy = lazy - sign * right->lazy;
    }
    lazy = 0;
    sign = 1;
  }
  void pushup() { sum = left->sum + right->sum; }
  ~segtree() {
    if (left == nullptr) return;
    delete left;
    delete right;
  }
};
class extened_segment_tree {
  void update(segtree *root, int start, int end, int l, int r, int sign,
              int val) {
    root->pushdown(start, end);
    if (r < start || end < l) return;
    if (l <= start && end <= r) {
      root->sign = sign;
      root->lazy = val;
      root->pushdown(start, end);
      return;
    }
    root->extend();
    update(root->left, start, ((start + end) >> 1), l, r, sign, val);
    update(root->right, ((start + end) >> 1) + 1, end, l, r, sign, val);
    root->pushup();
  }

 public:
  int start, end;
  segtree *root;
  extened_segment_tree() {}
  extened_segment_tree(int start, int end) : start(start), end(end) {
    root = new segtree();
  }
  void update(int l, int r, int sign, int val) {
    update(root, start, end, l, r, sign, val);
  }
  int query() {
    root->pushdown(start, end);
    return root->sum.val;
  }
};
const int N = 1e9;
int main() {
  run();
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &it : a) cin >> it;
  extened_segment_tree seg(1, N);
  seg.update(1, a[0], 1, 1);
  for (int i = 1; i < n; i++) {
    int sum = seg.query();
    seg.update(1, a[i], -1, sum);
    seg.update(a[i] + 1, N, 0, 0);
  }
  cout << seg.query() << "\n";
}
