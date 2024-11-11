#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn = 1000010;
struct node {
  int to, nxt;
} tr[maxn];
int head[maxn], tot = 0;
int f[maxn][2], F[maxn];
inline void addedge(int u, int v) {
  tr[++tot].nxt = head[u];
  tr[tot].to = v;
  head[u] = tot;
}
int rt = 1;
int siz[maxn];
bool vis[maxn];
int ans = (1 << 30);
void dfs1(int u, int fa) {
  siz[u] = 1;
  int res = 0;
  for (int i = head[u]; i; i = tr[i].nxt) {
    int to = tr[i].to;
    if (fa == to) continue;
    dfs1(to, u);
    siz[u] += siz[to];
    res = max(res, siz[to]);
  }
  res = max(res, n - siz[u]);
  if (res < ans) {
    ans = res;
    rt = u;
  }
}
void dfs2(int u, int fa) {
  siz[u] = 1;
  for (int i = head[u]; i; i = tr[i].nxt) {
    int to = tr[i].to;
    if (to == fa) continue;
    dfs2(to, u);
    siz[u] += siz[to];
    if (siz[to] > f[u][0]) {
      f[u][1] = f[u][0];
      f[u][0] = siz[to];
    } else if (siz[to] > f[u][1])
      f[u][1] = siz[to];
  }
}
void dfs3(int u, int fa) {
  if (f[fa][0] == siz[u])
    F[u] = max(f[fa][1], F[fa]);
  else
    F[u] = max(f[fa][0], F[fa]);
  if (n - siz[u] <= n / 2) F[u] = max(F[u], n - siz[u]);
  if (u == rt) F[u] = 0;
  for (int i = head[u]; i; i = tr[i].nxt) {
    int to = tr[i].to;
    if (to == fa) continue;
    dfs3(to, u);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    addedge(x, y);
    addedge(y, x);
  }
  dfs1(1, 0);
  memset(siz, 0, sizeof siz);
  dfs2(rt, 0);
  dfs3(rt, 0);
  for (int i = 1; i <= n; i++) {
    if (siz[i] >= n / 2 || n - siz[i] - F[i] <= n / 2)
      printf("1 ");
    else
      printf("0 ");
  }
  return 0;
}
