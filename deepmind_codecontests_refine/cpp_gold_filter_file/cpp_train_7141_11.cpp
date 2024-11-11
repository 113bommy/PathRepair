#include <bits/stdc++.h>
const int N = 3e3 + 10, inf = 2147483647;
inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f ? -x : x;
}
struct Network {
  static const int N = 1e4 + 10, M = 1e5 + 10, inf = 2147483647;
  int n, s, t, tot = 1, fir[N], nex[M], got[M], tak[M], cst[M], dis[N], ins[N],
               pre[N];
  inline void add(int u, int v, int w, int c) {
    nex[++tot] = fir[u], fir[u] = tot, got[tot] = v, tak[tot] = w, cst[tot] = c;
    nex[++tot] = fir[v], fir[v] = tot, got[tot] = u, tak[tot] = 0,
    cst[tot] = -c;
  }
  inline int bfs() {
    for (int i = 1; i <= n; ++i) dis[i] = inf, pre[i] = 0;
    std::queue<int> que;
    que.push(s), dis[s] = 0;
    for (; !que.empty(); que.pop()) {
      int u = que.front();
      ins[u] = 0;
      for (int i = fir[u]; i; i = nex[i])
        if (dis[got[i]] > dis[u] + cst[i] && tak[i]) {
          dis[got[i]] = dis[u] + cst[i], pre[got[i]] = i;
          if (!ins[got[i]]) que.push(got[i]), ins[got[i]] = 1;
        }
    }
    return dis[t] != inf;
  }
  inline std::pair<int, int> mincost_maxflow() {
    int flow = 0, cost = 0;
    while (bfs()) {
      int f = inf;
      for (int i = t; i != s; i = got[pre[i] ^ 1]) f = std::min(f, tak[pre[i]]);
      for (int i = t; i != s; i = got[pre[i] ^ 1])
        tak[pre[i]] -= f, tak[pre[i] ^ 1] += f;
      flow += f, cost += dis[t] * f;
    }
    return std::make_pair(flow, cost);
  }
} G;
int a[N];
int main() {
  int n = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  G.s = 2 * n + 1, G.n = G.t = 2 * n + 3;
  for (int i = 1; i <= n; ++i) {
    G.add(G.s, i, 1, 0);
    G.add(i + n, G.t, 1, 0);
    G.add(i, i + n, 1, -1);
    G.add(i, i + n, inf, 0);
    for (int j = i + 1; j <= n; ++j)
      if (a[i] == a[j] + 1) {
        G.add(i + n, j, inf, 0);
        break;
      }
    for (int j = i + 1; j <= n; ++j)
      if (a[j] == a[i] + 1) {
        G.add(i + n, j, inf, 0);
        break;
      }
    for (int j = i + 1; j <= n; ++j)
      if (a[i] % 7 == a[j] % 7) {
        G.add(i + n, j, inf, 0);
        break;
      }
  }
  G.s = 2 * n + 2;
  G.add(G.s, 2 * n + 1, 4, 0);
  std::cout << -G.mincost_maxflow().second << std::endl;
  return 0;
}
