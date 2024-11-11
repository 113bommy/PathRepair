#include <bits/stdc++.h>
using namespace std;
const int NMAX = 3e4 + 7;
const int INF = 2e9 + 11;
int n, m, s, t, par[NMAX], fup[NMAX], tin[NMAX], es[NMAX], ec[NMAX], vis[NMAX],
    par2[NMAX];
vector<int> G[NMAX], res;
map<pair<int, int>, int> Bridge;
int ans = INF;
void Bfs() {
  queue<int> Q;
  Q.push(s);
  vis[s] = 1;
  while (!Q.empty()) {
    int now = Q.front();
    Q.pop();
    for (int edge2 : G[now]) {
      int nxt = es[edge2] - now;
      if (!vis[nxt]) {
        vis[nxt] = 1;
        Q.push(nxt);
        par[nxt] = edge2;
      }
    }
  }
}
int Time = 0, edge;
void Dfs(int cur, int prev) {
  vis[cur] = 1;
  tin[cur] = ++Time;
  fup[cur] = Time;
  for (int edge1 : G[cur]) {
    int nxt = es[edge1] - cur;
    if (edge1 == prev || edge1 == edge) continue;
    if (vis[nxt])
      fup[cur] = min(fup[cur], tin[nxt]);
    else {
      par2[nxt] = edge1;
      Dfs(nxt, edge1);
      fup[cur] = min(fup[cur], fup[nxt]);
      if (fup[nxt] > tin[cur]) Bridge[{min(nxt, cur), max(nxt, cur)}] = 1;
    }
  }
}
void Skip(int edge3) {
  memset(vis, 0, sizeof(vis));
  memset(par2, 0, sizeof(par2));
  Bridge.clear();
  edge = edge3;
  Time = 0;
  Dfs(s, -1);
  if (vis[t] == 0) {
    if (ans > ec[edge]) {
      ans = ec[edge];
      res = {edge};
      return;
    }
    return;
  }
  for (int go = t; go != s;) {
    int edg = par2[go];
    int nxt = es[edg] - go;
    if (Bridge[{min(nxt, go), max(nxt, go)}]) {
      if (ans > ec[edg] + ec[edge]) {
        ans = ec[edg] + ec[edge];
        res = {edge, edg};
      }
    }
    go = nxt;
  }
}
int main() {
  scanf("%d%d%d%d", &n, &m, &s, &t);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    G[u].push_back(i);
    G[v].push_back(i);
    es[i] = u + v;
    ec[i] = w;
  }
  Bfs();
  if (!vis[t]) return printf("0\n0") * 0;
  int go = t;
  for (; go != s; go = es[par[go]] - go) {
    Skip(par[go]);
  }
  if (ans == INF) return printf("-1\n") * 0;
  printf("%d\n", ans);
  printf("%d\n", res.size());
  for (int i : res) printf("%d ", i);
  return 0;
}
