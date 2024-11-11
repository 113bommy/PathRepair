#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > vec(5005);
int vis[5005];
int dis[5005][5005];
void bfs(int v) {
  queue<int> q;
  dis[v][v] = 0;
  q.push(v);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < vec[u].size(); i++) {
      int child = vec[u][i];
      if (dis[v][child] > dis[v][u] + 1)
        dis[v][child] = dis[v][u] + 1, q.push(child);
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int v, u;
    cin >> v >> u;
    v--;
    u--;
    vec[v].push_back(u);
    vec[u].push_back(v);
  }
  int s1, t1, l1, s2, t2, l2;
  cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
  s1--, t1--, s2--, t2--;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) dis[i][j] = 1e9;
  for (int i = 0; i < n; i++) bfs(i);
  int ans = 1e9;
  if (dis[s1][t1] <= l1 && dis[s2][t2] <= l2) ans = dis[s1][t1] + dis[s2][t2];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int dis1 = dis[s1][i] + dis[i][j] + dis[j][t1];
      int dis2 = dis[s2][i] + dis[i][j] + dis[j][t2];
      int dis4 = dis[t2][i] + dis[i][j] + dis[j][s2];
      if ((dis1 <= l1 && dis2 <= l2)) ans = min(dis1 + dis2 - dis[i][j], ans);
      if (dis1 <= l1 && dis4 <= l2) ans = min(dis1 + dis4 - dis[i][j], ans);
    }
  }
  if (ans > m)
    cout << -1 << endl;
  else
    cout << m - ans << endl;
  return 0;
}
