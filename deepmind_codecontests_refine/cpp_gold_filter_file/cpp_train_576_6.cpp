#include <bits/stdc++.h>
using namespace std;
const int N = 4 * 1e5 + 5;
vector<int> g[N];
int n, dp[N], res[N];
int dfs(int i, int p = -1) {
  dp[i] = 1;
  for (auto j : g[i]) {
    if (j != p) {
      dp[i] += dfs(j, i);
    }
  }
  return dp[i];
}
int dfs2(int i, int p = -1) {
  for (auto j : g[i]) {
    if (j != p && dp[j] * 2 > n) {
      return dfs2(j, i);
    }
  }
  return i;
}
void dfs3(int i, int p, int c1, int c2) {
  if (c1 * 2 >= n) res[i] = 1;
  if ((dp[i] + c2) * 2 >= n) res[i] = 1;
  for (auto j : g[i]) {
    if (j != p) {
      dfs3(j, i, c1, c2);
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0);
  int a = dfs2(0);
  dfs(a);
  res[a] = 1;
  int mx = -1, mx2 = -1, v;
  for (auto j : g[a]) {
    if (dp[j] > mx) {
      mx2 = mx;
      mx = dp[j];
      v = j;
    } else if (dp[j] > mx2) {
      mx2 = dp[j];
    }
  }
  for (auto j : g[a]) {
    if (j == v)
      dfs3(j, a, dp[j], mx2);
    else
      dfs3(j, a, dp[j], mx);
  }
  for (int i = 0; i < n; ++i) cout << res[i] << " ";
  return 0;
}
