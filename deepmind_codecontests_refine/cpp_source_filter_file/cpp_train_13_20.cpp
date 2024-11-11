#include <bits/stdc++.h>
const int N = 200005;
int n, m, t = -1, he, ta, sg[N], d[N], s[N], q[N];
bool vis[N];
long long h[N];
struct ed {
  ed* nxt;
  int to;
} pool[N], *p = pool, *lnk[N];
void ae(int u, int v) { *++p = (ed){lnk[u], v}, ++d[v], lnk[u] = p; }
void dfs(int u) {}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (n); ++i) scanf("%lld", h + i);
  for (int i = (1); i <= (m); ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    ae(u, v);
  }
  for (int i = (1); i <= (n); ++i)
    if (!d[i]) q[++ta] = i;
  while (he != ta) {
    int u = q[++he];
    for (ed* i = lnk[u]; i; i = i->nxt)
      if (!--d[i->to]) q[++ta] = i->to;
  }
  for (int i = (n); i >= (1); --i) {
    int u = q[i];
    for (ed* i = lnk[u]; i; i = i->nxt) vis[sg[i->to]] = 1;
    while (vis[sg[u]]) ++sg[u];
    for (ed* i = lnk[u]; i; i = i->nxt) vis[sg[i->to]] = 0;
    s[sg[u]] ^= h[u];
  }
  for (int i = (1); i <= (n); ++i)
    if (s[i]) t = i;
  if (t == -1) return 0 & puts("LOSE");
  for (int i = (1); i <= (n); ++i) {
    if (sg[i] == t && ((h[i] ^ s[t]) < h[i])) {
      h[i] ^= s[t];
      for (ed* j = lnk[i]; j; j = j->nxt) {
        h[j->to] ^= s[sg[j->to]];
        s[sg[j->to]] = 0;
      }
      break;
    }
  }
  puts("WIN");
  for (int i = (1); i <= (n); ++i) printf("%lld ", h[i]);
  return 0;
}
