#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
bool flag[maxn];
int dis[maxn], dist[maxn], n, m, t, x;
vector<pair<int, int>> graph[maxn];
vector<pair<pair<int, int>, int>> yal;
queue<int> q;
pair<int, int> par[maxn];
void bfs() {
  memset(dis, -1, sizeof dis);
  dis[0] = 0;
  q.push(0);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto u : graph[v]) {
      if (dis[u.first] == -1) dis[u.first] = dis[v] + 1, q.push(u.first);
      if (dis[u.first] == dis[v] + 1 &&
          dist[v] + yal[u.second].second >= dist[u.first])
        dist[u.first] = dist[v] + yal[u.second].second,
        par[u.first] = make_pair(v, u.second);
    }
  }
}
void Output() {
  printf("%d\n", t + dis[n] - 2 * dist[n]);
  while (x != 0) {
    if (yal[par[x].second].second == 0)
      printf("%d %d 1\n", yal[par[x].second].first.first + 1,
             yal[par[x].second].first.second + 1);
    flag[par[x].second] = true;
    x = par[x].first;
  }
  for (int i = 0; i < m; ++i)
    if (!flag[i] && yal[i].second == 1)
      printf("%d %d 0\n", yal[i].first.first + 1, yal[i].first.second + 1);
}
int main() {
  scanf("%d%d", &n, &m);
  x = n - 1;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    --a, --b;
    graph[a].push_back(make_pair(b, i));
    graph[b].push_back(make_pair(a, i));
    if (c) ++t;
    yal.push_back(make_pair(make_pair(a, b), c));
  }
  bfs();
  Output();
  return 0;
}
