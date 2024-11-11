#include <bits/stdc++.h>
using namespace std;
const int RLEN = 1 << 20 | 1;
inline char gc() {
  static char ibuf[RLEN], *ib, *ob;
  (ib == ob) && (ob = (ib = ibuf) + fread(ibuf, 1, RLEN, stdin));
  return (ib == ob) ? EOF : *ib++;
}
inline int read() {
  char ch = gc();
  int res = 0;
  bool f = 1;
  while (!isdigit(ch)) f ^= ch == '-', ch = gc();
  while (isdigit(ch)) res = (res + (res << 2) << 1) + (ch ^ 48), ch = gc();
  return f ? res : -res;
}
inline long long readll() {
  char ch = gc();
  long long res = 0;
  bool f = 1;
  while (!isdigit(ch)) f ^= ch == '-', ch = gc();
  while (isdigit(ch)) res = (res + (res << 2) << 1) + (ch ^ 48), ch = gc();
  return f ? res : -res;
}
inline int readstring(char *s) {
  int top = 0;
  char ch = gc();
  while (isspace(ch)) ch = gc();
  while (!isspace(ch) && ch != EOF) s[++top] = ch, ch = gc();
  return top;
}
template <typename tp>
inline void chemx(tp &a, tp b) {
  a < b ? a = b : 0;
}
template <typename tp>
inline void chemn(tp &a, tp b) {
  a > b ? a = b : 0;
}
const int N = 205, M = 5005;
int con[2][M * 2][505];
int d[2][N], id[2][N];
int E[N][N], ans[M], bel[M];
int n1, n2, m, k, lim, tot;
void dfs(int pos, int u, int v, int cu, int cv) {
  int t = con[pos ^ 1][v][cu];
  con[pos ^ 1][v][cu] = u;
  con[pos][u][cu] = v;
  if (!t) {
    con[pos ^ 1][v][cv] = 0;
    return;
  }
  dfs(pos ^ 1, v, t, cv, cu);
}
int main() {
  n1 = read(), n2 = read(), m = read(), k = read();
  for (int i = 1; i <= n1; i++) id[0][i] = ++tot, bel[tot] = i;
  for (int i = 1; i <= n2; i++) id[1][i] = ++tot, bel[tot] = i;
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    E[u][v] = i;
    if (d[0][u] == k) d[0][u] = 0, id[0][u] = ++tot, bel[tot] = u;
    d[0][u]++, u = id[0][u];
    if (d[1][v] == k) d[1][v] = 0, id[1][v] = ++tot, bel[tot] = v;
    d[1][v]++, v = id[1][v];
    int cu = 1, cv = 1;
    while (con[0][u][cu]) cu++;
    while (con[1][v][cv]) cv++;
    chemx(lim, max(cu, cv));
    if (cu == cv)
      con[0][u][cu] = v, con[1][v][cv] = u;
    else
      dfs(0, u, v, cu, cv);
  }
  int res = 0;
  for (int i = 1; i <= n1; i++)
    if (d[0][i] != k && d[0][i] != 0) res++;
  for (int j = 1; j <= n2; j++)
    if (d[1][j] != k && d[1][j] != 0) res++;
  cout << res << '\n';
  for (int i = 1; i <= tot; i++)
    for (int j = 1; j <= lim; j++)
      if (con[0][i][j]) ans[E[bel[i]][bel[con[0][i][j]]]] = j;
  for (int i = 1; i <= m; i++) cout << ans[i] << " ";
}
