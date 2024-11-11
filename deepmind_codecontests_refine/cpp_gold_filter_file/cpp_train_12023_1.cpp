#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
vector<int> edges[N];
int dp[N], leafs[N];
void dfs(int u, int par, bool sign) {
  bool isLeaf = true;
  leafs[u] = 0;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v != par) {
      dfs(v, u, !sign);
      isLeaf = false;
      leafs[u] += leafs[v];
    }
  }
  dp[u] = 0;
  if (isLeaf) {
    dp[u] = 1, leafs[u] = 1;
    return;
  }
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v != par) {
      if (sign) {
        dp[u] = max(dp[u], dp[v] + leafs[u] - leafs[v]);
      } else {
        dp[u] += (dp[v] - 1);
      }
    }
  }
  if (!sign) dp[u] = dp[u] + 1;
}
void dfs1(int u, int par, bool sign) {
  bool isLeaf = true;
  leafs[u] = 0;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v != par) {
      dfs1(v, u, !sign);
      isLeaf = false;
      leafs[u] += leafs[v];
    }
  }
  dp[u] = N;
  if (sign) dp[u] = 0;
  if (isLeaf) dp[u] = 1, leafs[u] = 1;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v != par) {
      if (sign) {
        dp[u] += dp[v];
      } else {
        dp[u] = min(dp[u], dp[v]);
      }
    }
  }
}
int main() {
  int n, x, y;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    scanf("%d %d", &x, &y);
    edges[x].push_back(y);
    edges[y].push_back(x);
  }
  dfs(1, 0, 1);
  cout << dp[1] << " ";
  memset(dp, 0, sizeof dp);
  dfs1(1, 0, 1);
  cout << dp[1];
  return 0;
}
