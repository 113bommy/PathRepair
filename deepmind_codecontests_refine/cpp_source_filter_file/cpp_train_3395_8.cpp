#include <bits/stdc++.h>
const int maxn = 110;
const int maxm = 1010;
const int iinf = 1e9 + 7;
namespace flow {
const int maxv = maxn;
const int maxe = maxm << 1;
struct edge {
  int to, cap, next;
  edge() {}
  edge(int to, int cap, int next) : to(to), cap(cap), next(next) {}
} e[maxe];
int head[maxv], S, T, n, m, iter[maxv], dst[maxv], q[maxv];
bool vis[maxv];
void I(int _n, int _S, int _T) {
  n = _n;
  S = _S;
  T = _T;
  m = 0;
  memset(head, -1, sizeof(head[0]) * n);
}
inline void add_edge(int u, int v, int cap) {
  e[m] = edge(v, cap, head[u]);
  head[u] = m++;
  e[m] = edge(u, 0, head[v]);
  head[v] = m++;
  return;
}
inline int dfs(int u = S, int f = iinf) {
  if (u == T) {
    return f;
  }
  for (int &i = iter[u]; ~i; i = e[i].next) {
    if (e[i].cap && dst[e[i].to] == dst[u] + 1) {
      int F = dfs(e[i].to, std::min(f, e[i].cap));
      if (F) {
        e[i].cap -= F;
        e[i ^ 1].cap += F;
        return F;
      }
    }
  }
  return 0;
}
inline bool bfs() {
  memset(dst, -1, sizeof(dst[0]) * n);
  int fnt = 0, rar = 0;
  dst[q[rar++] = S] = 0;
  while (fnt != rar) {
    int u = q[fnt++];
    for (int i = head[u]; ~i; i = e[i].next) {
      if (e[i].cap && !~dst[e[i].to]) {
        dst[e[i].to] = dst[u] + 1;
        q[rar++] = e[i].to;
      }
    }
  }
  return ~dst[T];
}
inline void find(int u = S) {
  if (vis[u]) {
    return;
  }
  vis[u] = 1;
  for (int i = head[u]; ~i; i = e[i].next) {
    if (e[i].cap) {
      find(e[i].to);
    }
  }
  return;
}
inline int dinic() {
  int ans = 0;
  while (bfs()) {
    memcpy(iter, head, sizeof(iter[0]) * n);
    for (int f = dfs(); f; f = dfs()) {
      ans += f;
    }
  }
  find();
  return ans;
}
}  // namespace flow
int n, m, S, T, tot;
struct edge {
  int to, g, f, ful, next;
  edge() {}
  edge(int to, int g, int next) : to(to), g(g), next(next) { f = ful = 0; }
} e[maxm];
int head[maxn], rem[maxm];
bool vis[maxn];
bool dfs(int u, int T) {
  if (vis[u]) {
    return 0;
  }
  vis[u] = 1;
  if (u == T) {
    return 1;
  }
  for (int i = head[u]; ~i; i = e[i].next) {
    if (e[i].g) {
      rem[tot++] = i;
      if (dfs(e[i].to, T)) {
        return 1;
      }
      --tot;
    }
  }
  return 0;
}
int main() {
  int mm;
  scanf("%d%d%d%d", &n, &mm, &S, &T);
  --S;
  --T;
  flow::I(n, S, T);
  memset(head, -1, sizeof(head[0]) * n);
  for (int i = 0; i < mm; ++i) {
    int from, to, g;
    scanf("%d%d%d", &from, &to, &g);
    --from;
    --to;
    if (g) {
      flow::add_edge(from, to, 1);
      flow::add_edge(to, from, iinf);
    } else {
      flow::add_edge(from, to, iinf);
    }
    e[m] = edge(to, g, head[from]);
    head[from] = m++;
  }
  e[m] = edge(S, 1, head[T]);
  head[T] = m++;
  int ans = flow::dinic();
  printf("%d\n", ans);
  for (int u = 0; u < n; ++u) {
    for (int i = head[u]; ~i; i = e[i].next) {
      if (flow::vis[u] && !flow::vis[e[i].to]) {
        e[i].ful = 1;
      }
      if (e[i].g) {
        memset(vis, 0, sizeof(vis[0]) * n);
        tot = 0;
        dfs(e[i].to, u);
        for (int j = 0; j < tot; ++j) {
          ++e[j].f;
        }
        ++e[i].f;
      }
    }
  }
  for (int i = 0; i < m - 1; ++i) {
    printf("%d %d\n", e[i].f, e[i].f + 1 - e[i].ful);
  }
  return 0;
}
