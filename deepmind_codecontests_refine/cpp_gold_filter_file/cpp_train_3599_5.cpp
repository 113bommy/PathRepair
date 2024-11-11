#include <bits/stdc++.h>
using namespace std;
int xr = 1124971;
inline int R() {
  xr = (1ll * (xr ^ 1297131) * 182791 + 12987941) % 1000000007;
  return xr;
}
int n, m, Q, K, tot = 0, S, T, a[1006][1006], h[1000012], cnt = 0, h1[3311031],
                cn1 = 0, f[1000012], cn = 0, c[1006 << 3], num;
bool vi[1000012];
unsigned long long w1[1000012];
char sc[1012];
struct Edge {
  int to, next;
} e[1000012 * 6];
struct Ed {
  pair<int, int> to;
  int next;
} e1[1000012 * 6];
inline void AddEdge(int x, int y) {
  e[++cnt] = (Edge){y, h[x]};
  h[x] = cnt;
  e[++cnt] = (Edge){x, h[y]};
  h[y] = cnt;
}
inline void Add(int x, int y) {
  if (!vi[x]) c[++num] = x, vi[x] = 1;
  e[++cnt] = (Edge){y, h[x]};
  h[x] = cnt;
  if (!vi[y]) c[++num] = y, vi[y] = 1;
  e[++cnt] = (Edge){x, h[y]};
  h[y] = cnt;
}
void dfs(int x) {
  f[x] = cn;
  int i, y;
  for (i = h[x]; i; i = e[i].next)
    if (!f[y = e[i].to]) dfs(y);
}
struct has {
  inline void Ins(unsigned long long x, pair<int, int> p) {
    int v = x % 3311031, i;
    for (i = h1[v]; i; i = e1[i].next)
      if (e1[i].to == p) return;
    e1[++cn1] = (Ed){p, h1[v]};
    h1[v] = cn1;
  }
  inline bool Fin(unsigned long long x, pair<int, int> p) {
    int v = x % 3311031, i;
    for (i = h1[v]; i; i = e1[i].next)
      if (e1[i].to == p) return true;
    return false;
  }
} ha;
int tm[12], nu, A[127], t1, B[127], t2;
bool vis[1000012];
void dfs1(int x, int *V, int &sz) {
  vis[V[++sz] = x] = 1;
  int i, y;
  for (i = h[x]; i; i = e[i].next)
    if (!vis[y = e[i].to]) dfs1(y, V, sz);
}
int main() {
  scanf("%d%d%d", &n, &m, &Q);
  S = ++tot;
  T = ++tot;
  int i, j, k, w, x, y;
  bool fl;
  for (i = 1; i < n; i++)
    for (j = 1; j < m; j++) a[i][j] = ++tot;
  for (i = 0; i <= n; i++) a[i][0] = S, a[i][m] = T;
  for (i = 0; i <= m; i++) a[0][i] = T, a[n][i] = S;
  for (i = 1; i <= n; i++) {
    scanf("%s", sc + 1);
    for (j = 1; j <= m; j++)
      if (sc[j] == '#')
        AddEdge(a[i][j], a[i - 1][j]), AddEdge(a[i][j], a[i][j - 1]),
            AddEdge(a[i][j], a[i - 1][j - 1]);
  }
  for (i = 1; i <= tot; i++)
    if (!f[i]) w1[++cn] = 1ull * R() * R() * R(), dfs(i);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      if (((i == 1) && (j == 1)) || ((i == n) && (j == m))) continue;
      nu = 0;
      tm[++nu] = f[a[i - 1][j - 1]];
      tm[++nu] = f[a[i - 1][j]];
      tm[++nu] = f[a[i][j - 1]];
      tm[++nu] = f[a[i][j]];
      for (k = 1; k <= nu; k++)
        for (w = 1; w <= nu; w++)
          if (tm[k] < tm[w])
            ha.Ins(w1[tm[k]] ^ w1[tm[w]], make_pair(tm[k], tm[w]));
    }
  memset(h, 0, sizeof(h));
  cnt = 0;
  while (Q--) {
    scanf("%d", &K);
    while (K--) {
      scanf("%d%d", &x, &y);
      Add(f[a[x][y]], f[a[x - 1][y]]), Add(f[a[x][y]], f[a[x][y - 1]]),
          Add(f[a[x][y]], f[a[x - 1][y - 1]]);
    }
    fl = true;
    t1 = t2 = 0;
    dfs1(f[S], A, t1);
    if (vis[f[T]]) fl = false;
    if (fl) dfs1(f[T], B, t2);
    for (i = 1; (i <= t1) && fl; i++)
      for (j = 1; (j <= t2) && fl; j++)
        if (ha.Fin(w1[A[i]] ^ w1[B[j]],
                   make_pair(min(A[i], B[j]), max(A[i], B[j]))))
          fl = false;
    printf("%s\n", fl ? "YES" : "NO");
    fflush(stdout);
    for (i = 1; i <= num; i++) x = c[i], vi[x] = vis[x] = 0, h[x] = 0;
    cnt = 0;
    num = 0;
    vis[f[S]] = vis[f[T]] = 0;
  }
  return 0;
}
