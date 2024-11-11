#include <bits/stdc++.h>
using namespace std;
const int MAXN = 410, MOD = 1e9 + 7, INF = 1e9 + 5;
bool mark[MAXN], G[MAXN][MAXN];
vector<int> adj[MAXN];
int dis[MAXN];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u][v] = 1;
    G[v][u] = 1;
  }
  bool want = !G[0][n - 1];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (G[i][j] == want) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }
  queue<int> q;
  q.push(0);
  mark[0] = 1;
  while (!q.empty()) {
    auto f = q.front();
    q.pop();
    for (int i : adj[f]) {
      if (mark[i]) continue;
      mark[i] = 1;
      dis[i] = dis[f] + 1;
      q.push(i);
    }
  }
  cout << (dis[n - 1] == 0 ? -1 : dis[n - 1]) << '\n';
}
