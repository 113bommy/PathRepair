#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
void make_unique(T& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
int geti() {
  int x;
  cin >> x;
  return x;
}
long long getll() {
  long long x;
  cin >> x;
  return x;
}
double getd() {
  double x;
  cin >> x;
  return x;
}
const int MAXN = 3e5 + 100;
struct fenwick_tree {
  using dtype = int;
  int n;
  dtype tree[MAXN] = {}, a[MAXN] = {};
  inline int lowbit(int x) { return x & -x; }
  dtype& operator[](int idx) { return a[idx]; }
  void build(int _n) {
    n = _n;
    for (int i = 1; i <= n; i++) tree[i] = a[i] + tree[i - 1];
    for (int i = n; i >= 1; i--) tree[i] -= tree[lowbit(i)];
  }
  void add(int i, dtype val) {
    a[i] += val;
    for (; i <= n; i += lowbit(i)) tree[i] += val;
  }
  dtype get(int i) {
    dtype res = 0;
    for (; i > 0; i -= lowbit(i)) res += tree[i];
    return res;
  }
  dtype get(int i, int j) { return get(j) - get(i - 1); }
  int lower_bound(dtype target) {
    int sum = 0, res = 0, bit = 1;
    while (bit <= n) bit <<= 1;
    for (bit >>= 1; bit; bit >>= 1) {
      if (res + bit <= n && sum + tree[res + bit] < target) {
        sum += tree[res + bit];
        res += bit;
      }
    }
    return res + (sum < target);
  }
  void add_range(int i, int j, dtype val) {
    add(i, val);
    add(j + 1, dtype(0) - val);
  }
  dtype get_element(int i) { return get(i); }
};
fenwick_tree ft;
struct segment_tree {
  using dtype = int;
  int _l, _r, _n;
  function<dtype(dtype, dtype)> op;
  dtype _null_val;
  dtype a[MAXN] = {}, tree[MAXN] = {}, lazy[MAXN] = {};
  segment_tree(function<dtype(dtype, dtype)> _op, dtype null_val) : op(_op) {
    _null_val = null_val;
  }
  void push(int l, int r, int node) {
    int mid = (l + r) / 2;
    int rnode = node + (mid - l + 1) * 2;
    if (lazy[node] != 0) {
      tree[node + 1] += lazy[node];
      lazy[node + 1] += lazy[node];
      tree[rnode] += lazy[node];
      lazy[rnode] += lazy[node];
      lazy[node] = 0;
    }
  }
  void build(int l, int r, int node) {
    if (l == r)
      tree[node] = a[l];
    else {
      int mid = l + (r - l) / 2;
      int rnode = node + (mid - l + 1) * 2;
      build(l, mid, node + 1);
      build(mid + 1, r, rnode);
      tree[node] = op(tree[node + 1], tree[rnode]);
    }
  }
  void update(dtype v, int left, int right, int l, int r, int node) {
    if (left > right) return;
    if (right < l || r < left) return;
    if (left <= l && r <= right) {
      tree[node] += v;
      lazy[node] += v;
    } else {
      push(l, r, node);
      int mid = l + (r - l) / 2;
      int rnode = node + (mid - l + 1) * 2;
      update(v, left, right, l, mid, node + 1);
      update(v, left, right, mid + 1, r, rnode);
      tree[node] = op(tree[node + 1], tree[rnode]);
    }
  }
  dtype query(int left, int right, int l, int r, int node) {
    if (left > right) return _null_val;
    if (right < l || r < left) return _null_val;
    if (left <= l && r <= right) return tree[node];
    push(l, r, node);
    int mid = l + (r - l) / 2;
    int rnode = node + (mid - l + 1) * 2;
    dtype r1 = query(left, right, l, mid, node + 1);
    dtype r2 = query(left, right, mid + 1, r, rnode);
    return op(r1, r2);
  }
  inline bool lower_bound_valid(int val, int target) { return val < target; }
  int lower_bound(int target, int l, int r, int node) {
    if (!lower_bound_valid(tree[node], target)) return r + 1;
    while (l < r) {
      push(l, r, node);
      int mid = l + (r - l) / 2;
      int rnode = node + (mid - l + 1) * 2;
      if (lower_bound_valid(tree[node + 1], target)) {
        r = mid;
        node++;
      } else {
        l = mid + 1;
        node = rnode;
      }
    }
    return l;
  }
  void set(int l, int r) {
    _l = l;
    _r = r;
    _n = r - l + 1;
  }
  dtype& operator[](int idx) { return a[idx]; }
  void build() { build(_l, _r, 0); }
  void update(dtype v, int left, int right) {
    return update(v, left, right, _l, _r, 0);
  }
  dtype query(int left, int right) { return query(left, right, _l, _r, 0); }
  int lower_bound(dtype target) { return lower_bound(target, _l, _r, 0); }
};
segment_tree segt([](int a, int b) { return min(a, b); }, int(1e6));
void solve(int tt) {}
int a[MAXN];
int extra[MAXN];
int valid[MAXN];
vector<int> inputs[MAXN];
int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, q;
  cin >> n >> q;
  for (auto i = (1); i < (n + 1); i++) cin >> a[i];
  int cur = 0;
  fill(extra, extra + n + 1, 1e6);
  fill(valid, valid + n + 1, 0);
  ft.build(n);
  for (auto i = (1); i < (n + 1); i++) {
    if (i < a[i]) continue;
    int need = i - a[i];
    if (need <= cur) {
      extra[i] = cur - need;
      valid[i] = 1;
      ft.add(i, 1);
      cur++;
    }
  }
  segt.set(1, n);
  for (auto i = (1); i < (n + 1); i++) segt[i] = extra[i];
  segt.build();
  for (auto qq = (0); qq < (q); qq++) {
    inputs[qq] = vector<int>(4);
    inputs[qq][0] = qq;
    cin >> inputs[qq][1] >> inputs[qq][2];
  }
  sort(inputs, inputs + q,
       [](const vector<int>& x, const vector<int>& y) { return x[1] < y[1]; });
  int pos = 1;
  for (auto qq = (0); qq < (q); qq++) {
    for (; pos <= inputs[qq][1]; pos++) {
      if (!valid[pos] || segt.query(pos, pos) > 0) continue;
      int pp = pos;
      while (pp <= n) {
        segt.update(1e6, pp, pp);
        segt.update(-1, pp + 1, n);
        ft.add(pp, -1);
        valid[pp] = 0;
        int lo = segt.lower_bound(0);
        assert(lo > pp);
        pp = lo;
      }
    }
    inputs[qq][3] = ft.get(inputs[qq][1] + 1, n - inputs[qq][2]);
  }
  sort(inputs, inputs + q,
       [](const vector<int>& x, const vector<int>& y) { return x[0] < y[0]; });
  for (auto qq = (0); qq < (q); qq++) {
    cout << inputs[qq][3] << endl;
  }
  return 0;
}
