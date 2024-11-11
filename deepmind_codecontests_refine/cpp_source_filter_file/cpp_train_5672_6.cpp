#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long k = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch <= '9' && ch >= '0') k = k * 10 + ch - 48, ch = getchar();
  return k;
}
const int maxn = 1e5 + 5;
int n, m, id[maxn];
int h[maxn], cnt;
struct d {
  int to, next, dis;
} a[maxn * 2];
inline void add(int x, int y, int z) {
  a[++cnt] = (d){y, h[x], z};
  h[x] = cnt;
}
long long f[maxn], dis[maxn], Dis = 1e18;
int rt, p1, p2, p3, vis[maxn];
bool cmp(int x, int y) { return f[x] < f[y]; }
void dfs1(int x, int fa) {
  if (dis[x] > dis[rt]) rt = x;
  f[x] = max(f[x], dis[x]);
  for (int i = h[x]; i; i = a[i].next) {
    if (a[i].to == fa) continue;
    dis[a[i].to] = dis[x] + a[i].dis;
    dfs1(a[i].to, x);
  }
}
void dfs2(int x, int fa) {
  for (int i = h[x]; i; i = a[i].next) {
    if (a[i].to == fa) continue;
    dis[a[i].to] = dis[x] + a[i].dis;
    dfs2(a[i].to, x);
    vis[x] |= vis[a[i].to];
  }
  if (max(dis[p1] - dis[x], dis[x]) <= Dis)
    p3 = x, Dis = max(dis[p1] - dis[x], dis[x]);
}
int fa[maxn];
void dfs(int x, int father) {
  fa[x] = father;
  for (int i = h[x]; i; i = a[i].next) {
    if (a[i].to == fa[x]) continue;
    dfs(a[i].to, x);
  }
}
int pr[maxn], sz[maxn];
int Get(int x) { return x == pr[x] ? x : pr[x] = Get(pr[x]); }
void Merge(int x, int y) {
  int fx = Get(x), fy = Get(y);
  if (fx == fy) return;
  pr[fx] = fy;
  sz[fy] += sz[fx];
}
void Solve() {
  int ans = 0;
  long long len = read();
  int r = n, l = n, x;
  for (int i = 1; i <= n; ++i) pr[i] = i, sz[i] = 0;
  for (r = n; r >= 1; --r) {
    while (l >= 1 && f[id[r]] - f[id[l]] <= len) {
      x = id[l];
      sz[x] = 1;
      --l;
      for (int i = h[x]; i; i = a[i].next)
        if (a[i].to != fa[x]) Merge(a[i].to, x);
    }
    x = Get(id[r]);
    ans = max(ans, sz[x]);
    --sz[x];
  }
  cout << ans << '\n';
}
int main() {
  n = read();
  int x, y, z;
  for (int i = 1; i < n; ++i) {
    x = read();
    y = read();
    z = read();
    add(x, y, z);
    add(y, x, z);
  }
  dis[1] = 0;
  dfs1(1, 0);
  p1 = rt;
  dis[p1] = 0;
  dfs1(p1, 0);
  p2 = rt;
  dis[p2] = 0;
  dfs1(p2, 0);
  vis[p2] = 1;
  dfs2(p2, 0);
  dfs(p3, 0);
  m = read();
  for (int i = 1; i <= n; ++i) id[i] = i;
  sort(id + 1, id + 1 + n, cmp);
  for (int i = 1; i <= m; ++i) Solve();
  return 0;
}
