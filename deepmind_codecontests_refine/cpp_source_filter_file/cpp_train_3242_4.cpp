#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, d;
  cin >> n >> m >> d;
  vector<int> adj1;
  vector<pair<int, int>> ps;
  int c = 0;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    ps.push_back({a, b});
    if (min(a, b) == 1) c++, adj1.push_back(max(a, b));
  }
  if (c < d) {
    cout << "NO\n";
    return;
  }
  vector<int> id(n + 2);
  iota(id.begin(), id.end(), 0);
  function<int(int)> Find = [&](int x) {
    return id[x] == x ? x : id[x] = Find(id[x]);
  };
  c = 0;
  set<int> g[n + 2];
  for (auto p : ps) {
    int a = Find(p.first);
    int b = Find(p.second);
    if (a != b) {
      if (min(p.first, p.second) == 1) {
        if (c == 0) {
          id[a] = id[b];
          g[p.first].insert(p.second);
          g[p.second].insert(p.first);
          c++;
        }
      } else {
        id[a] = id[b];
        g[p.first].insert(b);
        g[p.second].insert(p.first);
      }
    }
  }
  for (int x : adj1) {
    if (Find(x) != Find(1)) {
      id[Find(x)] = id[Find(1)];
      g[x].insert(1);
      g[1].insert(x);
      c++;
    }
  }
  if (c > d) {
    cout << "NO\n";
    return;
  }
  if (c < d) {
    for (int x : adj1) {
      if (c == d) break;
      if (g[1].find(x) == g[1].end()) {
        g[1].insert(x);
        c++;
      }
    }
  }
  vector<pair<int, int>> ans;
  vector<bool> vis(n + 2, 0);
  auto bfs = [&](int x) {
    queue<int> Q;
    Q.push(x);
    vis[x] = 1;
    while (!Q.empty()) {
      int f = Q.front();
      Q.pop();
      for (int x : g[f]) {
        if (vis[x] == false) {
          vis[x] = true;
          Q.push(x);
          ans.push_back({f, x});
        }
      }
    }
  };
  bfs(1);
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      cout << "NO\n";
      return;
    }
  }
  if (ans.size() != n - 1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (auto x : ans) {
    cout << x.first << ' ' << x.second << "\n";
  }
  return;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
