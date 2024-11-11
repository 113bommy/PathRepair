#include <bits/stdc++.h>
using namespace std;
const int M = 2010;
vector<int> A[M], G[M], S[M];
bool visited[M], ok[M][M];
int disc[M], low[M], parent[M], Size[M], n;
int subtr[M], dp[M];
void find_bridges(int u) {
  static int time = 0;
  visited[u] = true;
  disc[u] = low[u] = ++time;
  int i, v;
  for (i = 0; i < A[u].size(); i++) {
    v = A[u][i];
    if (!visited[v]) {
      parent[v] = u;
      find_bridges(v);
      low[u] = min(low[u], low[v]);
      if (low[v] > disc[u]) {
        ok[u][v] = ok[v][u] = false;
      }
    } else if (v != parent[u])
      low[u] = min(low[u], disc[v]);
  }
}
void dfs(int u, int p) {
  visited[u] = true;
  parent[u] = p;
  Size[p]++;
  for (int i = 0; i < A[u].size(); i++) {
    int v = A[u][i];
    if (visited[v] || !ok[u][v]) continue;
    dfs(v, p);
  }
}
int dfs2(int u, int up) {
  int sum = 0;
  visited[u] = true;
  subtr[u] = Size[u];
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (visited[v]) continue;
    sum += dfs2(v, up + Size[u]);
    subtr[u] += subtr[v];
  }
  return sum + Size[u] * up;
}
int main() {
  int m, i, j, k;
  memset((ok), (false), sizeof(ok));
  scanf("%d%d", &n, &m);
  while (m--) {
    scanf("%d%d", &i, &j);
    A[i].push_back(j);
    A[j].push_back(i);
    ok[i][j] = ok[j][i] = true;
  }
  memset((visited), (false), sizeof(visited));
  memset((parent), (-1), sizeof(parent));
  for (i = 1; i <= n; i++)
    if (!visited[i]) find_bridges(i);
  memset((visited), (false), sizeof(visited));
  memset((Size), (0), sizeof(Size));
  for (i = 1; i <= n; i++)
    if (!visited[i]) dfs(i, i);
  for (i = 1; i <= n; i++)
    for (j = 0; j < A[i].size(); j++)
      if (!ok[i][A[i][j]]) G[parent[i]].push_back(parent[A[i][j]]);
  int sum, maxx = 0;
  for (i = 1; i <= n; i++) {
    if (parent[i] == i) {
      memset((visited), (false), sizeof(visited));
      sum = dfs2(i, 0);
      memset((dp), (0), sizeof(dp));
      dp[0] = 1;
      for (j = 0; j < A[i].size(); j++) {
        k = subtr[A[i][j]];
        for (int l = n; l >= 0; l--)
          if (dp[l] == 1) dp[l + k] = 1;
      }
      int tempmax = 0;
      for (int l = 0; l < n; l++)
        if (dp[l] == 1) tempmax = max(tempmax, l * (n - l - Size[i]));
      maxx = max(maxx, tempmax + sum);
    }
  }
  for (i = 1; i <= n; i++)
    if (parent[i] == i) maxx += Size[i] * Size[i];
  printf("%d\n", maxx);
  return 0;
}
