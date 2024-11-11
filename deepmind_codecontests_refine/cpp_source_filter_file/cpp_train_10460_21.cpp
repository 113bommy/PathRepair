#include <bits/stdc++.h>
using namespace std;
const long long N = 1000005;
long long n, m;
vector<long long> g[N];
long long dep[N], fa[N][20], siz[N];
void dfs(long long p, long long from) {
  siz[p] = 1;
  for (auto q : g[p]) {
    if (q != from) {
      dep[q] = dep[p] + 1;
      fa[q][0] = p;
      dfs(q, p);
      siz[p] += siz[q];
    }
  }
}
void presolve() {
  dep[1] = 1;
  dfs(1, 0);
  for (long long j = 1; j < 20; j++)
    for (long long i = 1; i <= n; i++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
}
long long lca(long long p, long long q) {
  if (dep[p] < dep[q]) swap(p, q);
  for (long long i = 19; i >= 0; i--)
    if (dep[fa[p][i]] >= dep[q]) p = fa[p][i];
  for (long long i = 19; i >= 0; i--)
    if (fa[p][i] != fa[q][i]) {
      p = fa[p][i];
      q = fa[q][i];
    }
  if (p != q) return fa[p][0];
  return p;
}
long long jump(long long p, long long depth) {
  for (long long i = 19; i >= 0; i--)
    if (dep[fa[p][i]] >= depth) p = fa[p][i];
  return p;
}
bool check_mid(long long u, long long v) { return (dep[u] + dep[v]) % 2 == 0; }
long long mid(long long u, long long v) {
  long long l = lca(u, v);
  if (l == v) {
    long long depth = (dep[u] + dep[v]) / 2;
    return jump(u, depth);
  } else {
    long long len = dep[u] + dep[v] - 2 * dep[l];
    long long depth = dep[u] - len / 2;
    return jump(u, depth);
  }
}
long long get_rela_child(long long p, long long q) {
  return jump(q, dep[p] + 1);
}
signed main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (long long i = 1; i < n; i++) {
    long long u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  presolve();
  cin >> m;
  for (long long i = 1; i <= m; i++) {
    long long u, v;
    cin >> u >> v;
    if (dep[u] < dep[v]) swap(u, v);
    long long l = lca(u, v);
    long long ans = 0;
    if (u == v) {
      ans = n;
    } else if (check_mid(u, v)) {
      long long c = mid(u, v);
      if (l == c) {
        long long rela_u = get_rela_child(c, u);
        long long rela_v = get_rela_child(c, v);
        ans = siz[l] - siz[rela_u] - siz[rela_v];
      } else {
        long long rela_u = get_rela_child(c, u);
        ans = siz[c] - siz[rela_u];
      }
    }
    cout << ans << endl;
  }
}
