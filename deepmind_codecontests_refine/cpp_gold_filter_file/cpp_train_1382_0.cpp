#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 7;
const int mod = 1e9 + 7;
const int INF = 1e9 + 7;
const int mlog = 20;
const int SQ = 400;
int n, m;
int col[maxn], dis[maxn];
vector<pair<int, int> > adj[maxn];
void bfs() {
  for (int i = 1; i < n; i++) dis[i] = n + 1;
  queue<int> q;
  q.push(n);
  while (!q.empty()) {
    int v = q.front();
    for (pair<int, int> u : adj[v]) {
      if (!col[u.first])
        col[u.first] = (u.second ^ 1) + 1;
      else if (col[u.first] == u.second + 1 && dis[v] + 1 < dis[u.first]) {
        dis[u.first] = dis[v] + 1;
        q.push(u.first);
      }
    }
    q.pop();
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[v].push_back({u, c});
  }
  bfs();
  if (dis[1] < n)
    cout << dis[1] << "\n";
  else
    cout << -1 << "\n";
  for (int i = 1; i <= n; i++) {
    if (col[i])
      cout << col[i] - 1;
    else
      cout << col[i];
  }
  return 0;
}
