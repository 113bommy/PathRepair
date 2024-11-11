#include <bits/stdc++.h>
using namespace std;
const int N = 105, inf = 1e9;
const long long INF = 1e18;
int n, m, S, T, val[N];
int inq[N], head[N], cur[N], ce = 1;
long long dis[N], mincost;
struct edge {
  int to, nxt, cap, flow, w;
} e[200003];
void lnk(int a, int b, int c, int w) {
  if (!c) return;
  e[++ce] = (edge){b, head[a], c, 0, w}, head[a] = ce;
  e[++ce] = (edge){a, head[b], 0, 0, -w}, head[b] = ce;
}
queue<int> q;
long long bfs() {
  for (int i = 1; i <= n + 2; ++i) inq[i] = 0, dis[i] = INF;
  q.push(S);
  dis[S] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    inq[u] = 0;
    for (int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].to;
      if (dis[v] > dis[u] + e[i].w && e[i].cap > e[i].flow) {
        dis[v] = dis[u] + e[i].w;
        if (!inq[v]) inq[v] = 1, q.push(v);
      }
    }
  }
  memcpy(cur, head, n + 3 << 2);
  return dis[T];
}
int dfs(int u, int lim) {
  if (u == T) return mincost += dis[T] * lim, lim;
  int tag = 0;
  inq[u] = 1;
  for (int &i = cur[u]; i; i = e[i].nxt)
    if (dis[e[i].to] == dis[u] + e[i].w && e[i].cap > e[i].flow &&
        !inq[e[i].to]) {
      int d = dfs(e[i].to, min(lim - tag, e[i].cap - e[i].flow));
      tag += d, e[i].flow += d, e[i ^ 1].flow -= d;
      if (tag == lim) return inq[u] = 0, lim;
    }
  return tag;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int u, v, c, f;
    cin >> u >> v >> c >> f;
    val[v] += min(c, f), val[u] -= min(c, f);
    if (f <= c) {
      lnk(u, v, c - f, 1);
      lnk(u, v, inf, 2);
      lnk(v, u, f, 1);
    } else {
      lnk(u, v, f - c, 0);
      lnk(u, v, inf, 2);
      lnk(v, u, inf, 1);
      mincost += abs(c - f);
    }
  }
  S = n + 1, T = n + 2;
  for (int i = 1; i <= n; ++i) {
    if (val[i] > 0)
      lnk(S, i, val[i], 0);
    else
      lnk(i, T, -val[i], 0);
  }
  lnk(n, 1, inf, 0);
  while (bfs() < INF) dfs(S, inf);
  S = n, T = 1;
  while (bfs() < 0) dfs(S, inf);
  swap(S, T);
  while (bfs() < 0) dfs(S, inf);
  cout << mincost << endl;
  return 0;
}
