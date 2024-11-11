#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
const int maxm = maxn * maxn;
int n, m, q;
long long ans[maxm];
namespace Dinic {
int tot, hd, tl;
int head[maxn], que[maxn * maxn], dis[maxn], vis[maxn], fe[maxn], fv[maxn];
int to[maxm << 1], nxt[maxm << 1], cap[maxm << 1], cost[maxm << 1];
inline void init() {
  tot = 0;
  memset(head, -1, sizeof(head));
  return;
}
inline void add(int u, int v, int w, int c) {
  to[tot] = v, cap[tot] = w, cost[tot] = c, nxt[tot] = head[u], head[u] = tot++;
  return;
}
inline void addEdge(int u, int v, int w) {
  add(u, v, 1, w);
  add(v, u, 0, -w);
  return;
}
inline void spfa(int s) {
  hd = tl = 0;
  vis[s] = true;
  memset(dis, 0x3f, sizeof(dis));
  dis[0] = 0, vis[0] = true;
  for (que[tl++] = s; hd < tl; ++hd) {
    int u = que[hd];
    vis[u] = false;
    for (int i = head[u]; ~i; i = nxt[i])
      if (cap[i]) {
        int v = to[i], w = cost[i];
        if (dis[v] > dis[u] + w) {
          dis[v] = dis[u] + w;
          fv[v] = u;
          fe[v] = i;
          if (!vis[v]) {
            vis[v] = true;
            que[tl++] = v;
          }
        }
      }
  }
  return;
}
inline void work() {
  ans[0] = 0;
  for (int i = (1); i <= (m); ++i) {
    spfa(0);
    ans[i] = ans[i - 1] + dis[n - 1];
    for (int u = n - 1; u; u = fv[u]) {
      int e = fe[u];
      --cap[e], ++cap[e ^ 1];
    }
  }
  return;
}
}  // namespace Dinic
int main() {
  scanf("%d%d", &n, &m);
  Dinic::init();
  for (int i = (0); i < (m); ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    --u;
    --v;
    Dinic::addEdge(u, v, w);
  }
  Dinic::work();
  scanf("%d", &q);
  for (int i = (0); i < (q); ++i) {
    int x;
    scanf("%d", &x);
    double res = 0x3f3f3f3f;
    for (int j = (1); j <= (m); ++j) res = min(res, 1.0 * (ans[j] + x) / j);
    printf("%.10lf\n", res);
  }
  return 0;
}
