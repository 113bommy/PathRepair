#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  int f = 1, sum = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    sum = (sum << 3) + (sum << 1) + ch - '0';
    ch = getchar();
  }
  return f * sum;
}
const int N = 610, No = 200010, M = 500010, Inf = 1e9 + 10;
int g[N][N], v, E, n, k, x[N];
struct node {
  int to, nxt, w;
} e[M << 1];
int front[No], cnt, dep[No], s, t, cur[No];
void Add(int u, int v, int w) {
  e[cnt] = (node){v, front[u], w};
  front[u] = cnt++;
  e[cnt] = (node){u, front[v], 0};
  front[v] = cnt++;
}
queue<int> Q;
bool bfs() {
  memset(dep, 0, sizeof(dep));
  dep[s] = 1;
  Q.push(s);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int i = front[u]; ~i; i = e[i].nxt) {
      int v = e[i].to;
      if (e[i].w && !dep[v]) {
        dep[v] = dep[u] + 1;
        Q.push(v);
      }
    }
  }
  return dep[t];
}
int dfs(int u, int flow) {
  if (u == t || !flow) return flow;
  for (int &i = cur[u]; ~i; i = e[i].nxt) {
    int v = e[i].to;
    if (e[i].w && dep[v] == dep[u] + 1) {
      int di = dfs(v, min(flow, e[i].w));
      if (di) {
        e[i].w -= di;
        e[i ^ 1].w += di;
        return di;
      } else
        dep[v] = -1;
    }
  }
  return 0;
}
int Dinic() {
  int flow = 0;
  while (bfs()) {
    for (int i = s; i <= t; i++) cur[i] = front[i];
    while (int d = dfs(s, Inf)) flow += d;
  }
  return flow;
}
bool check(int mid) {
  memset(front, -1, sizeof(front));
  cnt = 0;
  s = 0;
  t = n + v + 1;
  for (int i = 1; i <= n; i++) Add(s, i, 1);
  for (int i = 1; i <= v; i++) Add(i + n, t, 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= v; j++)
      if (g[x[i]][j] <= mid) Add(i, j + n, 1);
  return Dinic() >= k;
}
int main() {
  v = gi();
  E = gi();
  n = gi();
  k = gi();
  memset(g, 63, sizeof(g));
  for (int i = 1; i <= n; i++) x[i] = gi();
  for (int i = 1; i <= E; i++) {
    int u = gi(), v = gi();
    g[u][v] = g[v][u] = min(g[u][v], gi());
  }
  for (int i = 1; i <= v; i++) g[i][i] = 0;
  for (int u = 1; u <= v; u++)
    for (int i = 1; i <= v; i++)
      for (int j = 1; j <= v; j++) g[i][j] = min(g[i][j], g[i][u] + g[u][j]);
  int l = 0, r = 1731311, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  printf("%d\n", ans);
  return 0;
}
