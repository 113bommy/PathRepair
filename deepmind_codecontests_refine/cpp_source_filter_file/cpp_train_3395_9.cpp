#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int inf = 1e9;
vector<int> Eid[N];
int n, m, cnt, S, T, in[N], out[N], cur[N], d[N];
struct Edge {
  int c, v;
} E[N];
void AddEdge(int x, int y, int c, int cc) {
  E[cnt].v = y, E[cnt].c = c;
  Eid[x].push_back(cnt++);
  E[cnt].v = x, E[cnt].c = cc;
  Eid[y].push_back(cnt++);
}
bool BFS() {
  static int Q[N];
  int x, ql, qr;
  for (int i = 0; i <= n; i++) d[i] = -1;
  Q[ql = qr = 0] = S;
  d[S] = 0;
  while (ql <= qr) {
    x = Q[ql++];
    for (int i = 0; i < Eid[x].size(); i++) {
      const Edge &e = E[Eid[x][i]];
      if (e.c && d[e.v] == -1) {
        Q[++qr] = e.v;
        d[e.v] = d[x] + 1;
        if (e.v == T) return 1;
      }
    }
  }
  return 0;
}
int Aug(int x, int a) {
  if (x == T) return a;
  int aug = 0, delta;
  for (int &i = cur[x]; i < Eid[x].size(); i++) {
    Edge &e = E[Eid[x][i]];
    if (e.c && d[e.v] == d[x] + 1) {
      delta = Aug(e.v, min(a, e.c));
      if (delta) {
        e.c -= delta;
        E[Eid[x][i] ^ 1].c += delta;
        aug += delta;
        if (!(a -= delta)) break;
      }
    }
  }
  if (!aug) d[x] = -1;
  return aug;
}
int MaxFlow() {
  int flow = 0;
  while (BFS()) {
    for (int i = 0; i <= n; i++) cur[i] = 0;
    flow += Aug(S, inf);
  }
  return flow;
}
int u[N], v[N], g[N];
int C[N], F[N];
bool cut[N];
vector<pair<int, int> > G[N], G1[N];
pair<int, int> pre[N], pre1[N];
int dis[N], dis1[N], que[N];
bool bo[N];
void spfa() {
  int l = 1, r = 1, x, u, id;
  que[1] = S;
  for (int i = 1; i <= n; i++) dis[i] = inf;
  dis[S] = 0;
  while (l <= r) {
    x = que[l++];
    bo[x] = 0;
    for (int i = 0; i < G[x].size(); i++) {
      u = G[x][i].first;
      id = G[x][i].second;
      if (dis[u] > dis[x] + 1) {
        dis[u] = dis[x] + 1;
        pre[u] = make_pair(x, id);
        if (!bo[u]) que[++r] = u;
        bo[u] = 1;
      }
    }
  }
  l = r = 1;
  que[1] = T;
  for (int i = 1; i <= n; i++) dis1[i] = inf;
  dis1[T] = 0;
  while (l <= r) {
    x = que[l++];
    bo[x] = 0;
    for (int i = 0; i < G1[x].size(); i++) {
      u = G1[x][i].first;
      id = G1[x][i].second;
      if (dis1[u] > dis1[x] + 1) {
        dis1[u] = dis1[x] + 1;
        pre1[u] = make_pair(x, id);
        if (!bo[u]) que[++r] = u;
        bo[u] = 1;
      }
    }
  }
}
bool dfs(int x, int ed) {
  bo[x] = 1;
  if (x == ed) return 1;
  for (int i = 0; i < G[x].size(); i++) {
    int u = G[x][i].first;
    int id = G[x][i].second;
    if (bo[u]) continue;
    if (dfs(u, ed)) {
      C[id]++;
      F[id]++;
      return 1;
    }
  }
  return 0;
}
int main() {
  scanf("%d %d %d %d", &n, &m, &S, &T);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d", u + i, v + i, g + i);
    if (g[i]) {
      AddEdge(u[i], v[i], 1, 1);
      G[u[i]].push_back(make_pair(v[i], i));
      G1[v[i]].push_back(make_pair(u[i], i));
    } else
      AddEdge(u[i], v[i], inf, 0);
  }
  int ans = 0;
  cout << MaxFlow() << endl;
  MaxFlow();
  for (int i = 1; i <= m; i++)
    if (d[u[i]] != -1 && d[v[i]] == -1) cut[i] = 1;
  for (int i = 1; i <= m; i++) {
    if (g[i] == 0) continue;
    C[i]++;
    F[i]++;
    for (int j = 1; j <= n; j++) bo[j] = 0;
    if (dfs(v[i], u[i])) continue;
    for (int j = 1; j <= n; j++) bo[j] = 0;
    if (!dfs(S, u[i]))
      while (1)
        ;
    for (int j = 1; j <= n; j++) bo[j] = 0;
    if (!dfs(v[i], T))
      while (1)
        ;
  }
  for (int i = 1; i <= m; i++) {
    if (g[i] == 0) {
      cout << "0 1" << endl;
      continue;
    }
    if (!cut[i]) C[i]++;
    cout << F[i] << " " << C[i] << endl;
  }
}
