#include <bits/stdc++.h>
using namespace std;
const int N = 2600;
int capacity[N][N], cost[N][N], f[N], visit[N], n, q, can[N][N], source, sink,
    res, p[N], oo = 1e9;
vector<int> adj[N];
void add(int u, int v, int cap, int c) {
  adj[u].push_back(v);
  adj[v].push_back(u);
  capacity[u][v] = cap;
  cost[u][v] = c;
  cost[v][u] = -c;
}
int bfs() {
  for (int i = 0; i <= sink; i++) {
    f[i] = oo;
    visit[i] = 2;
  }
  f[source] = 0;
  deque<int> q;
  q.push_back(source);
  while (!q.empty()) {
    int u = q.front();
    q.pop_front();
    visit[u] = 0;
    for (int v : adj[u]) {
      if (capacity[u][v] > 0 && f[v] > f[u] + cost[u][v]) {
        f[v] = f[u] + cost[u][v];
        p[v] = u;
        if (visit[v] == 2) {
          visit[v] = 1;
          q.push_back(v);
        } else if (visit[v] == 0) {
          visit[v] = 1;
          q.push_front(v);
        }
      }
    }
  }
  if (f[sink] != oo)
    return 1;
  else
    return 0;
}
int main() {
  cin >> n >> q;
  source = 0;
  sink = n + n * n + n + 1;
  for (int i = 1; i <= n; i++) add(source, i, 1, 0);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) can[i][j] = 1;
  while (q--) {
    int type, l, r, val;
    cin >> type >> l >> r >> val;
    for (int i = l; i <= r; i++) {
      if (type == 1)
        for (int j = 1; j < val; j++) can[i][j] = 0;
      else
        for (int j = val + 1; j <= n; j++) can[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    int check = 0;
    for (int j = 1; j <= n; j++)
      if (can[i][j]) {
        check = 1;
        for (int k = 1; k <= n; k++) add(i, n + j * n + k, 1, 0);
      }
    if (!check) {
      cout << -1;
      return 0;
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) add(n + i * n + j, sink, 1, j * 2 - 1);
  while (bfs()) {
    int flow = 1e9;
    int v = sink;
    while (v != source) {
      int u = p[v];
      flow = min(flow, capacity[u][v]);
      v = u;
    }
    res += 1LL * flow * f[sink];
    v = sink;
    while (v != source) {
      int u = p[v];
      capacity[u][v] -= flow;
      capacity[v][u] += flow;
      v = u;
    }
  }
  cout << res;
}
