#include <bits/stdc++.h>
using namespace std;
struct event {
  int x, y1, y2, d;
  bool operator<(const event &a) const {
    return tuple<int, int>(x, d) < tuple<int, int>(a.x, a.d);
  }
};
struct seg_tree {
  vector<int> st, lazy;
  seg_tree(int n) : st(4 * n), lazy(4 * n) {}
  void update(int cur, int b, int e, int l, int h, int d) {
    if (l <= b && e <= h) {
      st[cur] += d;
      lazy[cur] += d;
      return;
    }
    st[cur << 1] += lazy[cur];
    st[cur << 1 | 1] += lazy[cur];
    lazy[cur << 1] += lazy[cur];
    lazy[cur << 1 | 1] += lazy[cur];
    lazy[cur] = 0;
    int m = (b + e) >> 1;
    if (l < m) update(cur << 1, b, m, l, h, d);
    if (m < h) update(cur << 1 | 1, m, e, l, h, d);
    st[cur] = min(st[cur << 1], st[cur << 1 | 1]);
  }
};
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int>> f(k);
  for (auto &i : f) cin >> i.first >> i.second;
  function<int(int)> sweep = [&](int t) {
    vector<event> e;
    vector<int> ys;
    for (auto i : f) {
      int x1 = max(i.first - t, 1), x2 = min(i.first + t, n),
          y1 = max(i.second - t, 1), y2 = min(i.second + t, m);
      e.push_back({x1, y1, y2, 1});
      for (int j = -1; j <= 1; ++j) ys.push_back(y1 + j), ys.push_back(y2 + j);
      if (x2 < n) e.push_back({x2 + 1, y1, y2, -1});
    }
    sort(e.begin(), e.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    int id = 0;
    map<int, int> mp;
    for (auto i : ys)
      if (1 <= i && i <= m) mp[i] = ++id;
    if (e[0].x != 1) return 1;
    int sz = e.size();
    seg_tree st(id);
    for (int i = 0; i < sz;) {
      int v = e[i].x;
      while (i < sz && e[i].x == v)
        st.update(1, 1, id + 1, mp[e[i].y1], mp[e[i].y2] + 1, e[i].d), ++i;
      if (st.st[1] == 0) return e[i - 1].x;
    }
    return -1;
  };
  function<bool(int)> burn = [&](int t) {
    vector<int> dist;
    for (int r = 4; r--;) {
      dist.push_back(sweep(t));
      for (auto &i : f) i = {i.second, n - i.first + 1};
      swap(n, m);
    }
    return dist[0] == -1 || max(n - dist[0] + 1 - dist[2] + 1,
                                m - dist[1] + 1 - dist[3] + 1) <= 2 * t + 1;
  };
  int b = 0, e = 1e9;
  while (b < e) {
    int m = (b + e) >> 1;
    if (burn(m))
      e = m;
    else
      b = m + 1;
  }
  cout << b << "\n";
  return 0;
}
