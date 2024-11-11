#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const long long M = 998244353;
int n, k, u, v, a[N];
int dep[N], fa[N][20];
long long dp[N][2];
vector<int> G[N], vc[N];
void dfs(int u, int f, int d) {
  fa[u][0] = f;
  dep[u] = d;
  for (int i = 1; i < 20; i++) {
    fa[u][i] = fa[fa[u][i - 1]][i - 1];
  }
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v != f) dfs(v, u, d + 1);
  }
}
int get_lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 19; i >= 0; i--) {
    if (dep[fa[u][i]] >= dep[v]) {
      u = fa[u][i];
    }
  }
  for (int i = 19; i >= 0; i--) {
    if (fa[u][i] != fa[v][i]) {
      u = fa[u][i];
      v = fa[v][i];
    }
  }
  if (u != v) u = fa[u][0];
  return u;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  long long d = a;
  if (b != 0) {
    d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}
long long mod_inv(long long a, long long m) {
  long long x, y;
  exgcd(a, m, x, y);
  return (m + x % m) % m;
}
void dfs2(int u, int f) {
  long long tmp = 1;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == f) continue;
    dfs2(v, u);
    tmp *= (dp[v][0] + dp[v][1]);
    tmp %= M;
  }
  if (a[u] == 0) {
    dp[u][0] = tmp;
    dp[u][1] = 0;
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if (v == f) continue;
      long long x = tmp * mod_inv(dp[v][0] + dp[v][1], M);
      x = x * dp[v][1] % M;
      dp[u][1] += x;
    }
    dp[u][1] %= M;
  } else {
    dp[u][0] = 0;
    dp[u][1] = tmp;
  }
}
void pt() {
  for (int i = 1; i <= n; i++) {
    printf("a[%d]=%d\n", i, a[i]);
  }
}
long long solve() {
  for (int i = 1; i <= k; i++) {
    int lca = vc[i][0];
    for (int j = 0; j < vc[i].size(); j++) {
      int u = vc[i][j];
      lca = get_lca(lca, u);
    }
    for (int j = 0; j < vc[i].size(); j++) {
      int u = vc[i][j];
      if (u == lca) continue;
      int v = u;
      while (v != lca) {
        v = fa[v][0];
        if (a[v] != 0 && a[v] != i) return 0;
        if (a[v] == i) break;
        a[v] = i;
      }
    }
  }
  dfs2(1, 0);
  return dp[1][1];
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    vc[a[i]].push_back(i);
  }
  for (int i = 1; i < n; i++) {
    scanf("%d %d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, 0, 1);
  printf("%lld\n", solve());
}
