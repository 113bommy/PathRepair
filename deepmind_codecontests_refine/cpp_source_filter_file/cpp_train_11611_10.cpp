#include <bits/stdc++.h>
using namespace std;
int vis[201000], dep[201000], n, a[201000], b[201000], fa[201000], rta, rtb, O;
int cp, cq;
vector<int> G[201000], cir;
void dfs(int u, int f) {
  fa[u] = f, dep[u] = dep[f] + 1;
  for (auto v : G[u])
    if (v != f) dfs(v, u);
}
void no() {
  puts("-1");
  exit(0);
}
int lca(int u, int v) {
  while (u != v) dep[u] > dep[v] ? u = fa[u] : v = fa[v];
  return u;
}
void findcir() {
  int p = 0, q = 0;
  for (int i = 1; i <= n; ++i)
    if (a[i] != b[i] && dep[i] > dep[p]) p = i;
  if (!p) return;
  for (int i = p; i && a[i] != b[i]; i = fa[i]) cir.push_back(i), vis[i] = 1;
  for (int i = 1; i <= n; ++i)
    if (a[i] != b[i] && !vis[i] && dep[i] > dep[q]) q = i;
  if (q) {
    reverse(cir.begin(), cir.end());
    for (int i = q; i && a[i] != b[i]; i = fa[i]) cir.push_back(i), vis[i] = 1;
  } else
    q = fa[cir.back()];
  for (int i = 1; i <= n; ++i)
    if (a[i] != b[i] && !vis[i]) no();
  int lc = lca(p, q);
  if (a[lc] != b[lc]) no();
  if (cir.size() != dep[p] + dep[q] - 2 * dep[lc]) no();
  O = lc, cp = p, cq = q;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
  for (int i = 2, u, v; i <= n; ++i) {
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i)
    if (!a[i]) rta = i;
  for (int i = 1; i <= n; ++i)
    if (!b[i]) rtb = i;
  dfs(rtb, 0);
  for (int i = rta; i != rtb; i = fa[i]) swap(a[i], a[fa[i]]);
  findcir();
  if (!cir.size()) {
    printf("0 %d\n", dep[rta] - 1);
    return 0;
  }
  int mov = 0;
  for (int i = 0; i < cir.size(); ++i)
    if (a[cir[i]] == b[cir[0]]) mov = i;
  for (int i = 0; i < cir.size(); ++i)
    if (a[cir[(i + mov) % cir.size()]] != b[cir[i]]) no();
  long long ans = dep[rta] - 1;
  int len = cir.size();
  memset(vis, 0, sizeof(vis));
  for (int i = rta; i; i = fa[i]) vis[i] = 1;
  if (vis[cir[0]] || vis[cir.back()]) {
    int O = cir.size();
    for (int i = 0; i < cir.size(); ++i)
      if (!vis[cir[i]]) {
        O = i;
        break;
      }
    ans = ans - O +
          min((long long)mov * (len + 1) + O,
              abs((long long)(len - mov) * (len + 1) - O));
  } else {
    ans += (long long)min(len - mov, mov) * (len + 1);
  }
  for (; !vis[O]; O = fa[O]) ans += 2;
  if (cp > cq) swap(cp, cq);
  printf("%d %d %lld\n", cp, cq, ans);
}
