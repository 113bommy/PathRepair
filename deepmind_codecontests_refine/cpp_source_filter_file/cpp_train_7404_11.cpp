#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1 << 62;
const long long MOD = 1e9 + 7;
const int iINF = 1 << 30;
const double PI = 3.14159265359;
vector<vector<int> > adj;
vector<int> cmp[3];
vector<int> dist[3];
int bfs(int src, int state, int c) {
  queue<int> q;
  cmp[state][src] = c;
  dist[state][src] = 0;
  q.push(src);
  int farthest = src;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      if (cmp[state][v] == -1) {
        dist[state][v] = dist[state][u] + 1;
        cmp[state][v] = c;
        q.push(v);
        farthest = v;
      }
    }
  }
  return farthest;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  adj.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cmp[0].assign(n, -1);
  cmp[1].assign(n, -1);
  cmp[2].assign(n, -1);
  dist[0].assign(n, iINF);
  dist[1].assign(n, iINF);
  dist[2].assign(n, -1);
  int c = 0;
  int maxi_diam = iINF, best_center_idx = 0;
  vector<int> centers;
  for (int i = 0; i < n; i++) {
    if (cmp[0][i] == -1) {
      int node1 = bfs(i, 0, c);
      int node2 = bfs(node1, 1, c);
      bfs(node2, 2, c);
      int diam = dist[1][node2];
      int center = -1;
      for (int j = 0; j < n; j++) {
        if (cmp[0][j] == c && dist[2][j] == diam / 2 &&
            dist[1][j] == diam - diam / 2)
          center = j;
      }
      if (diam > maxi_diam) {
        maxi_diam = diam;
        best_center_idx = centers.size();
      }
      centers.push_back(center);
      c++;
    }
  }
  for (int i = 0; i < centers.size(); i++) {
    if (i == best_center_idx) continue;
    adj[centers[best_center_idx]].push_back(centers[i]);
    adj[centers[i]].push_back(centers[best_center_idx]);
  }
  cmp[0].assign(n, -1);
  cmp[1].assign(n, -1);
  dist[0].assign(n, -1);
  dist[1].assign(n, -1);
  int node1 = bfs(0, 0, 0);
  int node2 = bfs(node1, 1, 0);
  cout << dist[1][node2] << "\n";
  for (int i = 0; i < centers.size(); i++) {
    if (i == best_center_idx) continue;
    cout << centers[best_center_idx] + 1 << " " << centers[i] + 1 << "\n";
  }
  return 0;
}
