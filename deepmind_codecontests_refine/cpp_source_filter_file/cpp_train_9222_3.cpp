#include <bits/stdc++.h>
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool flag = false;
  while (!isdigit(c)) {
    if (c == '-') flag = true;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
  if (flag) x = -x;
}
using namespace std;
const int P = 1e9 + 7;
inline void ADD(long long &a, long long b) {
  a += b;
  if (a >= P) a -= P;
}
int n;
int pri[201000], phi[201000], pcnt, mu[201000];
bool depri[201000];
long long inv[201000];
inline void init() {
  const int up = n + 5;
  depri[1] = true;
  phi[1] = mu[1] = 1;
  for (int i = 2; i <= up; ++i) {
    if (!depri[i]) pri[++pcnt] = i, phi[i] = i - 1, mu[i] = -1;
    for (int j = 1; j <= pcnt && i * pri[j] <= up; ++j) {
      depri[i * pri[j]] = true;
      if (i % pri[j] == 0) {
        phi[i * pri[j]] = phi[i] * pri[j];
        break;
      }
      phi[i * pri[j]] = phi[i] * (pri[j] - 1);
      mu[i * pri[j]] = -mu[i];
    }
  }
  inv[1] = 1;
  for (int i = 2; i <= up; ++i) inv[i] = (P - P / i) * inv[P % i] % P;
}
int a[201000], pos[201000];
struct edge {
  int nxt, to;
  edge() {}
  edge(int jzp, int zzz) { nxt = jzp, to = zzz; }
} e[201000 << 1];
int head[201000], ecnt;
inline void addedge(int from, int to) {
  e[++ecnt] = edge(head[from], to);
  head[from] = ecnt;
}
int dep[201000], siz[201000], son[201000], fa[201000];
void dfs_son(int cur, int faa) {
  fa[cur] = faa, dep[cur] = dep[faa] + 1, siz[cur] = 1;
  int mx = 0;
  for (int i = head[cur]; i; i = e[i].nxt) {
    int to = e[i].to;
    if (to == faa) continue;
    dfs_son(to, cur);
    siz[cur] += siz[to];
    if (siz[to] > mx) mx = siz[to], son[cur] = to;
  }
}
int top[201000], dfn[201000], dcnt;
void dfs_chain(int cur, int topp) {
  top[cur] = topp, dfn[cur] = ++dcnt;
  if (!son[cur]) return;
  dfs_chain(son[cur], topp);
  for (int i = head[cur]; i; i = e[i].nxt) {
    int to = e[i].to;
    if (to == fa[cur] || to == son[cur]) continue;
    dfs_chain(to, to);
  }
}
inline int get_lca(int x, int y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    x = fa[top[x]];
  }
  return dep[x] < dep[y] ? x : y;
}
long long F[201000];
int h[201000], htot;
bool isimp[201000];
bool cmp(const int x, const int y) { return dfn[x] < dfn[y]; }
vector<int> ve[201000];
inline void aded(int u, int v) { ve[u].push_back(v); }
int stk[201000], stop;
inline void ins(int cur) {
  int lca = get_lca(cur, stk[stop]);
  while (stop > 1 && dep[lca] <= dep[stk[stop - 1]])
    aded(stk[stop - 1], stk[stop]), --stop;
  if (lca != stk[stop]) aded(lca, stk[stop]), stk[stop] = lca;
  stk[++stop] = cur;
}
long long nwres;
long long f[201000], g[201000];
void dfs(int cur) {
  if (isimp[cur])
    f[cur] = phi[a[cur]], g[cur] = phi[a[cur]] * dep[cur] % P;
  else
    f[cur] = 0, g[cur] = 0;
  for (unsigned int i = 0; i < ve[cur].size(); ++i) {
    int to = ve[cur][i];
    dfs(to);
    nwres += (g[to] * f[cur] + f[to] * g[cur] -
              2ll * dep[cur] * f[to] % P * f[cur]) %
             P;
    ADD(g[cur], g[to]);
    ADD(f[cur], f[to]);
  }
  ve[cur].clear();
  isimp[cur] = false;
}
inline void calc(int t) {
  htot = 0;
  nwres = 0;
  for (int i = 1; i * t <= n; ++i)
    h[++htot] = pos[i * t], isimp[h[htot]] = true;
  sort(h + 1, h + 1 + htot, cmp);
  stk[stop = 1] = 1;
  for (int i = 1; i <= htot; ++i)
    if (h[i] > 1) ins(h[i]);
  while (stop > 1) aded(stk[stop - 1], stk[stop]), --stop;
  dfs(1);
  F[t] = nwres * 2 % P;
}
int main() {
  read(n);
  init();
  for (int i = 1; i <= n; ++i) read(a[i]), pos[a[i]] = i;
  for (int i = 1; i < n; ++i) {
    int u, v;
    read(u), read(v);
    addedge(u, v), addedge(v, u);
  }
  dfs_son(1, 0), dfs_chain(1, 1);
  for (int i = 1; i <= n; ++i) calc(i);
  long long ans = 0;
  for (int g = 1; g <= n; ++g) {
    for (int d = 1; d * g <= n; ++d) {
      ans += g * mu[d] % P * inv[phi[g]] % P * F[d * g] % P;
    }
  }
  printf("%lld\n", (ans % P * inv[n] % P * inv[n - 1] % P + P) % P);
  return 0;
}
