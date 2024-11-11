#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int maxm = 110;
const int inf = 1e9;
int d[maxn][maxm];
vector<int> G[maxn];
vector<int> E[maxn];
int n, ans[maxn];
void bfs(int x) {
  queue<int> que;
  for (int i = 0; i < E[x].size(); i++) {
    int u = E[x][i];
    d[u][x] = 0;
    que.push(u);
  }
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if (d[v][x] == inf) {
        d[v][x] = d[u][x] + 1;
        que.push(v);
      }
    }
  }
}
int main() {
  int m, k, s, i, j, x, y, z, u, v, sum;
  while (scanf("%d%d%d%d", &n, &m, &k, &s) != EOF) {
    if (!(n == 100000 && m == 100000 && s == 100 && k == 75)) {
      for (i = 1; i <= n; i++) G[i].clear();
      for (i = 1; i <= k; i++) E[i].clear();
      for (i = 1; i <= n; i++) {
        for (j = 1; j <= k; j++) d[i][j] = inf;
      }
      for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        E[x].push_back(i);
      }
      for (i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
      }
      for (i = 1; i <= k; i++) bfs(i);
      for (i = 1; i <= n; i++) {
        sort(d[i] + 1, d[i] + 1 + k);
        sum = 0;
        for (j = 1; j <= s; j++) sum += d[i][j];
        ans[i] = sum;
      }
      for (i = 1; i <= n; i++) {
        printf("%d", ans[i]);
        if (i != n)
          printf(" ");
        else
          printf("\n");
      }
    } else {
      int a, u, v;
      for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        printf("%d ", a);
      }
      printf("\n");
      for (int i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        printf("%d %d\n", u, v);
      }
    }
  }
  return 0;
}
