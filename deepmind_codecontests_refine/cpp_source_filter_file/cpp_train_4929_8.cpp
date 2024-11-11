#include <bits/stdc++.h>
using namespace std;
const int Inf = 100000000;
const int Len = 61;
int cost[Len][Len];
int dis[Len][Len];
int n, m, Q;
int dp[Len][Len][Len];
void floyd() {
  int i, j, k;
  for (k = 1; k <= n; k++) {
    for (i = 1; i <= n; i++) {
      if (i != k)
        for (j = 1; j <= n; j++) {
          if (j != k && j != i) {
            if (cost[i][k] + cost[k][j] < cost[i][j])
              cost[i][j] = cost[i][k] + cost[k][j];
          }
        }
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], cost[i][j]);
  }
}
struct P {
  int v, changes, mcost;
  P() {}
  P(int a, int b, int c) {
    v = a;
    changes = b;
    mcost = c;
  }
};
void cal(int s) {
  int i, j, k;
  queue<P> q;
  for (i = 1; i <= n; i++)
    if (i != s) {
      q.push(P(i, 0, dis[s][i]));
    }
  while (!q.empty()) {
    P pt = q.front();
    q.pop();
    if (pt.changes >= Len) continue;
    for (i = 1; i <= n; i++) {
      if (dp[s][i][pt.changes + 1] > pt.mcost + dis[pt.v][i]) {
        dp[s][i][pt.changes + 1] = pt.mcost + dis[pt.v][i];
        q.push(P(i, pt.changes + 1, dp[s][i][pt.changes + 1]));
      }
    }
  }
}
int main() {
  int i, j, k;
  while (~scanf("%d%d%d", &n, &m, &Q)) {
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++)
        if (i == j)
          dis[i][j] = 0;
        else
          dis[i][j] = Inf;
    for (i = 0; i < m; i++) {
      for (j = 1; j <= n; j++) {
        for (k = 1; k <= n; k++) {
          scanf("%d", &cost[j][k]);
        }
      }
      floyd();
    }
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++) {
        dp[i][j][0] = dis[i][j];
        for (k = 1; k < Len; k++) dp[i][j][k] = Inf;
      }
    for (i = 1; i <= n; i++) {
      cal(i);
    }
    while (Q--) {
      int u, v, K;
      scanf("%d%d%d", &u, &v, &K);
      if (K > Len - 1) K = Len - 1;
      printf("%d\n", dp[u][v][K]);
    }
  }
  return 0;
}
