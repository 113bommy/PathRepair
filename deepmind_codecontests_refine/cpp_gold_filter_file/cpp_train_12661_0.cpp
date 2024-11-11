#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
map<int, int> M;
int g[500], h[500], u[10], v[10], x[500], y[500];
bool b[500], z[10];
int i, j, k, m, n, s, w;
inline int getsize(int x) {
  int l = x, r = x, t = 0;
  for (; l <= n; l = l << 1, r = min(r << 1 | 1, n)) t = t + r - l + 1;
  return t;
}
inline bool go(int u, int v, bool c) {
  int x, y;
  x = u, y = v;
  bool d = true;
  while (x != y) {
    if (x < y) swap(x, y);
    d = d && (c != b[M[x]]);
    x = x >> 1;
  }
  d = d && (c != b[M[x]]);
  if (!d) return d;
  x = u, y = v;
  while (x != y) {
    if (x < y) swap(x, y);
    b[M[x]] = c;
    x = x >> 1;
  }
  b[M[x]] = c;
  return d;
}
inline void dfsV(int x, int y) {
  if (!M[x]) return;
  if (b[M[x]]) return;
  b[M[x]] = true;
  s = (s + 1LL * h[M[x]] * y) % p;
  dfsV(x >> 1, y);
  dfsV(x << 1, y);
  dfsV(x << 1 | 1, y);
  b[M[x]] = false;
  return;
}
inline void dfsU(int x, int y) {
  if (!M[x]) return;
  if (b[M[x]]) return;
  b[M[x]] = true;
  dfsV(v[w], y * h[M[x]]);
  dfsU(x >> 1, y);
  dfsU(x << 1, y);
  dfsU(x << 1 | 1, y);
  b[M[x]] = false;
  return;
}
inline void dfs(int o) {
  if (o > 1) dfsU(u[1], 1);
  w++;
  for (int i = 1; i <= m; i++)
    if (!z[i]) {
      z[i] = true;
      u[w] = x[i], v[w] = y[i];
      if ((o == 1) || (go(v[w - 1], u[w], true))) {
        dfs(o + 1);
        if (o > 1) go(v[w - 1], u[w], false);
      }
      u[w] = y[i], v[w] = x[i];
      if ((o == 1) || (go(v[w - 1], u[w], true))) {
        dfs(o + 1);
        if (o > 1) go(v[w - 1], u[w], false);
      }
      z[i] = false;
    }
  w--;
  return;
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &x[i], &y[i]);
    for (j = x[i]; j; j = j >> 1)
      if (!M[j]) k++, g[k] = j, M[j] = k;
    for (j = y[i]; j; j = j >> 1)
      if (!M[j]) k++, g[k] = j, M[j] = k;
  }
  for (i = 1; i <= k; i++) {
    h[i] = getsize(g[i]);
    if (M[g[i] << 1]) h[i] = h[i] - getsize(g[i] << 1);
    if (M[g[i] << 1 | 1]) h[i] = h[i] - getsize(g[i] << 1 | 1);
  }
  s = 1LL * n * n % p;
  dfs(1);
  printf("%d", s);
  return 0;
}
