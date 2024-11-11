#include <bits/stdc++.h>
using namespace std;
int Read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int first[200005], nxt[200005], to[200005], w[200005], tot;
void Add(int x, int y, int z) {
  nxt[++tot] = first[x];
  first[x] = tot;
  to[tot] = y;
  w[tot] = z;
}
int n, q, lst, maxn, mpos, s, num, du[100005], d[100005];
void dfs(int u, int fa) {
  if (d[u] > maxn) maxn = d[u], mpos = u;
  for (int e = first[u]; e; e = nxt[e]) {
    int v = to[e];
    if (v == fa) continue;
    d[v] = d[u] + w[e];
    dfs(v, u);
  }
}
struct node {
  int rt, dep[100005], mdep[100005], top[100005], son[100005], rnk[100005],
      sum[100005];
  int f[100005][20], g[100005][20];
  vector<pair<int, int> > ss;
  void dfs1(int u, int fa) {
    for (int i = 1; i < 20; i++) f[u][i] = f[f[u][i - 1]][i - 1];
    for (int i = 1; i < 20; i++) g[u][i] = g[u][i - 1] + g[f[u][i - 1]][i - 1];
    for (int e = first[u]; e; e = nxt[e]) {
      int v = to[e];
      if (v == fa) continue;
      mdep[v] = dep[v] = dep[u] + w[e];
      g[v][0] = w[e], f[v][0] = u;
      dfs1(v, u);
      mdep[u] = max(mdep[u], mdep[v]);
      if (mdep[v] > mdep[son[u]]) son[u] = v;
    }
  }
  void dfs2(int u, int tp) {
    top[u] = tp;
    if (son[u]) dfs2(son[u], tp);
    for (int e = first[u]; e; e = nxt[e])
      if (!top[to[e]]) dfs2(to[e], to[e]);
  }
  void init(int x) {
    rt = x;
    dfs1(x, 0);
    dfs2(x, x);
    for (int i = 1; i <= n; i++)
      if (top[i] == i) ss.push_back(make_pair(-(mdep[i] - dep[i]), i));
    sort(ss.begin(), ss.end());
    for (int i = 0; i < (int)ss.size(); i++) {
      rnk[ss[i].second] = i + 1;
      sum[i + 1] = sum[i] - ss[i].first;
    }
    for (int i = (int)ss.size(); i <= n; i++) sum[i + 1] = sum[i];
    for (int i = 1; i <= n; i++) {
      if (top[i] != i) continue;
      int xx = i;
      while (xx) {
        rnk[xx] = rnk[i];
        xx = son[xx];
      }
    }
  }
  int solve1(int x, int y) {
    int nw = x, res = mdep[x] - dep[x];
    for (int i = 19; ~i; i--)
      if (f[nw][i] && rnk[f[nw][i]] >= y) res += g[nw][i], nw = f[nw][i];
    return sum[y - 1] + f[nw][0] + res;
  }
  int solve2(int x, int y) {
    int nw = x, res = mdep[x] - dep[x];
    for (int i = 19; ~i; i--)
      if (f[nw][i] && rnk[f[nw][i]] > y) res += g[nw][i], nw = f[nw][i];
    return sum[y] + g[nw][0] + res - (mdep[f[nw][0]] - dep[f[nw][0]]);
  }
  int query(int x, int y) {
    y = 2 * y - 1;
    return rnk[x] <= y ? sum[y] : max(solve1(x, y), solve2(x, y));
  }
} T[2];
signed main() {
  n = Read(), q = Read();
  for (int i = 1; i < n; i++) {
    int x = Read(), y = Read(), z = Read();
    s += z;
    Add(x, y, z);
    Add(y, x, z);
    ++du[x], ++du[y];
  }
  for (int i = 1; i <= n; i++)
    if (du[i] == 1) ++num;
  dfs(1, 0);
  T[0].init(mpos);
  memset(d, 0, sizeof(d));
  maxn = 0, dfs(mpos, 0);
  T[1].init(mpos);
  for (int i = 1; i <= q; i++) {
    int x = (Read() + lst - 1) % n + 1, y = (Read() + lst - 1) % n + 1;
    printf("%d\n", 2 * y >= num
                       ? lst = s
                       : lst = max(T[0].query(x, y), T[1].query(x, y)));
  }
  return 0;
}
