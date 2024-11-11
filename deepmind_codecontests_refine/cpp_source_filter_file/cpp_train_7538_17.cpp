#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;
const int INF = 1000000000;
int f[maxn][maxn], n, m, ans = INF, s, t, cur[maxn], dis[maxn], vis[maxn];
struct node {
  int u, v;
} e[maxn * 2];
struct edge {
  int from, to, cap, flow;
};
vector<edge> edges;
vector<int> g[maxn];
void addedge(int from, int to, int cap) {
  edges.push_back((edge){from, to, cap, 0});
  edges.push_back((edge){to, from, 0, 0});
  int m1 = edges.size();
  g[from].push_back(m1 - 2);
  g[to].push_back(m1 - 1);
}
bool bfs() {
  memset(vis, 0, sizeof(vis));
  queue<int> Q;
  Q.push(s);
  vis[s] = 1;
  dis[s] = 0;
  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();
    for (int i = 0; i < g[x].size(); i++) {
      edge e = edges[g[x][i]];
      if (e.cap > e.flow && !vis[e.to]) {
        dis[e.to] = dis[x] + 1;
        vis[e.to] = 1;
        Q.push(e.to);
      }
    }
  }
  return vis[t];
}
int dfs(int x, int a) {
  if (x == t || a == 0) return a;
  int flow = 0, f;
  for (int &i = cur[x]; i < g[x].size(); i++) {
    edge &e = edges[g[x][i]];
    if (dis[e.to] == dis[x] + 1 &&
        (f = dfs(e.to, min(e.cap - e.flow, a))) > 0) {
      flow += f;
      e.flow += f;
      edges[g[x][i] ^ 1].flow -= f;
      a -= f;
      if (a == 0) break;
    }
  }
  return flow;
}
int maxflow() {
  int flow = 0;
  while (bfs()) {
    memset(cur, 0, sizeof(cur));
    flow += dfs(s, INF);
  }
  return flow;
}
void build(int p) {
  edges.clear();
  for (int i = s; i <= t; i++) g[i].clear();
  for (int i = 1; i <= n; i++) {
    if (i == p) continue;
    addedge(s, i, 1);
    addedge(i + n, s, 1);
  }
  for (int i = 1; i <= m; i++)
    if (e[i].u != p && e[i].v != p) addedge(e[i].u, e[i].v + n, 1);
}
int work(int p) {
  int res = 0, tm = m;
  for (int i = 1; i <= n; i++) {
    if (p == i) continue;
    if (!f[i][p])
      res++;
    else
      tm--;
    if (!f[p][i])
      res++;
    else
      tm--;
  }
  if (!f[p][p])
    res++;
  else
    tm--;
  build(p);
  int v = maxflow();
  res += tm - v + n - 1 - v;
  return res;
}
int main() {
  scanf("%d%d", &n, &m);
  s = 0, t = n + 1;
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    f[x][y] = 1;
    e[i].u = x;
    e[i].v = y;
  }
  for (int i = 1; i <= n; i++) ans = min(ans, work(i));
  printf("%d\n", ans);
  return 0;
}
