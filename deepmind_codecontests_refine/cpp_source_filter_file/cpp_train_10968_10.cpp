#include <bits/stdc++.h>
const long long big = 1010, large = 2010;
long long n, m;
long long vis[2][big], dis[big], inq[big], in[big], uu[large], vv[large],
    degree[big];
struct _Graph {
  long long EdgeSize;
  long long head[big];
  _Graph() { memset(head, -1, sizeof head), EdgeSize = 0; }
  struct _Edge {
    long long v, next, w;
  } e[large];
  inline void EdgeAdd(long long u, long long v, long long w = 0) {
    e[EdgeSize] = (_Edge){v, head[u], w};
    head[u] = EdgeSize++;
  }
} G[3], P;
std::queue<long long> q;
inline long long read() {
  char c(getchar());
  long long f(1), x(0);
  for (; !isdigit(c); (c == '-') && (f = -1), c = getchar())
    ;
  for (; isdigit(c); x = (x << 1) + (x << 3) + (c ^ 48), c = getchar())
    ;
  return f * x;
}
void dfs(long long u, long long sign) {
  vis[sign][u] = true;
  for (register int i(G[sign].head[u]); ~i; i = G[sign].e[i].next) {
    long long v = G[sign].e[i].v;
    if (vis[sign][v]) continue;
    dfs(v, sign);
  }
}
inline bool SPFA() {
  memset(dis, 0x3f, sizeof dis), memset(inq, 0, sizeof inq),
      memset(in, 0, sizeof in);
  dis[1] = 0, inq[1] = true, q.push(1);
  while (!q.empty()) {
    long long u = q.front();
    q.pop(), inq[u] = false;
    for (register int i(P.head[u]); ~i; i = P.e[i].next) {
      long long v = P.e[i].v, w = P.e[i].w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        if (++in[v] > n + 2) return false;
        if (!inq[v]) q.push(v), inq[v] = true;
      }
    }
  }
  return true;
}
inline void build() {
  for (register int i(1); i <= m; ++i)
    if ((vis[0][uu[i]] && vis[1][uu[i]]) && (vis[0][vv[i]] && vis[1][vv[i]]))
      G[2].EdgeAdd(uu[i], vv[i]), ++degree[vv[i]];
  for (register int i(1); i <= n; ++i)
    if (!degree[i] && (vis[0][i] && vis[1][i])) q.push(i);
  while (!q.empty()) {
    long long u = q.front();
    q.pop();
    for (register int i(G[2].head[u]); ~i; i = G[2].e[i].next) {
      long long v = G[2].e[i].v;
      --degree[v], P.EdgeAdd(u, v, 2), P.EdgeAdd(v, u, -1);
      if (!degree[v]) q.push(v);
    }
  }
}
int main(void) {
  n = read(), m = read();
  for (register int i(1); i <= m; ++i) {
    uu[i] = read(), vv[i] = read();
    G[0].EdgeAdd(uu[i], vv[i]), G[1].EdgeAdd(vv[i], uu[i]);
  }
  dfs(1, 0);
  if (!vis[0][n]) {
    printf("-1\n");
    return 0;
  }
  dfs(n, 1), build();
  if (!SPFA()) {
    printf("No\n");
    return 0;
  }
  printf("Yes\n");
  for (register int i(1); i <= m; ++i) {
    if ((vis[0][uu[i]] && vis[1][uu[i]]) && (vis[0][vv[i]] && vis[1][vv[i]]))
      printf("%lld\n", 1ll * abs(dis[uu[i]] - dis[vv[i]]));
    else
      printf("1\n");
  }
end:;
  return 0;
}
