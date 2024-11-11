#include <bits/stdc++.h>
using namespace std;
const int N = 105, M = N * 30, INF = 0x3f3f3f3f;
struct GRAPH {
  int head[N], to[M << 1], nxt[M << 1], cap[M << 1], cost[M << 1], ncnt;
  GRAPH() { ncnt = 1; }
  inline void AddEdge(const int &u, const int &v, const int &vcap,
                      const int &vcost) {
    int p = ++ncnt, q = ++ncnt;
    to[p] = v, nxt[p] = head[u], head[u] = p, cap[p] = vcap, cost[p] = vcost;
    to[q] = u, nxt[q] = head[v], head[v] = q, cap[q] = 0, cost[q] = -vcost;
  }
  inline int operator[](const int &u) { return head[u]; }
} Gr;
int n, m, St, Ed;
int in_out[N], edg[N][4], dis[N], head[N];
bool vis[N];
bool SPFA() {
  for (int i = 1; i <= Ed; i++) dis[i] = INF, head[i] = Gr[i];
  queue<int> que;
  que.push(St), dis[St] = 0;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    vis[u] = false;
    for (int it = head[u]; it; it = Gr.nxt[it]) {
      int v = Gr.to[it];
      if (!Gr.cap[it]) continue;
      if (dis[v] > dis[u] + Gr.cost[it]) {
        dis[v] = dis[u] + Gr.cost[it];
        if (!vis[v]) vis[v] = true, que.push(v);
      }
    }
  }
  return dis[Ed] < INF;
}
int Aug(const int &u, const int &in, int &cst) {
  cst = 0;
  if (u == Ed) return in;
  int out = 0;
  vis[u] = true;
  for (int &it = head[u]; it; it = Gr.nxt[it]) {
    int v = Gr.to[it];
    if (vis[v] || dis[v] != dis[u] + Gr.cost[it] || !Gr.cap[it]) continue;
    int cstv, tov = Aug(v, min(in - out, Gr.cap[it]), cstv);
    cst += cstv + tov * Gr.cost[it];
    if (cst >= INF)
      printf("! %d -> %d %d %d\n", u, v, tov, Gr.cost[it], Gr.cap[it]);
    Gr.cap[it] -= tov, Gr.cap[it ^ 1] += tov;
    out += tov;
    if (out == in) break;
  }
  vis[u] = false;
  return out;
}
int Dinic() {
  int ret = 0, per = 0, flow = 0;
  while (SPFA()) flow += Aug(St, INF, per), ret += per;
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++)
    scanf("%d%d%d%d", &edg[i][0], &edg[i][1], &edg[i][2], &edg[i][3]);
  St = n + 1, Ed = n + 2;
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    int u = edg[i][0], v = edg[i][1];
    in_out[u] -= edg[i][3];
    in_out[v] += edg[i][3];
    if (edg[i][3] <= edg[i][2]) {
      if (edg[i][3] < edg[i][2]) Gr.AddEdge(u, v, edg[i][2] - edg[i][3], 1);
      Gr.AddEdge(u, v, INF, 2);
      Gr.AddEdge(v, u, edg[i][3], 1);
    } else {
      ans += edg[i][3] - edg[i][2];
      Gr.AddEdge(v, u, edg[i][3] - edg[i][2], 0);
      Gr.AddEdge(v, u, edg[i][2], 1);
      Gr.AddEdge(u, v, INF, 2);
    }
  }
  int totin = in_out[n];
  for (int i = 1; i <= n; i++) {
    if (in_out[i] > 0)
      Gr.AddEdge(St, i, in_out[i], 0);
    else if (in_out[i] < 0)
      Gr.AddEdge(i, Ed, -in_out[i], 0), totin += in_out[i];
  }
  Gr.AddEdge(n, 1, INF, 0);
  printf("%d\n", ans + Dinic());
  return 0;
}
