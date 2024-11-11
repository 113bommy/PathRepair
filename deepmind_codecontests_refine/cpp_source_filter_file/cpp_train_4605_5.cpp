#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 1, M = 5e3 + 1, INF = 0x3f3f3f3f;
long double a[M];
int n, m, q, tot = 1, S, T, lim, h[N];
int dis[N], pre[N], last[N], ins[N];
struct edge {
  int t, n, w, v;
} e[M];
inline void add_edge(int x, int y, int w, int v) {
  e[++tot] = (edge){y, h[x], w, v}, h[x] = tot;
  e[++tot] = (edge){x, h[y], 0, -v}, h[y] = tot;
}
inline void input() {
  scanf("%d%d", &n, &m);
  int x, y, w = 1, v;
  while (m--) scanf("%d%d%d", &x, &y, &v), add_edge(x, y, w, v);
  scanf("%d", &q);
}
queue<int> Q;
inline bool spfa() {
  for (int i = 2; i <= n; i++) dis[i] = INF, pre[i] = last[i] = 0;
  Q.push(S), ins[S] = 1;
  for (int u; !Q.empty(); Q.pop()) {
    ins[u = Q.front()] = 0;
    for (int i = h[u], v; v = e[i].t, i; i = e[i].n)
      if (e[i].w && dis[v] > dis[u] + e[i].v) {
        dis[v] = dis[u] + e[i].v, pre[v] = u, last[v] = i;
        if (!ins[v]) Q.push(v), ins[v] = 1;
      }
  }
  return dis[T] < INF;
}
inline void init() {
  for (S = 1, T = n, lim = 0; spfa(); lim++) {
    a[lim + 1] = a[lim] + dis[T];
    for (int x = T; x ^ S; x = pre[x]) e[last[x]].w--, e[last[x] ^ 1].w++;
  }
}
inline void work() {
  long double ans;
  int x;
  while (q--) {
    scanf("%d", &x), ans = 1e99;
    for (int i = 1; i <= lim; i++) ans = min(ans, (a[i] + x) / i);
    printf("%.9Lf\n", ans);
  }
}
int main() {
  input();
  init();
  work();
  return 0;
}
