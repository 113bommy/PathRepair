#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  bool f = true;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = false;
    c = getchar();
  }
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return f ? x : -x;
}
const int INF = 0x3f3f3f3f;
const int N = 300010;
const int M = 300010;
int head[N], tot;
struct node {
  int nxt, to;
} edge[M << 1];
inline void adde(int u, int v) {
  edge[++tot].nxt = head[u], edge[tot].to = v, head[u] = tot;
}
int sz[N], mson[N], f[N], maxsz[N];
inline int get(int rt, int u) { return max(sz[rt] - sz[u], maxsz[u]); }
void dfs(int u) {
  sz[u] = 1;
  for (register int e = head[u]; e; e = edge[e].nxt) {
    int v = edge[e].to;
    dfs(v), sz[u] += sz[v], maxsz[u] = max(maxsz[u], sz[v]);
  }
  int msize = INF;
  mson[u] = u;
  for (register int e = head[u]; e; e = edge[e].nxt) {
    int v = edge[e].to;
    int now = mson[v];
    while (get(u, f[now]) < get(u, now) && f[now] != u) now = f[now];
    if (get(u, now) < msize) mson[u] = now, msize = get(u, now);
  }
}
int n, q;
inline void Init() {
  n = read(), q = read();
  for (register int i = 2; i <= n; ++i) {
    f[i] = read();
    adde(f[i], i);
  }
}
int main() {
  Init();
  dfs(1);
  for (register int i = 1; i <= q; ++i) {
    int u = read();
    printf("%d\n", mson[u]);
  }
  return 0;
}
