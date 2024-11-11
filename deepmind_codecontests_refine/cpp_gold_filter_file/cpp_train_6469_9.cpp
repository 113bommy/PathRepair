#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5;
const int _N = 1 << 18;
const ll LL_INF = 1e18;
struct node {
  ll lazy, sum, min, max;
};
int n, q;
ll a[N], k[N];
node seg_tree[_N << 1];
ll k_sum_suff[N + 1];
void init_node(int i, ll val) { seg_tree[i] = {-LL_INF, val, val, val}; }
void merge_node(int i) {
  seg_tree[i].sum = seg_tree[i << 1].sum + seg_tree[i << 1 | 1].sum;
  seg_tree[i].min = seg_tree[i << 1].min;
  seg_tree[i].max = seg_tree[i << 1 | 1].max;
}
void init() {
  ll k_sum = 0LL;
  for (int i = n - 1; i >= 0; --i) {
    k_sum += k[i];
    k_sum_suff[i] = k_sum_suff[i + 1] + k_sum;
    init_node(_N + i, a[i] + k_sum);
  }
  for (int i = n; i < _N; ++i)
    seg_tree[_N + i] = {-LL_INF, 0LL, LL_INF, LL_INF};
  for (int i = _N - 1; i; --i) {
    seg_tree[i].lazy = -LL_INF;
    merge_node(i);
  }
}
void push_lazy(int i, int l, int r) {
  ll lazy = seg_tree[i].lazy;
  if (lazy == -LL_INF) return;
  seg_tree[i].sum = lazy * (r - l + 1);
  seg_tree[i].min = seg_tree[i].max = lazy;
  if (l != r) seg_tree[i << 1].lazy = seg_tree[i << 1 | 1].lazy = lazy;
  seg_tree[i].lazy = -LL_INF;
}
ll query(int l, int r, int sti = 1, int il = 0, int ir = _N - 1) {
  push_lazy(sti, il, ir);
  if (l > ir || r < il) return 0LL;
  if (il >= l && ir <= r) return seg_tree[sti].sum;
  ll res = query(l, r, sti << 1, il, (il + ir - 1) >> 1) +
           query(l, r, sti << 1 | 1, (il + ir + 1) >> 1, ir);
  merge_node(sti);
  return res;
}
int find_right(int left, ll val, int sti = 1, int il = 0, int ir = _N - 1) {
  push_lazy(sti, il, ir);
  if (ir <= left || seg_tree[sti].min > val) return left;
  if (seg_tree[sti].max <= val) return ir;
  int res = max(find_right(left, val, sti << 1, il, (il + ir - 1) >> 1),
                find_right(left, val, sti << 1 | 1, (il + ir + 1) >> 1, ir));
  merge_node(sti);
  return res;
}
void update(int l, int r, ll val, int sti = 1, int il = 0, int ir = _N - 1) {
  push_lazy(sti, il, ir);
  if (l > ir || r < il) return;
  if (il >= l && ir <= r) {
    seg_tree[sti].lazy = val;
    push_lazy(sti, il, ir);
    return;
  }
  update(l, r, val, sti << 1, il, (il + ir - 1) >> 1);
  update(l, r, val, sti << 1 | 1, (il + ir + 1) >> 1, ir);
  merge_node(sti);
}
void _update(int left, ll delta) {
  ll cur_val = query(left, left);
  int right = find_right(left, cur_val + delta);
  update(left, right, cur_val + delta);
}
ll _query(int left, int right) {
  return query(left, right) - (k_sum_suff[left] - k_sum_suff[right + 1]);
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n - 1; ++i) cin >> k[i];
  init();
  cin >> q;
  for (int i = 0; i < q; ++i) {
    char c;
    int x, y;
    cin >> c >> x >> y;
    if (c == '+') {
      _update(x - 1, y);
    } else {
      cout << _query(x - 1, y - 1) << "\n";
    }
  }
  return 0;
}
