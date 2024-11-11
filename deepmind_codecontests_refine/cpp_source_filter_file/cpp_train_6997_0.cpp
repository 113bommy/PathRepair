#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e3 + 5;
vector<int> edge[maxn];
int n, u, v;
int sub[maxn][maxn], par[maxn][maxn];
long long dp[maxn][maxn], res;
int root;
int dfs(int x, int p) {
  sub[root][x] = 1;
  for (int i = 0; i < edge[x].size(); i++) {
    if (edge[x][i] != p) {
      par[root][edge[x][i]] = x;
      sub[root][x] += dfs(edge[x][i], x);
    }
  }
  return sub[root][x];
}
long long solve(int u, int v) {
  if (u == v) return 0;
  if (dp[u][v]) return dp[u][v];
  return dp[u][v] = sub[u][v] * sub[v][u] +
                    max(solve(par[v][u], v), solve(par[u][v], u));
}
int main() {
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    cin >> u >> v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    root = i;
    dfs(root, -1);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      res = max(res, solve(i, j));
    }
  printf("%d\n", res);
}
