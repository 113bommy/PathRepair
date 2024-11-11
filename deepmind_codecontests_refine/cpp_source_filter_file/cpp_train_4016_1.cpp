#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000 + 5], gp[1000 + 5];
int W[1000 + 5], B[1000 + 5], G[1000 + 5], Ba[1000 + 5], Wa[1000 + 5];
bool vis[1000 + 5], done[1000 + 5][1000 + 5];
long long dp[1000 + 5][1000 + 5];
int n, m, w, grupo = 0;
long long f(int pos, int sum) {
  if (pos == grupo) return 0;
  if (done[pos][sum]) return dp[pos][sum];
  done[pos][sum] = 1;
  long long ret = -3000000000;
  ret = max(ret, f(pos + 1, sum));
  if (sum + Wa[pos] <= w) {
    ret = max(ret, Ba[pos] + f(pos + 1, sum + Wa[pos]));
  }
  int sz = gp[pos].size();
  for (int i = 0; i < sz; ++i) {
    if (sum + W[gp[pos][i]] <= w) {
      ret = max(ret, B[gp[pos][i]] + f(pos + 1, W[gp[pos][i]]));
    }
  }
  dp[pos][sum] = ret;
  return ret;
}
void dfs(int u, int g) {
  if (vis[u]) return;
  vis[u] = 1;
  G[u] = g;
  int sz = adj[u].size();
  for (int i = 0; i < sz; ++i) {
    int v = adj[u][i];
    dfs(v, g);
  }
}
int main() {
  int x, y;
  scanf("%d%d%d", &n, &m, &w);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &W[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &B[i]);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &x, &y);
    x--, y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      dfs(i, grupo);
      grupo++;
    }
  }
  for (int i = 0; i < n; ++i) {
    gp[G[i]].push_back(i);
  }
  for (int i = 0; i < grupo; ++i) {
    int sz = gp[i].size();
    for (int j = 0; j < sz; ++j) {
      Wa[i] += W[gp[i][j]];
      Ba[i] += B[gp[i][j]];
    }
  }
  for (int i = 0; i <= 1000; ++i)
    for (int j = 0; j <= 1000; ++j) done[i][j] = 0;
  cout << f(0, 0) << endl;
}
