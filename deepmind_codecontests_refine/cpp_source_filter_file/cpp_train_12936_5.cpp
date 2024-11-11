#include <bits/stdc++.h>
using namespace std;
inline int add(int _a, int _b) {
  if (_a < 0) {
    _a += 1000000007;
  }
  if (_b < 0) {
    _b += 1000000007;
  }
  if (_a + _b >= 1000000007) {
    return _a + _b - 1000000007;
  }
  return _a + _b;
}
inline int mul(int _a, int _b) {
  if (_a < 0) {
    _a += 1000000007;
  }
  if (_b < 0) {
    _b += 1000000007;
  }
  return ((long long int)((long long int)_a * (long long int)_b)) % 1000000007;
}
const int N = 2e5;
vector<pair<int, int> > seg[2];
int tree[2][4 * N + 10], lz[2][4 * N + 10];
int n;
void mrg(int idx, int iter) {
  tree[idx][iter] = max(tree[idx][2 * iter + 1], tree[idx][2 * iter + 2]);
}
void make_tree(int idx, int lo, int hi, int iter) {
  int mid = (lo + hi) >> 1;
  tree[idx][iter] = -INT_MAX, lz[idx][iter] = 0;
  if (lo == hi) {
    if (lo == 0) tree[idx][iter] = 0;
  } else if (lo < hi) {
    make_tree(idx, lo, mid, 2 * iter + 1);
    make_tree(idx, mid + 1, hi, 2 * iter + 2);
    mrg(idx, iter);
  }
}
void lazy_up(int idx, int iter, int val) {
  lz[idx][iter] += val;
  tree[idx][iter] += val;
}
void push_down(int idx, int iter) {
  lazy_up(idx, 2 * iter + 1, lz[idx][iter]);
  lazy_up(idx, 2 * iter + 1, lz[idx][iter]);
  lz[idx][iter] = 0;
}
void update(int idx, int lo, int hi, int iter, int l, int r, int val) {
  int mid = (lo + hi) >> 1;
  if (l > r) return;
  if (l <= lo && r >= hi) {
    lazy_up(idx, iter, val);
    return;
  } else if (l > hi || r < lo)
    return;
  else {
    push_down(idx, iter);
    update(idx, lo, mid, 2 * iter + 1, l, r, val);
    update(idx, mid + 1, hi, 2 * iter + 2, l, r, val);
    mrg(idx, iter);
  }
}
void replace(int idx, int lo, int hi, int iter, int pos, int val) {
  int mid = (lo + hi) >> 1;
  if (lo == hi) {
    tree[idx][iter] = val;
    return;
  }
  push_down(idx, iter);
  if (pos >= lo && pos <= mid)
    replace(idx, lo, mid, 2 * iter + 1, pos, val);
  else
    replace(idx, mid + 1, hi, 2 * iter + 2, pos, val);
  mrg(idx, iter);
}
int query(int idx, int lo, int hi, int iter, int l, int r) {
  int mid = (lo + hi) >> 1;
  if (l <= lo && r >= hi)
    return tree[idx][iter];
  else if (l > hi || r < lo)
    return -INT_MAX;
  else {
    push_down(idx, iter);
    int L = query(idx, lo, mid, 2 * iter + 1, l, r);
    int R = query(idx, mid + 1, hi, 2 * iter + 2, l, r);
    mrg(idx, iter);
    return max(L, R);
  }
}
bool cmp(pair<int, int> lhs, pair<int, int> rhs) {
  if (lhs.first == rhs.first) return lhs.second < rhs.second;
  return lhs.first < rhs.first;
}
void solve() {
  int i, j, ans = 0;
  make_tree(0, 0, (int)seg[0].size() - 1, 0);
  make_tree(1, 0, (int)seg[1].size() - 1, 0);
  for (i = j = 1; i < seg[0].size() || j < seg[1].size();) {
    if (i == seg[0].size() ||
        (j < seg[1].size() && cmp(seg[1][j], seg[0][i]))) {
      int idx = upper_bound(seg[0].begin(), seg[0].end(),
                            make_pair(seg[1][j].second - 1, +INT_MAX)) -
                seg[0].begin();
      --idx;
      int val = query(0, 0, (int)seg[0].size() - 1, 0, 0, idx) + 1;
      ans = max(ans, val);
      update(0, 0, (int)seg[0].size() - 1, 0, 0, idx, 1);
      replace(1, 0, (int)seg[1].size() - 1, 0, j, val);
      ++j;
    } else {
      int idx = upper_bound(seg[1].begin(), seg[1].end(),
                            make_pair(seg[0][i].second - 1, +INT_MAX)) -
                seg[1].begin();
      --idx;
      int val = query(1, 0, (int)seg[1].size() - 1, 0, 0, idx) + 1;
      ans = max(ans, val);
      update(1, 0, (int)seg[1].size() - 1, 0, 0, idx, 1);
      replace(0, 0, (int)seg[0].size() - 1, 0, i, val);
      ++i;
    }
  }
  printf("%d", ans), puts("");
}
int main() {
  int i, j;
  scanf("%d", &n);
  seg[0].push_back(make_pair(-INT_MAX, -INT_MAX));
  seg[1].push_back(make_pair(-INT_MAX, -INT_MAX));
  for (i = 0; i < n; i++) {
    int l, r, t;
    scanf("%d %d %d", &l, &r, &t);
    seg[t - 1].push_back(make_pair(r, l));
  }
  sort(seg[0].begin(), seg[0].end(), cmp);
  sort(seg[1].begin(), seg[1].end(), cmp);
  solve();
}
