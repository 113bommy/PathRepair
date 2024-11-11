#include <bits/stdc++.h>
using namespace std;
const int N = 1008;
vector<vector<int>> groups;
vector<int> g[1 + N];
int n, m, w[1 + N], b[1 + N], maxW;
bool viz[1 + N];
vector<int> gnow;
long long dp[1 + N], dpa[1 + N];
long long beautynow, wnow;
void dfs(int node) {
  viz[node] = 1;
  gnow.push_back(node);
  beautynow += b[node];
  wnow += w[node];
  for (auto i : g[node]) {
    if (!viz[i]) {
      dfs(i);
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &maxW);
  for (int i = 1; i <= n; ++i) scanf("%d", &w[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (!viz[i]) {
      beautynow = 0;
      wnow = 0;
      gnow.clear();
      dfs(i);
      for (int j = 0; j <= maxW; ++j) dpa[j] = dp[j];
      for (int j = wnow; j <= maxW; ++j)
        dp[j] = max(dp[j], dpa[j - wnow] + beautynow);
      for (auto x : gnow)
        for (int j = w[x]; j <= maxW; ++j)
          dp[j] = max(dp[j], dpa[j - w[x]] + b[x]);
    }
  }
  long long res = 0;
  for (int j = 0; j <= maxW; ++j) res = max(res, dp[j]);
  printf("%I64d", res);
}
