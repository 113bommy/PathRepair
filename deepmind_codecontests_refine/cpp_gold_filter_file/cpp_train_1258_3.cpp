#include <bits/stdc++.h>
using namespace std;
int n, m;
struct edge {
  int from;
  int to;
  long long len;
  int next;
} E[300005 << 1];
int head[300005];
int size = 0;
void add_edge(int u, int v, long long w) {
  size++;
  E[size].from = u;
  E[size].to = v;
  E[size].len = w;
  E[size].next = head[u];
  head[u] = size;
}
int log2n;
long long val[300005];
int deep[300005];
long long dis[300005];
int anc[300005][32];
long long dp1[300005];
long long dp2[300005];
long long dp3[300005][32];
long long sumv[300005];
void dfs1(int x, int fa) {
  dp1[x] = val[x];
  anc[x][0] = fa;
  deep[x] = deep[fa] + 1;
  for (int i = 1; i <= log2n; i++) {
    anc[x][i] = anc[anc[x][i - 1]][i - 1];
  }
  for (int i = head[x]; i; i = E[i].next) {
    int y = E[i].to;
    if (y != fa) {
      dis[y] = dis[x] + E[i].len;
      sumv[y] = sumv[x] + val[E[i].to];
      dfs1(y, x);
      dp1[x] += max(dp1[y] - 2LL * E[i].len, 0LL);
    }
  }
}
void dfs2(int x, int fa) {
  for (int i = head[x]; i; i = E[i].next) {
    int y = E[i].to;
    if (y != fa) {
      dp3[y][0] = dp1[x] - max(dp1[y] - 2LL * E[i].len, 0LL) - val[x];
      for (int j = 1; j <= log2n; j++) {
        dp3[y][j] = dp3[y][j - 1] + dp3[anc[y][j - 1]][j - 1];
      }
      dp2[y] = max(dp2[x] + dp3[y][0] + val[x] - 2LL * E[i].len, 0LL);
      dfs2(y, x);
    }
  }
}
int lca(int x, int y) {
  if (x == 1 || y == 1) return 1;
  if (deep[x] < deep[y]) swap(x, y);
  for (int i = log2n; i >= 0; i--) {
    if (deep[anc[x][i]] >= deep[y]) {
      x = anc[x][i];
    }
  }
  if (x == y) return x;
  for (int i = log2n; i >= 0; i--) {
    if (anc[x][i] != anc[y][i]) {
      x = anc[x][i];
      y = anc[y][i];
    }
  }
  return anc[x][0];
}
long long get_ans(int x, int y) {
  long long ans = 0;
  if (deep[x] < deep[y]) swap(x, y);
  int tx = x, ty = y;
  if (tx == ty) return dp1[x] + dp2[x];
  int l = lca(x, y);
  if (l == y) {
    for (int i = log2n; i >= 0; i--) {
      if (deep[anc[x][i]] >= deep[l]) {
        ans += dp3[x][i];
        x = anc[x][i];
      }
    }
    ans += (sumv[tx] - sumv[y]) - (dis[tx] - dis[y]) + val[y] + dp1[tx] -
           val[tx] + dp2[y];
    return ans;
  } else {
    for (int i = log2n; i >= 0; i--) {
      if (deep[anc[x][i]] > deep[l]) {
        ans += dp3[x][i];
        x = anc[x][i];
      }
    }
    for (int i = log2n; i >= 0; i--) {
      if (deep[anc[y][i]] > deep[l]) {
        ans += dp3[y][i];
        y = anc[y][i];
      }
    }
    long long d1 = sumv[tx] - sumv[anc[x][0]] - dis[tx] + dis[anc[x][0]];
    long long d2 = sumv[ty] - sumv[anc[y][0]] - dis[ty] + dis[anc[y][0]];
    long long subtree_1 = dp1[tx] - val[tx];
    long long subtree_2 = dp1[ty] - val[ty];
    long long subtree_3 = dp2[l] + dp1[l] - val[l] -
                          max(dp1[x] - 2 * (dis[x] - dis[anc[x][0]]), 0LL) -
                          max(dp1[y] - 2 * (dis[y] - dis[anc[y][0]]), 0LL);
    ans += d1 + d2 + val[l] + subtree_1 + subtree_2 + subtree_3;
    return ans;
  }
}
int main() {
  int u, v;
  long long w;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &val[i]);
  }
  for (int i = 1; i < n; i++) {
    scanf("%d %d %I64d", &u, &v, &w);
    add_edge(u, v, w);
    add_edge(v, u, w);
  }
  deep[1] = 1;
  log2n = log2(n) + 1;
  dfs1(1, 0);
  dfs2(1, 0);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &u, &v);
    printf("%I64d\n", get_ans(u, v));
  }
}
