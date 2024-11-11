#include <bits/stdc++.h>
using namespace std;
const int mx = 505;
vector<int> g[mx];
int d[mx];
void bfs(int from, int to) {
  queue<int> q;
  q.push(from);
  memset(d, -1, sizeof(d));
  d[from] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i = 0; i < g[v].size(); i++) {
      int u = g[v][i];
      if (d[u] == -1) {
        q.push(u);
        d[u] = d[v] + 1;
      }
    }
  }
}
int bus, train;
bool bb[mx][mx];
int main() {
  int n;
  int t;
  scanf("%d%d", &n, &t);
  for (int i = 0, a, b; i < t; i++) {
    scanf("%d %d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
    bb[a][b] = bb[b][a] = true;
  }
  bfs(1, n);
  bus = d[n];
  for (int i = 0; i < t; i++) g[i].clear();
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (!bb[i][j]) {
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  }
  bfs(1, n);
  train = d[n];
  int ans = max(bus, train);
  if (bus == -1 || train == -1) ans = -1;
  cout << ans;
  return 0;
}
