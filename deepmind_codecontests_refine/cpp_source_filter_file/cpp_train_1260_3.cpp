#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = 10000007, G = 19990213;
int n, m, k, cc, fa[N], d[N], w[N][20], hd[N], ff[N * 2], po[N], ans[N],
    h[M + 5], nxt[M + 5], g[M + 5];
long long H[N], pp[N], f[M + 5];
char s[N], str[N];
struct E {
  int a, b;
  char c;
} e[N * 2];
struct st {
  long long h;
  int iv, id;
};
vector<st> t[N];
inline void add(int u, int v, char w) {
  e[++k] = (E){u, v, w};
  ff[k] = hd[u];
  hd[u] = k;
  e[++k] = (E){v, u, w};
  ff[k] = hd[v];
  hd[v] = k;
}
inline void ins(long long v, int w) {
  int x = (v % M + M) % M;
  for (int i = h[x]; i; i = nxt[i])
    if (f[i] == v) {
      g[i] += w;
      return;
    }
  f[++cc] = v;
  g[cc] = w;
  nxt[cc] = h[x];
  h[x] = cc;
}
inline int qry(long long v) {
  for (int x = (v % M + M) % M, i = h[x]; i; i = nxt[i])
    if (f[i] == v) return g[i];
  return 0;
}
void dfs1(int x) {
  w[x][0] = fa[x];
  for (int i = 1; i <= 18; i++) w[x][i] = w[w[x][i - 1]][i - 1];
  for (int i = hd[x]; i; i = ff[i])
    if (!d[e[i].b]) {
      fa[e[i].b] = x;
      s[e[i].b] = e[i].c;
      d[e[i].b] = d[x] + 1;
      dfs1(e[i].b);
    }
}
inline int lca(int x, int y) {
  if (d[x] < d[y]) swap(x, y);
  for (int i = 18; i >= 0; i--)
    if (d[w[x][i]] >= d[y]) x = w[x][i];
  if (x == y) return x;
  for (int i = 18; i >= 0; i--)
    if (w[x][i] != w[y][i]) {
      x = w[x][i];
      y = w[y][i];
    }
  return w[x][0];
}
inline int fnd(int x, int t) {
  for (int i = 18; i >= 0; i--)
    if (d[w[x][i]] >= t) x = w[x][i];
  return x;
}
inline long long gt(int l, int r) { return H[r] - H[l - 1] * pp[r - l + 1]; }
inline void qry(int x, int y, char *str, int id) {
  int p = lca(x, y), a = x, b = y, tot = 0, A, B, len = strlen(str), ps;
  long long h = 0;
  for (int i = 0; i < len; i++) h = h * G + str[i];
  if (d[x] - d[p] >= len) a = fnd(x, d[p] + len - 1);
  A = a;
  if (d[y] - d[p] >= len) b = fnd(y, d[p] + len - 1);
  B = b;
  while (a != p) po[++tot] = a, a = fa[a];
  ps = tot;
  while (a != p) po[++tot] = b, b = fa[b];
  reverse(po + ps + 1, po + tot + 1);
  for (int i = 1; i <= tot; i++) H[i] = H[i - 1] * G + s[po[i]];
  for (int i = 1; i + len - 1 <= tot; i++)
    if (gt(i, i + len - 1) == h) ans[id]++;
  if (A != x) {
    t[x].push_back((st){h, 1, id});
    t[A].push_back((st){h, -1, id});
  }
  h = 0;
  for (int i = len - 1; i >= 0; i--) h = h * G + str[i];
  if (B != y) {
    t[y].push_back((st){h, 1, id});
    t[B].push_back((st){h, -1, id});
  }
}
void dfs2(int x) {
  long long h = 0;
  for (int i = 1, p = x; i <= 100 && p; p = fa[p], i++)
    ins(h = h * G + s[p], 1);
  for (int i = 0; i < t[x].size(); i++)
    ans[t[x][i].id] += t[x][i].iv * qry(t[x][i].h);
  for (int i = hd[x]; i; i = ff[i])
    if (d[e[i].b] == d[x] + 1) dfs2(e[i].b);
  h = 0;
  for (int i = 1, p = x; i <= 100 && p; p = fa[p], i++)
    ins(h = h * G + s[p], -1);
}
int main() {
  int a, b, ps, len;
  char c;
  long long h;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) scanf("%d%d %c", &a, &b, &c), add(a, b, c);
  d[1] = 1;
  dfs1(1);
  for (int i = pp[0] = 1; i <= n; i++) pp[i] = pp[i - 1] * G;
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d%d %s", &a, &b, str), qry(a, b, str, i);
  dfs2(1);
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
