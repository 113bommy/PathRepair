#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int N = 100200;
struct Node {
  int to, cost;
};
vector<Node> g[N];
int dist[105][N] = {}, arr[N] = {}, n, m, type[N] = {}, k, s, vis[N] = {};
void addedge(int u, int v, int cost) {
  g[u].push_back((Node){v, cost});
  g[v].push_back((Node){u, cost});
}
void bfs(int s, int n, int* d) {
  queue<int> que;
  memset(vis, 0, sizeof(vis));
  int p, to, cost;
  que.push(s);
  vis[s] = 1;
  while (!que.empty()) {
    p = que.front();
    que.pop();
    const int sz = g[p].size();
    for (int i = 0; i < sz; i++) {
      to = g[p][i].to;
      if (to > n || vis[to]) continue;
      d[to] = d[p] + 1;
      que.push(to);
      vis[to] = 1;
    }
  }
}
int main(void) {
  std::ios::sync_with_stdio(false);
  cin >> n >> m >> k >> s;
  for (int i = 0; i < n; i++) cin >> type[i];
  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--;
    v--;
    addedge(u, v, 1);
  }
  for (int i = 0; i < n; i++) {
    addedge(n - 1 + type[i], i, 1);
  }
  for (int i = 1; i <= k; i++) {
    bfs(n - 1 + i, n, dist[i]);
  }
  for (int i = 0; i < n; i++) {
    int ans = 0;
    for (int j = 1; j <= k; j++) arr[j] = dist[j][i] - 1;
    sort(arr + 1, arr + k + 1);
    for (int i = 1; i <= s; i++) ans += arr[i];
    cout << ans << ' ';
  }
  return 0;
}
