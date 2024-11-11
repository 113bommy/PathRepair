#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 14, maxk = 114;
int n, m, k, s, cost[maxn][maxk], dist[maxn], a[maxn];
vector<int> g[maxn];
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> k >> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  while (m--) {
    int v, u;
    cin >> v >> u;
    v--, u--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  for (int col = 0; col < k; col++) {
    memset(dist, -1, sizeof dist);
    queue<int> que;
    for (int i = 0; i < n; i++) {
      if (a[i] == col) {
        dist[i] = 0;
        que.push(i);
      }
    }
    while (!que.empty()) {
      int a = que.front();
      que.pop();
      for (int i = 0; i < g[a].size(); i++) {
        int b = g[a][i];
        if (dist[b] == -1) {
          dist[b] = dist[a] + 1;
          que.push(b);
        }
      }
    }
    for (int i = 0; i < n; i++) cost[i][col] = dist[i];
  }
  for (int i = 0; i < n; i++) {
    sort(cost[i], cost[i] + k);
    cout << accumulate(cost[i], cost[i] + s, 0ll) << ' ';
  }
  cout << '\n';
}
