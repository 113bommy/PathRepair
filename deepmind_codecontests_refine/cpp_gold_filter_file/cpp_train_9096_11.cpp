#include <bits/stdc++.h>
using namespace std;
struct edge {
  int v, nxt, c;
} e[1500005];
int p[53005], eid, pp[53005];
void init() {
  memset(p, -1, sizeof p);
  eid = 0;
}
void insert(int u, int v, int c) {
  e[eid].v = v;
  e[eid].c = c;
  e[eid].nxt = p[u];
  p[u] = eid++;
}
void add(int u, int v, int c) {
  insert(u, v, c);
  insert(v, u, 0);
}
int d[53005], S, T, n, m, b, k, a[53005], g;
queue<int> q;
int bfs() {
  for (int i = 1; i <= T + 5; i++) pp[i] = p[i], d[i] = -1;
  d[S] = 0;
  q.push(S);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int i = p[u]; i + 1; i = e[i].nxt) {
      int v = e[i].v, c = e[i].c;
      if (d[v] == -1 && c) {
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
  }
  return d[T] != -1;
}
int dfs(int u, int flow) {
  if (u == T) return flow;
  int ret = 0;
  for (int &i = pp[u]; i + 1; i = e[i].nxt) {
    int v = e[i].v, c = e[i].c;
    if (c && d[v] == d[u] + 1) {
      int tmp = dfs(v, min(flow, c));
      e[i].c -= tmp, e[i ^ 1].c += tmp;
      flow -= tmp, ret += tmp;
      if (!flow) break;
    }
  }
  if (!ret) d[u] = -1;
  return ret;
}
int Dinic() {
  int ret = 0;
  for (; bfs();) ret += dfs(S, 23333333);
  return ret;
}
int main() {
  init();
  scanf("%d%d%d", &n, &m, &g);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  S = n + m + 1, T = S + 1;
  for (int i = 1; i <= n; i++) {
    int x = 0;
    scanf("%d", &x);
    if (a[i])
      add(i, T, x);
    else
      add(S, i, x);
  }
  int ans = 0;
  for (int id = n + 1; id <= n + m; id++) {
    int opt, w, gs;
    scanf("%d%d%d", &opt, &w, &gs);
    if (opt) {
      for (int i = 1; i <= gs; i++) {
        int x = 0;
        scanf("%d", &x);
        add(x, id, 23333333);
      }
      scanf("%d", &opt);
      add(id, T, w + opt * g);
    } else {
      for (int i = 1; i <= gs; i++) {
        int x = 0;
        scanf("%d", &x);
        add(id, x, 23333333);
      }
      scanf("%d", &opt);
      add(S, id, w + opt * g);
    }
    ans += w;
  }
  printf("%d", ans - Dinic());
  return 0;
}
