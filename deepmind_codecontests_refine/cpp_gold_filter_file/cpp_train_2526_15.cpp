#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct edge {
  int to;
  edge *nxt;
} * arc[maxn], pool[maxn << 1], *pt;
int n, a, b, da, db, len, r;
int g[maxn];
int getint() {
  char ch;
  int res = 0, p;
  while (!isdigit(ch = getchar()) && (ch ^ '-'))
    ;
  p = ch == '-' ? ch = getchar(), -1 : 1;
  while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
  return res * p;
}
void addedge(int u, int v) {
  *pt = (edge){v, arc[u]};
  arc[u] = pt++;
}
void dfs(int x, int tfa, int dep) {
  if (x == b) len = dep;
  g[x] = 0;
  int maxl = -1;
  for (edge *e = arc[x]; e; e = e->nxt)
    if (e->to != tfa) {
      dfs(e->to, x, dep + 1);
      r = max(r, maxl + g[e->to] + 2);
      maxl = max(maxl, g[e->to]);
    }
  g[x] = maxl + 1;
}
int main() {
  int kase;
  kase = getint();
  while (kase--) {
    n = getint();
    a = getint();
    b = getint();
    da = getint();
    db = getint();
    pt = pool;
    for (int i = 1; i <= n; ++i) arc[i] = 0;
    for (int i = 1; i <= n - 1; ++i) {
      int u, v;
      u = getint();
      v = getint();
      addedge(u, v);
      addedge(v, u);
    }
    r = 0;
    dfs(a, 0, 0);
    printf((da >= len || 2 * da >= r || 2 * da >= db) ? "Alice\n" : "Bob\n");
  }
  return 0;
}
