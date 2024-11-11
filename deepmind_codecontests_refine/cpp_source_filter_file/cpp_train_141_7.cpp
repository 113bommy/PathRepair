#include <bits/stdc++.h>
using namespace std;
const int maxn = 1111;
int num[maxn];
int tot;
int head[maxn];
int vis[maxn];
int sum;
int dp[maxn][maxn];
int tt;
int pos;
int tot2;
int head2[maxn];
void init() {
  tot = 0;
  memset(head, -1, sizeof(head));
  tot2 = 0;
  memset(head2, -1, sizeof(head2));
  memset(vis, 0, sizeof(vis));
  tt = 0;
}
struct {
  int v, next;
} edge[maxn * maxn], edge2[maxn * maxn];
void add(int u, int v) {
  edge[tot].v = v;
  edge[tot].next = head[u];
  head[u] = tot++;
}
void dfs(int u) {
  vis[u] = 1;
  sum++;
  int i, v;
  for (i = head[u]; i != -1; i = edge[i].next) {
    v = edge[i].v;
    if (!vis[v]) dfs(v);
  }
}
void add2(int u, int v) {
  edge2[tot2].v = v;
  edge2[tot2].next = head2[u];
  head2[u] = tot2++;
}
void dfs2(int u) {
  sum++;
  int i, v;
  for (i = head2[u]; i != -1; i = edge2[i].next) {
    v = edge2[i].v;
    dfs(v);
  }
}
int main() {
  int i, j, n, m;
  int a;
  while (scanf("%d%d", &n, &m) != EOF) {
    init();
    tt = 0;
    for (i = 1; i <= n; i++) {
      scanf("%d", &a);
      if (a) {
        add(i, a);
        add(a, i);
        add2(i, a);
      }
    }
    sum = 0;
    dfs(m);
    sum = 0;
    dfs2(m);
    pos = sum;
    for (i = 1; i <= n; i++) {
      sum = 0;
      if (!vis[i]) {
        dfs(i);
        num[++tt] = sum;
      }
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (i = 1; i <= n; i++) {
      for (j = 0; j <= n; j++) {
        dp[i][j] = dp[i - 1][j];
        if (!dp[i][j] && j - num[i] >= 0) {
          dp[i][j] = dp[i - 1][j - num[i]];
        }
      }
    }
    for (i = 0; i <= n; i++) {
      for (j = 0; j <= n; j++) {
        if (dp[j][i] == 1) {
          printf("%d\n", i + pos);
          break;
        }
      }
    }
  }
  return 0;
}
