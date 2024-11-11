#include <bits/stdc++.h>
using namespace std;
class graph {
 public:
  int v;
  list<int> *adj;
  int *par;
  int n;
  int *depth;
  bool *visited;
  bool flag;
  bool *vis;
  int *clr;
  int odd, even;
  graph(int v) {
    this->v = v;
    flag = true;
    odd = 0;
    even = 0;
    adj = new list<int>[v];
    par = new int[v];
    depth = new int[v];
    visited = new bool[v];
    vis = new bool[v];
    clr = new int[v];
    for (int i = 0; i < v; ++i) {
      clr[i] = -1;
      par[i] = -1;
      depth[i] = 0;
      visited[i] = false;
      vis[i] = false;
    }
  }
  void add(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  void dfs(int v, int d);
  void dfs1(int v, int d, pair<int, int> &cl, int &k);
};
void graph::dfs(int i, int d) {
  visited[i] = true;
  depth[i] = d;
  if (d & 1)
    odd++;
  else
    even++;
  for (auto t : adj[i]) {
    if (t != par[i] && visited[t]) {
      if ((depth[t] - depth[i]) % 2 == 0) flag = false;
    }
    if (!visited[t]) {
      par[t] = i;
      dfs(t, d + 1);
    }
  }
}
void graph::dfs1(int i, int d, pair<int, int> &cl, int &k) {
  vis[i] = true;
  if (d & 1) {
    if (cl.first == 1)
      clr[i] = 2;
    else {
      if (k >= n)
        clr[i] = 3;
      else {
        clr[i] = 1;
        k++;
      }
    }
  } else {
    if (cl.second == 1)
      clr[i] = 2;
    else {
      if (k >= n)
        clr[i] = 3;
      else {
        clr[i] = 1;
        k++;
      }
    }
  }
  for (auto t : adj[i]) {
    if (!vis[t]) {
      dfs1(t, d + 1, cl, k);
    }
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  int n1, n2, n3;
  cin >> n1 >> n2 >> n3;
  graph g(n);
  g.n = n1;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g.add(u, v);
  }
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    if (!g.visited[i]) {
      g.dfs(i, 0);
      v.push_back({g.odd, g.even});
      g.odd = 0;
      g.even = 0;
    }
  }
  if (!g.flag) {
    cout << "NO" << endl;
    return;
  }
  int dp[v.size() + 1][n + 1];
  memset(dp, -1, sizeof dp);
  dp[0][0] = 1;
  for (int i = 1; i <= v.size(); ++i) {
    for (int j = 0; j <= n; ++j) {
      if (j - v[i - 1].first >= 0 && dp[i - 1][j - v[i - 1].first] >= 0)
        dp[i][j] = 0;
      if (j - v[i - 1].second >= 0 && dp[i - 1][j - v[i - 1].second] >= 0)
        dp[i][j] = 1;
    }
  }
  if (dp[v.size()][n2] == -1)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    int e = n2;
    int o = n1 + n2;
    vector<pair<int, int> > cl;
    for (int i = v.size(); i > 0; --i) {
      if (dp[i][e] == 1) {
        cl.push_back({0, 1});
        e -= v[i - 1].second;
      } else {
        cl.push_back({1, 0});
        e -= v[i - 1].first;
      }
    }
    int k = 0;
    int idx = cl.size() - 1;
    for (int i = 0; i < n; i++) {
      if (!g.vis[i]) {
        g.dfs1(i, 0, cl[idx], k);
        idx--;
      }
    }
    for (int i = 0; i < n; ++i) {
      cout << g.clr[i];
    }
  }
}
int main() {
  long long int t = 1;
  while (t--) {
    solve();
  }
}
