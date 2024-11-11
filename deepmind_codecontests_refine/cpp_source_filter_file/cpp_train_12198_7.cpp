#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return x * f;
}
inline bool char_read() {
  char ch = getchar();
  while (!isalpha(ch)) return -1;
  return ch == 'B' ? 0 : 1;
}
void Write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) Write(x / 10);
  putchar(x % 10 + 48);
}
inline void writes(long long x) { Write(x), putchar(' '); }
inline void Writes(long long x) { Write(x), putchar('\n'); }
int n, m;
int fa[205000], fa_e[205000], size[205000];
int ans[205000];
bool vis[2006000];
struct node {
  int x, y, z, id;
} E[2006000];
int head[205000], deg[205000], nxt[2006000], ver[2006000], edge[2006000],
    num[2006000], tot = 1;
int f[205000][22], maxn[205000][22], dep[205000];
queue<int> q;
void add(int x, int y, int z, int id) {
  ver[++tot] = y, nxt[tot] = head[x], head[x] = tot, edge[tot] = z,
  num[tot] = id;
}
bool cmp(const node &a, const node &b) { return a.z < b.z; }
bool ccmp(const node &a, const node &b) { return a.id < b.id; }
void Start() {
  for (int i = 1; i <= n; ++i) fa[i] = i;
}
int Get(int x) { return x == fa[x] ? x : fa[x] = Get(fa[x]); }
void Merge(int x, int y) { x = Get(x), y = Get(y), fa[x] = y; }
int GetMax(int x, int y) {
  int tmax = 0;
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 22 - 1; i >= 0; --i)
    if (dep[f[x][i]] >= dep[y]) tmax = max(maxn[x][i], tmax), x = f[x][i];
  if (x == y) return tmax;
  for (int i = 22 - 1; i >= 0; --i)
    if (f[x][i] != f[y][i])
      tmax = max(maxn[x][i], tmax), tmax = max(maxn[y][i], tmax), x = f[x][i],
      y = f[y][i];
  tmax = max(tmax, maxn[x][0]), tmax = max(tmax, maxn[y][0]);
  return tmax;
}
int Lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 22 - 1; i >= 0; --i)
    if (dep[f[x][i]] >= dep[y]) x = f[x][i];
  if (x == y) return x;
  for (int i = 22 - 1; i >= 0; --i)
    if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
  return f[x][0];
}
void dfs(int x, int in_edge) {
  fa_e[x] = in_edge;
  for (int i = head[x]; i; i = nxt[i]) {
    int y = ver[i];
    if (y == f[x][0]) continue;
    dep[y] = dep[x] + 1, f[y][0] = x, maxn[y][0] = edge[i];
    for (int j = 1; j < 22; ++j)
      f[y][j] = f[f[y][j - 1]][j - 1],
      maxn[y][j] = max(maxn[y][j - 1], maxn[f[y][j - 1]][j - 1]);
    dfs(y, i);
  }
}
signed main() {
  n = read(), m = read();
  for (int i = 1, x, y, z; i <= m; ++i)
    x = read(), y = read(), z = read(), E[i] = (node){x, y, z, i};
  sort(E + 1, E + 1 + m, cmp);
  Start();
  for (int i = 1; i <= m; ++i) {
    int x = E[i].x, y = E[i].y, z = E[i].z, id = E[i].id;
    if (Get(x) == Get(y)) continue;
    Merge(x, y), ans[id] = 1000000000;
    add(x, y, z, i), add(y, x, z, i);
  }
  dep[1] = 1, dfs(1, 0);
  Start();
  for (int i = 1; i <= m; ++i) {
    int x = E[i].x, y = E[i].y, z = E[i].z, id = E[i].id;
    if (ans[id]) continue;
    int lca = Lca(x, y);
    while (1) {
      x = Get(x);
      if (dep[x] <= dep[lca]) break;
      ans[E[num[fa_e[x]]].id] = z;
      Merge(x, f[x][0]);
    }
    while (1) {
      y = Get(y);
      if (dep[y] <= dep[lca]) break;
      ans[E[num[fa_e[y]]].id] = z;
      Merge(y, f[y][0]);
    }
  }
  sort(E + 1, E + 1 + m, ccmp);
  for (int i = 1; i <= m; ++i) {
    int x = E[i].x, y = E[i].y, z = E[i].z, id = E[i].id;
    if (ans[id])
      Writes(ans[id]);
    else
      Writes(GetMax(x, y));
  }
  return 0;
}
