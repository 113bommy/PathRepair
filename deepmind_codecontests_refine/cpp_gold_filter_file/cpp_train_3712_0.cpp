#include <bits/stdc++.h>
using namespace std;
long long n, m, arr[1006][1006], k, vis[1000006], dis[1000006], dis1[1000006],
    dis2[1000006];
vector<long long> adj[1000006];
void bfs(long long v) {
  queue<long long> q;
  q.push(v);
  vis[v] = 1;
  dis[v] = 0;
  while (q.size() > 0) {
    long long u = q.front();
    q.pop();
    for (long long i = 0; i < adj[u].size(); i++) {
      long long ch = adj[u][i];
      if (vis[ch]) continue;
      vis[ch] = 1;
      dis[ch] = dis[u] + 1;
      q.push(ch);
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  long long u, i, cost, p, cnt = 0, j, ans = 0, v, w, src, des, d;
  cin >> n >> m >> src >> des;
  for (i = 1; i <= m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    arr[u][v] = arr[v][u] = 1;
    arr[v][v] = arr[u][u] = 1;
  }
  bfs(src);
  for (i = 0; i <= n; i++) dis1[i] = dis[i];
  memset(vis, 0, sizeof(vis));
  bfs(des);
  for (i = 0; i <= n; i++) dis2[i] = dis[i];
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (arr[i][j] == 1) continue;
      d = min(dis1[i] + min(1 + dis2[j], 1 + dis2[i]),
              dis1[j] + min(1 + dis2[i], 1 + dis2[j]));
      if (d >= dis1[des]) {
        cnt++;
      }
    }
  }
  cout << cnt / 2;
  return 0;
}
