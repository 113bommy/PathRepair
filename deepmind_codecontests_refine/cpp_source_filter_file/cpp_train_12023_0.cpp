#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
vector<int> e[N];
int dp[N], leafs[N];
void dfs(int u, bool sign) {
  if (e[u].size() == 0) {
    dp[u] = leafs[u] = 1;
    return;
  }
  leafs[u] = 0;
  for (int i = 0; i < e[u].size(); ++i) {
    int v = e[u][i];
    dfs(v, !sign);
    leafs[u] += leafs[v];
  }
  dp[u] = 0;
  for (int i = 0; i < e[u].size(); ++i) {
    int v = e[u][i];
    if (sign) {
      dp[u] = max(dp[u], dp[v] + leafs[u] - leafs[v]);
    } else {
      dp[u] += (dp[v] - 1);
    }
  }
  if (!sign) dp[u] = dp[u] + 1;
}
void dfs1(int u, bool sign) {
  if (e[u].size() == 0) {
    dp[u] = leafs[u] = 1;
    return;
  }
  leafs[u] = 0;
  for (int i = 0; i < e[u].size(); ++i) {
    int v = e[u][i];
    dfs(v, !sign);
    leafs[u] += leafs[v];
  }
  dp[u] = N * (int)sign;
  for (int i = 0; i < e[u].size(); ++i) {
    int v = e[u][i];
    if (sign) {
      dp[u] = min(dp[u], dp[v]);
    } else {
      dp[u] += dp[v];
    }
  }
}
int main() {
  int n, x, y;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    scanf("%d %d", &x, &y);
    e[x].push_back(y);
  }
  dfs(1, 1);
  cout << dp[1] << " ";
  dfs1(1, 0);
  cout << dp[1];
  return 0;
}
