#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic ignored "-Wmissing-declarations"
int const maxn = 100005;
long long tree[maxn * 4];
long long a[maxn];
int sz = 1;
pair<long long, int> tree_max[maxn * 4];
pair<long long, int> tree_max2[maxn * 4];
void build(const int n) {
  while (sz <= n) sz <<= 1;
  for (int i = 1; i <= n; ++i) tree[sz + i] = a[i];
  for (int i = 0; i < maxn; ++i)
    tree_max[i] = tree_max2[i] = {numeric_limits<long long>::min(), i - sz};
  for (int i = 2; i < n; ++i) {
    if (a[i] < a[i + 1] && a[i] < a[i - 1]) {
      tree_max2[sz + i] = {-a[i - 1] - a[i + 1] + a[i] + a[i], i};
    } else if (a[i] < a[i + 1] || a[i] < a[i - 1]) {
      long long d = a[i] - max(a[i - 1], a[i + 1]);
      tree_max[sz + i] = {d, i};
    } else {
      tree_max[sz + i] = {0, i};
    }
  }
  for (int i = sz - 1; i > 0; --i)
    tree_max[i] = max(tree_max[2 * i], tree_max[2 * i + 1]);
  for (int i = sz - 1; i > 0; --i)
    tree_max2[i] = max(tree_max2[2 * i], tree_max2[2 * i + 1]);
}
inline void upd(int l, int r, const long long x) {
  for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
    if (l & 1) tree[l++] += x;
    if (~r & 1) tree[r--] += x;
  }
}
inline long long get(int ind) {
  long long res = 0;
  for (ind += sz; ind > 0; ind >>= 1) res += tree[ind];
  return res;
}
inline void upd_max(int ind, long long val) {
  const int cind = ind;
  for (tree_max[ind += sz] = {val, cind}; ind > 1; ind >>= 1)
    tree_max[ind >> 1] = max(tree_max[ind], tree_max[ind ^ 1]);
}
inline void upd_max2(int ind, long long val) {
  const int cind = ind;
  for (tree_max2[ind += sz] = {val, cind}; ind > 1; ind >>= 1)
    tree_max2[ind >> 1] = max(tree_max2[ind], tree_max2[ind ^ 1]);
}
inline pair<int, int> get_max(int l, int r) {
  const int cl = l;
  const int cr = r;
  pair<long long, int> res = {numeric_limits<long long>::min(), -1};
  for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
    if (l & 1) res = std::max(res, tree_max[l++]);
    if (~r & 1) res = std::max(res, tree_max[r--]);
  }
  pair<long long, int> res2 = {numeric_limits<long long>::min(), -1};
  for (l = cl + sz, r = cr + sz; l <= r; l >>= 1, r >>= 1) {
    if (l & 1) res2 = std::max(res2, tree_max2[l++]);
    if (~r & 1) res2 = std::max(res2, tree_max2[r--]);
  }
  return {res.second, res2.second};
}
int n;
inline void addv(int ind) {
  if (ind > 1 && ind < n) {
    long long cur = 0;
    long long x = get(ind - 1);
    long long y = get(ind);
    long long z = get(ind + 1);
    int cnt = 0;
    if (y < x) cur += y - x, ++cnt;
    if (y < z) cur += y - z, ++cnt;
    if (cnt < 2) {
      upd_max(ind, cur);
      upd_max2(ind, numeric_limits<long long>::min());
    } else {
      upd_max(ind, numeric_limits<long long>::min());
      upd_max2(ind, cur);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  build(n);
  long long res = 0;
  for (int i = 2; i <= n; ++i) res += abs(a[i] - a[i - 1]);
  stringstream ss;
  int q;
  cin >> q;
  while (q--) {
    int t, l, r, x;
    cin >> t >> l >> r >> x;
    if (t == 1) {
      long long ans = numeric_limits<long long>::min();
      if (l <= r) {
        auto p = get_max(l, r);
        if (p.second > 0) {
          long long v1 = get(p.second);
          long long v2 = get(p.second - 1);
          long long v3 = get(p.second + 1);
          long long tmp = res - abs(v1 - v2) - abs(v1 - v3);
          tmp += abs(v1 + x - v2) + abs(v1 + x - v3);
          ans = max(ans, tmp);
        }
        if (p.first > 0) {
          long long v1 = get(p.first);
          long long v2 = get(p.first - 1);
          long long v3 = get(p.first + 1);
          long long tmp = res - abs(v1 - v2) - abs(v1 - v3);
          tmp += abs(v1 + x - v2) + abs(v1 + x - v3);
          ans = max(ans, tmp);
        }
      }
      ss << ans << '\n';
    } else {
      if (l > 1) res -= abs(get(l) - get(l - 1));
      if (r < n) res -= abs(get(r + 1) - get(r));
      upd(l, r, x);
      addv(l - 1);
      addv(l);
      if (r > l) addv(r);
      addv(r + 1);
      if (l > 1) res += abs(get(l) - get(l - 1));
      if (r < n) res += abs(get(r + 1) - get(r));
    }
  }
  cout << ss.str();
}
