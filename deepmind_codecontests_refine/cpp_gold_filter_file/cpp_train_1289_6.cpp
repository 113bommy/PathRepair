#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 5;
char buf[1 << 12], *pp1 = buf, *pp2 = buf, nc;
int ny;
inline char gc() {
  return pp1 == pp2 &&
                 (pp2 = (pp1 = buf) + fread(buf, 1, 1 << 12, stdin), pp1 == pp2)
             ? EOF
             : *pp1++;
}
inline int read() {
  int x = 0;
  for (ny = 1; nc = gc(), (nc < 48 || nc > 57) && nc != EOF;)
    if (nc == 45) ny = -1;
  if (nc < 0) return nc;
  for (x = nc - 48; nc = gc(), 47 < nc && nc < 58 && nc != EOF;
       x = (x << 3) + (x << 1) + (nc ^ 48))
    ;
  return x * ny;
}
struct Edge {
  int x, y, w;
} e[MAXN];
int n, sz[MAXN], fa[MAXN], vis[MAXN];
long long f[MAXN], g1, g2;
vector<pair<int, int> > G[MAXN];
void dfs(int x, int f) {
  sz[x] = 1, fa[x] = f;
  for (auto y : G[x])
    if (y.first != fa[x]) dfs(y.first, x), sz[x] += sz[y.first];
}
int Sz[MAXN], Mn, N, rt;
void dfs1(int x, int fa) {
  Sz[x] = 1;
  int Mx = 0;
  for (auto y : G[x])
    if (y.first != fa)
      dfs1(y.first, x), Sz[x] += Sz[y.first], Mx = max(Mx, Sz[y.first]);
  Mx = max(Mx, N - Sz[x]), Mx < Mn ? Mn = Mx, rt = x : 0;
}
inline int GetRt(int x, int sz, int fa = 0) {
  return N = sz, Mn = 1e9, rt = 0, dfs1(x, fa), rt;
}
void dfs2(int x, int fa, long long d) {
  f[x] = d;
  for (auto y : G[x])
    if (y.first != fa && !vis[y.first])
      dfs2(y.first, x, d + y.second), f[x] += f[y.first];
}
int dfs3(int x, int fa, long long& l, int N) {
  int t = 1;
  for (auto y : G[x])
    if (!vis[y.first] && y.first != fa) {
      int tt = dfs3(y.first, x, l, N);
      t += tt, l += 1ll * tt * (N - tt) * y.second;
    }
  return t;
}
int main() {
  n = read();
  for (int i = 1; i <= n - 1; i++) {
    int x = read(), y = read(), w = read();
    e[i] = (Edge){x, y, w}, G[x].emplace_back(y, w), G[y].emplace_back(x, w);
  }
  dfs(1, 0);
  long long ans = 1e18;
  for (int i = 1; i <= n - 1; i++) {
    int x = e[i].x, y = e[i].y, w = e[i].w, u, v, a, b;
    if (x == fa[y])
      u = GetRt(x, n - sz[y], y), a = n - sz[y], v = GetRt(y, sz[y], x),
      b = sz[y];
    else
      u = GetRt(x, sz[x], y), a = sz[x], v = GetRt(y, n - sz[x], x),
      b = n - sz[x];
    long long tmp = 0;
    vis[x] = 0, vis[y] = 1, vis[x] = 0, vis[y] = 1, dfs2(u, 0, 0),
    dfs3(u, 0, tmp, a), vis[x] = 1, vis[y] = 0, dfs2(v, 0, 0),
    dfs3(v, 0, tmp, b), vis[x] = vis[y] = 0;
    tmp += f[u] * b + f[v] * a + 1ll * a * b * w, ans = min(ans, tmp);
  }
  cout << ans << '\n';
  return 0;
}
