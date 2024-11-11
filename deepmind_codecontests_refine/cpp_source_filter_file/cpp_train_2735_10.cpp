#include <bits/stdc++.h>
using namespace std;
struct edge {
  int v, w;
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, sx, sy, tx, ty;
  cin >> m >> n >> sx >> sy >> tx >> ty;
  vector<int> xs(n + 2), ys(n + 2);
  for (int i = 1; i <= n; i++) cin >> xs[i] >> ys[i];
  xs[0] = sx;
  ys[0] = sy;
  xs[n + 1] = tx;
  ys[n + 1] = ty;
  n += 2;
  vector<int> id(n);
  vector<vector<edge>> e(n);
  iota(id.begin(), id.end(), 0);
  for (int i = 1; i < n - 1; i++) {
    int u = i, v = n - 1;
    int w = abs(xs[v] - xs[u]) + abs(ys[v] - ys[u]);
    e[u].push_back((edge){v, w});
    e[v].push_back((edge){u, w});
  }
  sort(id.begin(), id.begin() + n - 1, [&](int i, int j) {
    if (xs[i] == xs[j]) return ys[i] < ys[j];
    return xs[i] < xs[j];
  });
  for (int i = 0; i < n - 2; i++) {
    int u = id[i], v = id[i + 1];
    int w = min(abs(xs[v] - xs[u]), abs(ys[v] - ys[u]));
    e[u].push_back((edge){v, w});
    e[v].push_back((edge){u, w});
  }
  sort(id.begin(), id.begin() + n - 1, [&](int i, int j) {
    if (ys[i] == ys[j]) return xs[i] < xs[j];
    return ys[i] < ys[j];
  });
  for (int i = 0; i < n - 2; i++) {
    int u = id[i], v = id[i + 1];
    int w = min(abs(xs[v] - xs[u]), abs(ys[v] - ys[u]));
    e[u].push_back((edge){v, w});
    e[v].push_back((edge){u, w});
  }
  vector<int64_t> d(n, 1e18);
  d[0] = 0;
  priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>,
                 greater<pair<int64_t, int>>>
      q;
  q.emplace(0, 0);
  while (q.size()) {
    auto [w, u] = q.top();
    q.pop();
    if (d[u] < w) continue;
    for (auto t : e[u]) {
      int v = t.v;
      if (d[v] > d[u] + t.w) {
        d[v] = d[u] + t.w;
        q.emplace(d[v], v);
      }
    }
  }
  cout << d[n - 1] << '\n';
  return 0;
}
