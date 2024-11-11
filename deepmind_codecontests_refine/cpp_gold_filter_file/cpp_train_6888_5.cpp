#include <bits/stdc++.h>
using namespace std;
struct Edge {
  Edge() = default;
  Edge(int x, int y, int z) : u(x), v(y), val(z) {}
  int u, v;
  int val;
};
vector<vector<int>> g;
vector<Edge> ed;
vector<bool> used;
int dfs(int v) {
  used[v] = true;
  int ans;
  if (g[v].size() == 1) {
    used[v] = false;
    return v;
  } else {
    for (auto i : g[v]) {
      if (!used[i]) {
        ans = dfs(i);
        used[v] = false;
        return ans;
      }
    }
  }
}
pair<pair<int, int>, pair<int, int>> Smart_dfs(int u, int v) {
  set<int> eu;
  set<int> ev;
  pair<pair<int, int>, pair<int, int>> ans;
  used[u] = true;
  used[v] = true;
  if (g[u].size() == 1) {
    eu.insert(u);
    eu.insert(u);
  } else {
    for (auto &i : g[u]) {
      if (!used[i]) {
        eu.insert(dfs(i));
      }
    }
  }
  if (g[v].size() == 1) {
    ev.insert(v);
    ev.insert(v);
  } else {
    for (auto &i : g[v]) {
      if (!used[i]) {
        ev.insert(dfs(i));
      }
    }
  }
  used[u] = false;
  used[v] = false;
  ans.first.first = *begin(eu);
  if (eu.size() > 1) {
    ans.first.second = *next(begin(eu));
  } else {
    ans.first.second = *begin(eu);
  }
  ans.second.first = *begin(ev);
  if (ev.size() > 1) {
    ans.second.second = *next(begin(ev));
  } else {
    ans.second.second = *begin(ev);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  g.resize(n + 1);
  ed.resize(n - 1);
  used.resize(n + 1, false);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, val;
    cin >> u >> v >> val;
    g[u].push_back(v);
    g[v].push_back(u);
    ed[i] = *new Edge(u, v, val);
  }
  for (int i = 1; i <= n; ++i) {
    if (g[i].size() == 2) {
      cout << "NO\n";
      return 0;
    }
  }
  vector<Edge> ans;
  for (auto &i : ed) {
    pair<pair<int, int>, pair<int, int>> cur = Smart_dfs(i.u, i.v);
    ans.push_back(*new Edge(cur.first.first, cur.second.first, i.val / 2));
    ans.push_back(*new Edge(cur.first.second, cur.second.second, i.val / 2));
    if (cur.first.first != cur.first.second) {
      ans.push_back(*new Edge(cur.first.first, cur.first.second, -i.val / 2));
    }
    if (cur.second.first != cur.second.second) {
      ans.push_back(*new Edge(cur.second.first, cur.second.second, -i.val / 2));
    }
  }
  cout << "YES\n" << ans.size() << "\n";
  for (auto &i : ans) {
    cout << i.u << ' ' << i.v << ' ' << i.val << "\n";
  }
  return 0;
}
