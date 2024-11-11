#include <bits/stdc++.h>
using namespace std;
template <typename T>
void r1(T &x) {
  x = 0;
  char c(getchar());
  int f(1);
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  x *= f;
}
const int maxn = 100000 + 5;
const int maxm = maxn << 1;
typedef int room[maxn];
int n, m, d;
int dis[maxn], f[maxn][2];
int head[maxn], cnt;
struct Edge {
  int to, next;
} edg[maxn << 1];
void add(int u, int v) { edg[++cnt] = (Edge){v, head[u]}, head[u] = cnt; }
int vis[maxn];
void dfs(int p, int fa) {
  if (vis[p]) f[p][0] = 0;
  for (int i = head[p]; i; i = edg[i].next) {
    int to = edg[i].to;
    if (to == fa) continue;
    dfs(to, p);
    if (f[to][0] + 1 > f[p][0]) {
      f[p][1] = f[p][0], f[p][0] = f[to][0] + 1;
    } else
      f[p][1] = max(f[p][1], f[to][0] + 1);
  }
}
void dfs1(int p, int fa) {
  for (int i = head[p]; i; i = edg[i].next) {
    int to = edg[i].to;
    if (to == fa) continue;
    if (f[p][0] == f[to][0] + 1) {
      dis[to] = max(f[p][1] + 1, dis[p] + 1);
    } else
      dis[to] = max(dis[p] + 1, f[p][0] + 1);
    dfs1(to, p);
  }
}
signed main() {
  int i, j;
  memset(f, -0x3f, sizeof(f)), memset(dis, -0x3f, sizeof(dis));
  r1(n), r1(m), r1(d);
  for (i = 1; i <= m; ++i) {
    int x;
    r1(x);
    vis[x] = 1;
  }
  for (i = 1; i < n; ++i) {
    int u, v;
    r1(u), r1(v);
    add(u, v), add(v, u);
  }
  dfs(1, 0), dfs1(1, 0);
  int ans((bool)(f[1][1] <= d && f[1][0] <= d));
  for (i = 2; i <= n; ++i)
    if (dis[i] <= d && f[i][0] <= d) {
      ++ans;
    }
  printf("%d\n", ans);
  return 0;
}
