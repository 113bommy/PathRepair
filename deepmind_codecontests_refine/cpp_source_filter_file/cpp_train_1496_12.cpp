#include <bits/stdc++.h>
using namespace std;
int num[1000009], low[1000009], scc[1000009], n, m, cnt, t;
vector<vector<int> > adj;
stack<int> s;
void add(int x, int sx, int y, int sy) {
  x = x << 1 ^ sx;
  y = y << 1 ^ sy;
  adj[x ^ 1].push_back(y);
  adj[y ^ 1].push_back(x);
}
void dfs(int u) {
  num[u] = low[u] = ++cnt;
  s.push(u);
  for (int v : adj[u])
    if (num[v])
      low[u] = min(low[u], num[v]);
    else {
      dfs(v);
      low[u] = min(low[v], low[u]);
    }
  if (num[u] == low[u]) {
    int v = INT_MAX;
    t++;
    do {
      v = s.top();
      s.pop();
      scc[v] = t;
      num[v] = low[v] = INT_MAX;
    } while (v != u);
  }
}
vector<int> solve() {
  for (int i = 0; i < adj.size(); i++)
    if (!num[i]) dfs(i);
  int n = adj.size() / 2;
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    if (scc[i << 1 ^ false] == scc[i << 1 ^ true])
      return vector<int>(0);
    else if (scc[i << 1 ^ false] > scc[i << 1 ^ true])
      ans[i] = 1;
  }
  return ans;
}
int main() {
  cin >> n >> m;
  adj.resize(4 * n);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    if (w == 0) {
      add(u, 0, v, 0);
      add(u, 1, v, 1);
    } else {
      add(u, 1, v, 0);
      add(u, 0, v, 1);
    }
  }
  vector<int> ans = solve();
  if (ans.size() == 0)
    cout << "Impossible";
  else {
    vector<int> p;
    for (int i = 0; i < ans.size(); i++)
      if (ans[i] == 1) p.push_back(i + 1);
    cout << p.size() << '\n';
    for (int v : p) cout << v << " ";
  }
}
