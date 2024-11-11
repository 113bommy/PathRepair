#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
int n, c[maxn][5], d[maxn];
int col[maxn];
vector<int> g[maxn], ans[40];
long long minx = 1e16, id = -1, cnt;
void dfs(int u, int fa, int ye, int d) {
  if (d == n + 1) {
    long long sum = 0;
    ++cnt;
    for (int i = 1; i <= n; i++) {
      sum += c[i][col[i]];
      ans[cnt].push_back(col[i]);
    }
    if (sum < minx) {
      minx = sum;
      id = cnt;
    }
    return;
  }
  if (d == 1) {
    for (int i = 1; i < 4; i++) {
      col[u] = i;
      dfs(g[u][0], u, 0, d + 1);
    }
  } else if (d == 2) {
    for (int i = 1; i < 4; i++) {
      if (col[fa] == i) continue;
      int v1 = g[u][0], v2 = g[u][1];
      col[u] = i;
      if (v1 == fa)
        dfs(v2, u, fa, d + 1);
      else
        dfs(v1, u, fa, d + 1);
    }
  } else {
    for (int i = 1; i < 4; i++) {
      if (col[fa] == i || col[ye] == i) continue;
      if (d == n) {
        col[u] = i;
        dfs(u, u, fa, d + 1);
      } else {
        int v1 = g[u][0], v2 = g[u][1];
        col[u] = i;
        if (v1 == fa)
          dfs(v2, u, fa, d + 1);
        else
          dfs(v1, u, fa, d + 1);
      }
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &c[j][i]);
    }
  }
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
    ++d[u], ++d[v];
  }
  int d1 = 0, d2 = 0, u;
  for (int i = 1; i <= n; i++) {
    if (d[i] == 1) {
      d1++;
      u = i;
    }
    if (d[i] == 2) d2++;
  }
  if (d1 == 2 && d2 == n - 2) {
    dfs(u, 0, 0, 1);
    printf("%lld\n", minx);
    for (int i = 0; i < int(ans[id].size()); i++) {
      printf("%d%c", ans[id][i], i == ans[id].size() - 1 ? '\n' : ' ');
    }
  } else {
    puts("-1");
  }
}
