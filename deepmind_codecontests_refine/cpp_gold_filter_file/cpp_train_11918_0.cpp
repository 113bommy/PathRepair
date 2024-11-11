#include <bits/stdc++.h>
using namespace std;
const pair<long long, pair<int, int>> def = {0, {-1, -1}};
int n, sz;
vector<pair<long long, pair<int, int>>> tree;
vector<int> start, _end, height;
vector<long long> dist;
void init(int sz) {
  n = 1;
  while (n < sz) n *= 2;
  tree.resize(2 * n, def);
  start.resize(2 * n);
  _end.resize(2 * n);
  dist.resize(sz + 1);
  dist[0] = 0;
  height.resize(sz);
  for (int i = 1; i <= sz; ++i) {
    int di;
    cin >> di;
    dist[i] = di;
    dist[i] += dist[i - 1];
  }
  for (int i = 0; i < sz; ++i) {
    cin >> height[i];
    tree[i + n] = {2 * height[i], {i, i}};
  }
}
long long eval(int fi, int se, int type) {
  long long d;
  if (fi > se) swap(fi, se);
  if (type == 1)
    d = dist[se] - dist[fi];
  else
    d = dist[fi] + dist[sz - 1] - dist[se] + dist[sz] - dist[sz - 1];
  d += 2 * height[fi];
  d += 2 * height[se];
  return d;
}
pair<long long, pair<int, int>> combine(pair<long long, pair<int, int>> l,
                                        pair<long long, pair<int, int>> r,
                                        int type) {
  if (l == def) return r;
  if (r == def) return l;
  pair<long long, pair<int, int>> max_E;
  if (l > r)
    max_E = l;
  else
    max_E = r;
  vector<int> fi = {l.second.first, l.second.second};
  vector<int> se = {r.second.first, r.second.second};
  for (int i : fi) {
    for (int j : se) {
      long long res = eval(i, j, type);
      if (res > max_E.first) max_E = {res, {i, j}};
    }
  }
  return max_E;
}
void build() {
  for (int i = 0; i < n; ++i) {
    start[i + n] = i;
    _end[i + n] = i + 1;
  }
  for (int i = n - 1; i > 0; --i) {
    int l = 2 * i;
    int r = 2 * i + 1;
    start[i] = start[l];
    _end[i] = _end[r];
    tree[i] = combine(tree[l], tree[r], 1);
  }
}
pair<long long, pair<int, int>> max_segment(int l, int r, int type, int v = 1) {
  if (l >= _end[v] || r <= start[v]) return def;
  if (l <= start[v] && r >= _end[v]) return tree[v];
  return combine(max_segment(l, r, type, 2 * v),
                 max_segment(l, r, type, 2 * v + 1), type);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m;
  cin >> sz >> m;
  init(sz);
  build();
  while (m--) {
    int ai, bi;
    pair<long long, pair<int, int>> ans;
    cin >> ai >> bi;
    ai--;
    bi--;
    if (bi < ai)
      ans = max_segment(bi + 1, ai, 1);
    else {
      pair<long long, pair<int, int>> fi = max_segment(0, ai, 1);
      pair<long long, pair<int, int>> se = max_segment(bi + 1, sz, 1);
      ans = combine(fi, se, 2);
    }
    cout << ans.first << endl;
  }
}
