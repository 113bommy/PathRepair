#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
int n;
double ans;
double inv[N];
struct Edge {
  int ce;
  int hd[N], nxt[N * 2], v[N * 2];
  void ade(int x, int y) {
    ce++;
    nxt[ce] = hd[x];
    v[ce] = y;
    hd[x] = ce;
  }
};
Edge T;
int lenc, tp;
int fa[N], dep[N], cir[N], lc[N], rc[N];
void dfsc(int u) {
  for (int i = T.hd[u]; i; i = T.nxt[i]) {
    int v = T.v[i];
    if (v == fa[u]) continue;
    if (dep[v]) {
      if (dep[v] > dep[u]) continue;
      lenc = 1;
      tp = v;
      lc[u] = 0;
      rc[u] = dep[u] - dep[v] - 1;
      cir[u] = 1;
      for (int t = u; t != v; t = fa[t]) {
        lenc++;
        lc[fa[t]] = lc[t] + 1;
        rc[fa[t]] = rc[t] - 1;
        cir[fa[t]] = 1;
      }
      cir[tp] = 0;
    } else {
      fa[v] = u;
      dep[v] = dep[u] + 1;
      dfsc(v);
    }
  }
}
void dfsa(int u, int lstc) {
  if (!lstc)
    ans += inv[dep[u]];
  else {
    int len1, len2, len3;
    if (!cir[u])
      len1 = dep[u] - dep[lstc] + 1 + lc[lstc] + dep[tp],
      len2 = len1 - lc[lstc] + rc[lstc],
      len3 = dep[u] - dep[lstc] + lenc + dep[tp] - 1;
    else
      len1 = 1 + lc[u] + dep[tp], len2 = 1 + rc[u] + dep[tp],
      len3 = lenc + dep[tp] - 1;
    ans += inv[len1] + inv[len2] - inv[len3];
  }
  if (cir[u]) lstc = u;
  for (int i = T.hd[u]; i; i = T.nxt[i]) {
    int v = T.v[i];
    if (v == fa[u] || fa[v] != u) continue;
    dfsa(v, lstc);
  }
}
void calc(int u) {
  dep[u] = 1;
  dfsc(u);
  dfsa(u, 0);
  lenc = tp = 0;
  memset(fa, 0, sizeof(dep));
  memset(dep, 0, sizeof(dep));
  memset(cir, 0, sizeof(cir));
}
int main() {
  int x, y;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d%d", &x, &y), x++, y++, T.ade(x, y), T.ade(y, x);
  for (int i = 1; i <= n; i++) inv[i] = 1.0 / i;
  for (int i = 1; i <= n; i++) calc(i);
  printf("%.12lf\n", ans);
  return 0;
}
