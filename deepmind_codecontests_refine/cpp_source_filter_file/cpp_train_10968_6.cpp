#include <bits/stdc++.h>
using namespace std;
int const N = 1e3 + 20, M = 1e4 + 20, INF = 1e9;
struct edge {
  int from, to, w;
} e[M];
int n, m, dist[N];
bool mark1[N], mark2[N], mark[N];
vector<int> ad1[N], ad2[N];
pair<int, int> d[M];
void dfs(int v, bool f) {
  f ? mark2[v] = 1 : mark1[v] = 1;
  for (auto u : (f ? ad2[v] : ad1[v])) {
    if ((f && !mark2[u]) || (!f && !mark1[u])) dfs(u, f);
  }
  return;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    ad1[x].push_back(y);
    ad2[y].push_back(x);
    e[2 * i].from = x, e[2 * i].to = y, e[2 * i].w = 2;
    e[2 * i + 1].from = y, e[2 * i + 1].to = x, e[2 * i + 1].w = -1;
    d[i].first = x, d[i].second = y;
  }
  m *= 2;
  dfs(0, 0);
  dfs(n - 1, 1);
  for (int i = 0; i < n; i++) mark[i] = (mark1[i] & mark2[i]);
  if (!mark[0] || !mark[n - 1]) return cout << "No", 0;
  for (int i = 0; i < n; i++) dist[i] = INF;
  dist[0] = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int ed = 0; ed < m; ed++) {
      int x = e[ed].from, y = e[ed].to, we = e[ed].w;
      if (!mark[x] || !mark[y]) continue;
      dist[y] = min(dist[y], dist[x] + we);
    }
  }
  for (int ed = 0; ed < m; ed++) {
    int x = e[ed].from, y = e[ed].to, we = e[ed].w;
    if (!mark[x] || !mark[y]) continue;
    if (dist[y] > dist[x] + we) return cout << "No", 0;
  }
  cout << "YES\n";
  m /= 2;
  for (int i = 0; i < m; i++) {
    int x = d[i].first, y = d[i].second;
    if (dist[x] == INF || dist[y] == INF || dist[y] == dist[x] + 1)
      cout << "1\n";
    else
      cout << "2\n";
  }
  return 0;
}
