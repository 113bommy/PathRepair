#include <bits/stdc++.h>
using namespace std;
struct iii {
  int first, second, T;
};
struct DS {
  vector<int> p, c, r;
  int n;
  DS(int n) : n(n), p(n), c(n), r(n) { clear(); }
  void clear() {
    for (int i = 0; i < n; i++) p[i] = i, c[i] = 1, r[i] = 0;
  }
  pair<int, int> SetOf(int x) {
    int y = 0;
    while (p[x] != x) {
      y += r[x];
      x = p[x];
    }
    return {x, y % 2};
  }
  int Merge(int x, int y) {
    pair<int, int> tx = SetOf(x);
    pair<int, int> ty = SetOf(y);
    if (tx.first == ty.first) {
      if (tx.second != ty.second)
        return 2;
      else
        return 1;
    }
    if (c[tx.first] > c[ty.first]) swap(tx, ty);
    r[tx.first] = 1 - (tx.second + ty.second + 1) % 2;
    p[tx.first] = ty.first;
    c[ty.first] += c[tx.first];
    return 0;
  }
};
struct segment_tree {
  vector<vector<iii>> st;
  DS ds;
  int n;
  segment_tree(int n, int m, vector<iii> &e) : n(n), st(2 * n), ds(m) {
    build(0, n, e);
  }
  inline int id(int b, int e) { return (b + e - 1) | (b != e - 1); }
  void build(int l, int r, vector<iii> &e) {
    int cur = id(l, r);
    vector<iii> t;
    for (int i = l; i < r; i++) t.push_back(e[i]);
    sort(t.begin(), t.end(), [](iii x, iii y) { return x.T > y.T; });
    ds.clear();
    for (auto i : t) {
      int x = ds.Merge(i.first, i.second);
      if (x <= 1) st[cur].push_back(i);
      if (x == 1) break;
    }
    if (l + 1 == r) return;
    int mid = (l + r + 1) >> 1;
    build(l, mid, e);
    build(mid, r, e);
  }
  vector<iii> query(int l, int r, int li, int ri) {
    int cur = id(l, r);
    if (l >= ri || r <= li) return {};
    if (li <= l && r <= ri) return st[cur];
    int mid = (l + r + 1) >> 1;
    vector<iii> ret;
    for (auto i : query(l, mid, li, ri)) ret.push_back(i);
    for (auto i : query(mid, r, li, ri)) ret.push_back(i);
    return ret;
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<iii> e(m);
  for (auto &i : e) cin >> i.first >> i.second >> i.T, --i.first, --i.second;
  DS ds(n);
  segment_tree st(m, n, e);
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l;
    auto t = st.query(0, m, l, r);
    sort(t.begin(), t.end(), [](iii x, iii y) { return x.T > y.T; });
    int ans = -1;
    for (auto i : t)
      if (ds.Merge(i.first, i.second) == 1) {
        ans = i.T;
        break;
      }
    cout << ans << '\n';
    ds.clear();
  }
  return 0;
}
