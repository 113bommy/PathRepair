#include <bits/stdc++.h>
template <typename T>
bool Chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool Chkmin(T &x, T y) {
  return y < x ? x = y, true : false;
}
template <typename T>
void Readin(T &x) {
  x = 0;
  int c = getchar(), k = 1;
  for (; '0' > c || c > '9'; c = getchar())
    if (c == '-') k = -1;
  for (; '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  x *= k;
}
const int MAXN = 1e5 + 1e3, MAXM = MAXN, oo = 0x3f3f3f3f;
int n;
int head[MAXN];
int next[MAXM * 2], to[MAXM * 2];
int deep[MAXN];
int dfn[MAXN];
int rank[MAXN];
namespace FLca {
const int MAXSIZE = MAXN * 3, MAXD = 20;
int tot;
int minv[MAXN];
int st[MAXSIZE][MAXD];
int log2[MAXSIZE];
void Dfs(int u) {
  st[++tot][0] = dfn[u];
  minv[u] = tot;
  for (int i = head[u]; i; i = next[i]) {
    int v = to[i];
    if (minv[v] == 0) {
      Dfs(v);
      st[++tot][0] = dfn[u];
    }
  }
}
inline int Lca(int u, int v) {
  int l = minv[u], r = minv[v];
  if (l > r) std::swap(l, r);
  int d = log2[r - l + 1];
  return rank[std::min(st[l][d], st[r - (1 << d) + 1][d])];
}
void Init() {
  tot = 0;
  Dfs(1);
  for (int i = 1, j = 0; i <= tot; i++) {
    while ((1 << j) <= i) j++;
    log2[i] = j - 1;
  }
  for (int j = 1, _ = MAXD - 1; j <= _; j++)
    for (int i = 1, _ = tot; i <= _; i++) {
      if (i + (1 << j) > tot) break;
      st[i][j] = std::min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
}
}  // namespace FLca
namespace VT {
int root;
int fa[MAXN];
int pre[MAXN], bro[MAXN];
int ok[MAXN];
int dp[MAXN];
int vis[MAXN];
int Dp(int u) {
  if (!ok[u]) {
    int totc = 0;
    for (int v = pre[u]; v; v = bro[v]) {
      dp[u] += Dp(v);
      if (ok[v]) ++totc;
    }
    ok[u] = (totc == 1);
    dp[u] += (totc > 1);
  } else {
    for (int v = pre[u]; v; v = bro[v]) {
      dp[u] += Dp(v);
      if (ok[v] == 1) ++dp[u];
    }
  }
  return dp[u];
}
inline bool Cmp(const int &x, const int &y) { return dfn[x] < dfn[y]; }
int Exec(int a[], int m) {
  static int st[MAXN * 2], tmp[MAXN * 2];
  int top = 0, tot = 0;
  std::sort(a + 1, a + m + 1, Cmp);
  for (int i = 1, _ = m; i <= _; i++) {
    int u = a[i], lca = FLca::Lca(st[top], u);
    tmp[++tot] = u, tmp[++tot] = lca;
    while (top && deep[lca] < deep[st[top]]) {
      if (deep[st[top - 1]] <= deep[lca]) fa[st[top]] = lca;
      --top;
    }
    if (lca != st[top]) fa[lca] = st[top], st[++top] = lca;
    if (u != st[top]) fa[u] = st[top], st[++top] = u;
  }
  for (int i = 1, _ = tot; i <= _; i++) {
    int u = tmp[i];
    if (vis[u]) continue;
    vis[u] = true;
    if (fa[u] == 0) {
      root = u;
      continue;
    }
    bro[u] = pre[fa[u]];
    pre[fa[u]] = u;
  }
  for (int i = 1, _ = m; i <= _; i++) ok[a[i]] = true;
  int ans = 0;
  for (int i = 1, _ = m; i <= _; i++) {
    int u = a[i];
    if (ok[fa[u]] && deep[fa[u]] == deep[u] - 1) ans = -1;
  }
  if (ans != -1) ans = Dp(root);
  for (int i = 1, _ = tot; i <= _; i++) {
    int u = tmp[i];
    vis[u] = pre[u] = bro[u] = dp[u] = ok[u] = fa[u] = 0;
  }
  return ans;
}
}  // namespace VT
void AddEdge(int u, int v) {
  static int tote;
  ++tote;
  to[tote] = v;
  next[tote] = head[u];
  head[u] = tote;
}
void Dfs(int u, int d) {
  static int dfsclock;
  ++dfsclock;
  rank[dfsclock] = u;
  dfn[u] = dfsclock;
  deep[u] = d;
  for (int i = head[u]; i; i = next[i]) {
    int v = to[i];
    if (!dfn[v]) Dfs(v, d + 1);
  }
}
void Solve() {
  static int a[MAXN];
  int q, m;
  Readin(q);
  while (q--) {
    Readin(m);
    for (int i = 1, _ = m; i <= _; i++) Readin(a[i]);
    printf("%d\n", VT::Exec(a, m));
  }
}
void Init() {
  Readin(n);
  for (int i = 1, _ = n - 1; i <= _; i++) {
    int u, v;
    Readin(u), Readin(v);
    AddEdge(u, v);
    AddEdge(v, u);
  }
  Dfs(1, 1);
  FLca::Init();
}
int main() {
  if (fopen("D.in", "r") != NULL) {
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
  }
  Init();
  Solve();
  return 0;
}
