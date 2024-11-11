#include <bits/stdc++.h>
using namespace std;
const int N = 50005;
int n, m;
int p[N], a[N];
struct LCT {
  int fa[N], ch[N][2], siz[N], sv[N];
  long long sv2[N], sav[N], san[N], sa[N];
  int nroot(int u) { return ch[fa[u]][0] == u || ch[fa[u]][1] == u; }
  void pushup(int u) {
    siz[u] = siz[ch[u][0]] + siz[ch[u][1]] + sv[u];
    san[u] = san[ch[u][0]] + san[ch[u][1]] + 1ll * a[u] * siz[u];
    sa[u] =
        sa[ch[u][0]] + sa[ch[u][1]] + sav[u] +
        (1ll * sv[u] * sv[u] - sv2[u] + 2ll * siz[ch[u][1]] * sv[u]) * a[u] +
        2 * san[ch[u][0]] * (siz[ch[u][1]] + sv[u]);
  }
  void rot(int u) {
    int v = fa[u], t = fa[v], d = (u == ch[v][1]);
    if (nroot(v)) ch[t][v == ch[t][1]] = u;
    fa[u] = t;
    fa[ch[u][d ^ 1]] = v;
    ch[v][d] = ch[u][d ^ 1];
    fa[v] = u;
    ch[u][d ^ 1] = v;
    pushup(v);
    pushup(u);
  }
  void splay(int u) {
    while (nroot(u)) {
      int v = fa[u];
      if (nroot(v)) rot(u == ch[v][1] ^ v == ch[fa[v]][1] ? u : v);
      rot(u);
    }
  }
  int access(int u) {
    int v = 0;
    for (; u; v = u, u = fa[u]) {
      splay(u);
      sv[u] += siz[ch[u][1]] - siz[v];
      sv2[u] += 1ll * siz[ch[u][1]] * siz[ch[u][1]] - 1ll * siz[v] * siz[v];
      sav[u] += sa[ch[u][1]] - sa[v];
      ch[u][1] = v;
      pushup(u);
    }
    return v;
  }
  int lca(int u, int v) {
    access(u);
    return access(v);
  }
  void makeroot(int u) {
    access(u);
    splay(u);
  }
  void Link(int u, int v) {
    makeroot(u);
    makeroot(v);
    fa[u] = v;
    sv[v] += siz[u];
    sv2[v] += 1ll * siz[u] * siz[u];
    sav[v] += sa[u];
    pushup(v);
  }
  void Cut(int u, int v) {
    access(u);
    splay(v);
    ch[v][1] = fa[u] = 0;
    pushup(v);
  }
} lt;
void query() {
  lt.splay(1);
  printf("%.12lf\n", 1.0 * lt.sa[1] / n / n);
}
int main() {
  int x, y;
  char ty;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) scanf("%d", p + i);
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i), lt.siz[i] = lt.sv[i] = 1, lt.san[i] = lt.sa[i] = a[i];
  for (int i = 2; i <= n; i++) lt.Link(i, p[i]);
  scanf("%d", &m);
  query();
  while (m--) {
    do ty = getchar();
    while (ty != 'P' && ty != 'V');
    scanf("%d%d", &x, &y);
    if (ty == 'P') {
      if (lt.lca(x, y) == x) swap(x, y);
      lt.Cut(x, p[x]);
      lt.Link(x, p[x] = y);
    } else
      lt.makeroot(x), a[x] = y, lt.pushup(x);
    query();
  }
  return 0;
}
