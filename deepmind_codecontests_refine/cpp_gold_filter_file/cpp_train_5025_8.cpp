#include <bits/stdc++.h>
using namespace std;
int dp[100005];
int d(int v, int p, vector<vector<int> > &g) {
  vector<int> dis;
  int curr_max = 0;
  for (int i = 0; i < g[v].size(); i++) {
    if (g[v][i] != p) {
      curr_max = max(curr_max, d(g[v][i], v, g));
      dis.push_back(dp[g[v][i]]);
    }
  }
  sort(dis.begin(), dis.end());
  reverse(dis.begin(), dis.end());
  if (dis.empty()) {
    dp[v] = 1;
    return 1;
  }
  dp[v] = dis[0] + 1;
  if (dis.size() == 1) {
    return max(curr_max, dp[v]);
  }
  curr_max = max(curr_max, dis[0] + dis[1] + 1);
  return curr_max;
}
int dist(int a, int b, vector<vector<int> > &g) {
  queue<int> q;
  vector<int> d(g.size());
  vector<int> vis(g.size());
  q.push(a);
  vis[a] = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 0; i < g[x].size(); i++) {
      if (!vis[g[x][i]]) {
        q.push(g[x][i]);
        vis[g[x][i]] = 1;
        d[g[x][i]] = d[x] + 1;
      }
    }
  }
  return d[b];
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    vector<vector<int> > g(n + 1);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
      dp[i] = 0;
    }
    if (dist(a, b, g) > da && d(1, 0, g) > da * 2 + 1 && db >= da * 2 + 1) {
      cout << "Bob\n";
    } else {
      cout << "Alice\n";
    }
  }
  return 0;
}
