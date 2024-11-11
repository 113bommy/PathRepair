#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, LOG = 22;
const long long INF = 2e18;
int n;
int ecnt, root = 1, edge[N << 1], nxt[N << 1], head[N], fat[N][LOG], son[N];
long long f[N], g[N], h[N], ans = INF;
char buf[1 << 21], *p1 = buf, *p2 = buf;
template <typename T>
inline T read() {
  char tmp =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
           ? EOF
           : *p1++);
  T sum = 0;
  bool flag = false;
  while (tmp < '0' || tmp > '9') {
    if (tmp == '-') flag = true;
    tmp =
        (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
             ? EOF
             : *p1++);
  }
  while (tmp >= '0' && tmp <= '9') {
    sum = (sum << 1) + (sum << 3) + tmp - '0';
    tmp =
        (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
             ? EOF
             : *p1++);
  }
  return flag ? -sum : sum;
}
void dfs1(int u, int fa) {
  fat[u][0] = fa;
  for (register int i = 1; i <= 20; ++i) fat[u][i] = fat[fat[u][i - 1]][i - 1];
  for (register int i = head[u]; i; i = nxt[i]) {
    int v = edge[i];
    if (v == fa) continue;
    dfs1(v, u);
    h[u] += f[v] + 1;
    f[u] += h[v];
    son[u]++;
  }
}
void dfs2(int u, int fa, int dep) {
  switch (dep) {
    case 1:
      g[u] = 0;
      break;
    case 2:
      g[u] = h[1] - (f[u] + 1);
      break;
    case 3:
      g[u] = -(f[u] + 1) + f[root] + 1;
      break;
    default:
      g[u] = h[fat[u][0]] - (f[u] + 1) + g[fat[u][1]] + f[fat[u][1]] -
             h[fat[u][0]] + 1;
      break;
  }
  for (register int i = head[u]; i; i = nxt[i])
    if (edge[i] != fa) dfs2(edge[i], u, dep + 1);
}
inline void insert(int from, int to, int id) {
  nxt[id] = head[from];
  head[from] = id;
  edge[id] = to;
}
int main() {
  n = read<int>();
  for (register int i = 1; i <= n - 1; ++i) {
    int u = read<int>(), v = read<int>();
    insert(u, v, ++ecnt);
    insert(v, u, ++ecnt);
  }
  dfs1(1, 1);
  dfs2(1, 1, 1);
  for (register int i = 1; i <= n; ++i) ans = min(ans, f[i] + g[i]);
  printf("%lld\n", ans);
  return 0;
}
