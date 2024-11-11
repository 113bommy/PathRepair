#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int head[N], c[N], cnt, n, m, fa[N][22], dep[N], dfn[N], ed[N], tot, dp[N];
struct node {
  int x, y, z;
};
struct edge {
  int next, to;
} e[N << 1];
void add(int u, int v) {
  e[++cnt].next = head[u];
  e[cnt].to = v;
  head[u] = cnt;
}
int lowbit(int x) { return x & -x; }
void update(int x, int val) {
  for (; x <= n; x += lowbit(x)) c[x] += val;
}
int get_sum(int x) {
  int ans = 0;
  for (; x; x -= lowbit(x)) ans += c[x];
  return ans;
}
vector<node> V[N];
void dfs(int u, int f) {
  fa[u][0] = f;
  dep[u] = dep[f] + 1;
  dfn[u] = ++tot;
  for (int i = 1; i <= 19; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (int i = head[u]; i; i = e[i].next) dfs(e[i].to, u);
  ed[u] = tot;
}
int LCA(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int tmp = dep[u] - dep[v];
  for (int i = 0; (1 << i) <= tmp; i++)
    if ((tmp >> i) & 1) u = fa[u][i];
  if (u == v) return u;
  for (int i = 19; i >= 0; i--)
    if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
  return fa[u][0];
}
void dfs1(int u) {
  int sum = 0;
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    dfs1(v);
    sum += dp[v];
  }
  dp[u] = sum;
  for (auto it : V[u]) {
    dp[u] = max(dp[u], it.z + get_sum(dfn[it.x]) + get_sum(dfn[it.y]) + sum);
  }
  update(dfn[u], -dp[u] + sum);
  update(ed[u] + 1, dp[u] - sum);
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 2; i <= n; i++) {
    int x;
    scanf("%d", &x);
    add(x, i);
  }
  dfs(1, 0);
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    V[LCA(x, y)].push_back({x, y, z});
  }
  dfs1(1);
  cout << dp[1];
  return 0;
}
