#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 9;
const long long mod = 998244353;
vector<int> g[N];
int n, m;
namespace dsu {
int fa[N], v[N];
int find(int x) {
  if (fa[x] == x) return x;
  int f = fa[x];
  fa[x] = find(fa[x]);
  v[x] ^= v[f];
  return fa[x];
}
void build() {
  for (int i = (1); i < (n + 1); ++i) fa[i] = i;
}
void merge(int x, int y, int vv) {
  int fx = find(x), fy = find(y);
  if (fx == fy) {
    if (v[x] ^ v[y] ^ vv) {
      printf("-1");
      exit(0);
    }
  } else {
    fa[fx] = fy;
    v[fx] = v[x] ^ v[y] ^ vv;
  }
}
}  // namespace dsu
namespace TR {
int S[N], SS[N], fa[N];
int top[N], pos[N];
int dfn[N], dep[N], sz[N];
void dfs(int u) {
  sz[u] = 1;
  for (auto v : g[u]) {
    if (v == fa[u]) continue;
    fa[v] = u;
    dep[v] = dep[u] + 1;
    dfs(v);
    sz[u] += sz[v];
  }
}
void dfs2(int u, int tp) {
  top[u] = tp;
  dfn[u] = ++*dfn;
  pos[*dfn] = u;
  int k = 0;
  for (auto v : g[u]) {
    if (v == fa[u]) continue;
    if (sz[v] > sz[k]) k = v;
  }
  if (k) dfs2(k, tp);
  for (auto v : g[u]) {
    if (v == fa[u] || v == k) continue;
    dfs2(v, v);
  }
}
int LCA(int u, int v) {
  for (; top[u] != top[v]; u = fa[top[u]]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
  }
  return dep[u] < dep[v] ? u : v;
}
int jmp(int x, int f) {
  for (;;) {
    if (dep[top[x]] <= dep[f]) return pos[dfn[f] + 1];
    if (dep[top[x]] == dep[f] + 1) return top[x];
    x = fa[top[x]];
  }
}
void build() {
  dfs(1);
  dfs2(1, 1);
}
void build2() {
  for (int i = (n + 1) - 1; i >= (1); --i) {
    int u = pos[i];
    S[fa[u]] += S[u];
    SS[fa[u]] += SS[u];
    if (SS[u]) dsu::merge(u, fa[u], 0);
  }
}
void connect(int u, int v) {
  int f = LCA(u, v);
  ++S[u], ++S[v], S[f] -= 2;
  if (dep[f] ^ dep[u]) ++SS[u], --SS[u = jmp(u, f)];
  if (dep[f] ^ dep[v]) ++SS[v], --SS[v = jmp(v, f)];
  if ((u ^ f) && (v ^ f)) dsu::merge(u, v, 1);
}
}  // namespace TR
int v0[N], v1[N], dp[N];
int vis[N], T, tag[N];
int cc[N], q[N];
bool check(int K) {
  for (int i = (n + 1) - 1; i >= (1); --i) {
    ++T, *q = 0;
    int u = TR::pos[i], f = TR::fa[u];
    int vl = 0, vr = 0;
    for (auto v : g[u]) {
      if (v == f || !TR::S[v]) continue;
      int x = dsu::fa[v];
      if (vis[x] != T) vis[x] = T, v0[x] = 0, v1[x] = 0, q[++*q] = x;
      if (!dsu::v[v])
        v0[x] = max(v0[x], dp[v]);
      else
        v1[x] = max(v1[x], dp[v]);
    }
    if (vis[dsu::fa[u]] == T) {
      int x = dsu::fa[u];
      vl = v0[x], vr = v1[x];
      if (dsu::v[u]) swap(vl, vr);
    }
    int vmn = 0, vmx = 0;
    for (int j = (1); j < ((*q) + 1); ++j) {
      if (dsu::fa[u] != q[j]) {
        if (v0[q[j]] > v1[q[j]]) swap(v0[q[j]], v1[q[j]]);
        vmn = max(vmn, v0[q[j]]);
        vmx = max(vmx, v1[q[j]]);
      }
    }
    if (max(vmn, min(vl, vr)) + max(vmx, max(vl, vr)) >= K) return 0;
    dp[u] =
        (max(vmn, vl) + max(vmx, vr) >= K ? max(vmx, vl) : max(vmn, vl)) + 1;
  }
  return 1;
}
void construct(int K) {
  for (int i = (1); i < (n + 1); ++i) {
    ++T;
    *q = 0;
    int u = TR::pos[i], f = TR::fa[u];
    for (auto v : g[u]) {
      if (v == f || !TR::S[v]) continue;
      int x = dsu::fa[v];
      if (vis[x] != T) vis[x] = T, v0[x] = 0, v1[x] = 0, q[++*q] = x;
      if (!dsu::v[v])
        v0[x] = max(v0[x], dp[v]);
      else
        v1[x] = max(v1[x], dp[v]);
    }
    for (int j = (1); j < ((*q) + 1); ++j) {
      cc[q[j]] = tag[u];
      if (dsu::fa[u] != q[j])
        cc[q[j]] ^= (v0[q[j]] > dp[u] - 1 || v1[q[j]] + dp[u] > K);
      else
        cc[q[j]] ^= dsu::v[u];
    }
    for (auto v : g[u]) {
      if (v == f || !TR::S[v]) continue;
      tag[v] = cc[dsu::fa[v]] ^ dsu::v[v];
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i < (n); ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dsu::build();
  TR::build();
  for (int i = (0); i < (m); ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    TR::connect(u, v);
  }
  TR::build2();
  for (int i = (1); i < (n + 1); ++i) dsu::find(i);
  int l = 1, r = n;
  while (l < r) {
    int mid = l + r >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", l);
  check(l);
  construct(l);
  for (int i = (1); i < (n + 1); ++i)
    printf("%d ", tag[i] ? l + 1 - dp[i] : dp[i]);
}
