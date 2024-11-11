#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 13;
void dfs(int u, bool colour, int compo);
bool col[MAXN], markd[MAXN], bi = true, markb[MAXN][MAXN];
int dist[MAXN][MAXN];
queue<int> bfsq;
vector<int> adj[MAXN], comp[MAXN];
int main() {
  int n, m;
  cin >> n >> m;
  {
    int a, b;
    for (int i = 1; i <= m; i++) {
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
  }
  int c = 0;
  for (int i = 1; i <= n; i++)
    if (!markd[i]) dfs(i, true, ++c);
  if (!bi) {
    cout << -1 << endl;
    return 0;
  }
  int u = 0;
  for (int i = 1; i <= n; i++) {
    markb[i][i] = true;
    dist[i][i] = 0;
    bfsq.push(i);
    while (!bfsq.empty()) {
      u = bfsq.front();
      markb[u][i] = true;
      bfsq.pop();
      for (auto v : adj[u])
        if (!markb[v][i]) {
          markb[v][i] = true;
          bfsq.push(v);
          dist[i][v] = dist[i][u] + 1;
        }
    }
  }
  int ans = 0, k = 0;
  for (int i = 1; i <= c; i++) {
    k = 0;
    for (auto v : comp[i])
      for (auto u : comp[i]) k = max(k, dist[v][u]);
    ans += k;
  }
  cout << ans << endl;
  return 0;
}
void dfs(int u, bool colour, int compo) {
  markd[u] = true;
  col[u] = colour;
  comp[compo].push_back(u);
  for (auto v : adj[u])
    if (!markd[v])
      dfs(v, !colour, compo);
    else if (col[v] == colour) {
      bi = false;
      return;
    }
  return;
}
