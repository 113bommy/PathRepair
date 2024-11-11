#include <bits/stdc++.h>
using namespace std;
const int max_n = 200005;
const int max_m = 25;
struct edge {
  int to, next, cost;
} es[2 * max_n];
int cnt = 0;
int head[2 * max_n];
void add(int u, int v) {
  es[cnt].to = v;
  es[cnt].next = head[u];
  es[cnt].cost = 1;
  head[u] = cnt++;
}
int depth[max_n << 1];
int first[max_n << 1];
int dir[max_n << 1];
int que[max_n << 1];
int dp[max_n][20];
bool vis[max_n];
int tot = 0;
void dfs(int u, int dep) {
  vis[u] = true;
  que[++tot] = u;
  first[u] = tot;
  depth[tot] = dep;
  for (int k = head[u]; k != -1; k = es[k].next) {
    int v = es[k].to, cost = es[k].cost;
    if (!vis[v]) {
      dir[v] = dir[u] + cost;
      dfs(v, dep + 1);
      que[++tot] = u;
      depth[tot] = dep;
    }
  }
}
void ST(int n) {
  for (int i = 1; i <= n; i++) dp[i][0] = i;
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      int a = dp[i][j - 1], b = dp[i + (1 << (j - 1))][j - 1];
      dp[i][j] = depth[a] < depth[b] ? a : b;
    }
  }
}
int RMQ(int l, int r) {
  int k = 0;
  while ((1 << (k + 1)) <= r - l + 1) k++;
  int a = dp[l][k], b = dp[r - (1 << k) + 1][k];
  return depth[a] < depth[b] ? a : b;
}
int LCA(int u, int v) {
  int x = first[u], y = first[v];
  if (x > y) swap(x, y);
  int res = RMQ(x, y);
  return que[res];
}
int x[max_n];
int main() {
  int p, q;
  int n;
  for (int i = 0; i < max_n; i++) {
    head[i] = -1;
    vis[i] = false;
  }
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    scanf("%d", x + i);
    add(i, x[i]);
    add(x[i], i);
  }
  dfs(1, 1);
  ST(2 * n - 1);
  int da = 1, db = 2;
  int d = 1;
  int degree[max_n << 1];
  printf("1 ");
  memset(degree, 0, sizeof(degree));
  degree[1] = degree[2] = 1;
  for (int i = 3; i <= n; i++) {
    if (degree[x[i]] == 1) {
      int lca1 = LCA(i, da);
      int tmp1 = dir[i] + dir[da] - 2 * dir[lca1];
      int lca2 = LCA(i, db);
      int tmp2 = dir[i] + dir[db] - 2 * dir[lca2];
      if (tmp1 < tmp2) {
        if (tmp2 > d) {
          da = i;
          d = tmp2;
        }
      } else {
        if (tmp1 > d) {
          db = i;
          d = tmp1;
        }
      }
    }
    printf("%d ", d);
    degree[x[i]]++;
    degree[i]++;
  }
  return 0;
}
