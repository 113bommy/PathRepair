#include <bits/stdc++.h>
using namespace std;
void init() {}
const int N = 2e5 + 7;
vector<int> edge[N];
int n, ans, in[N], dp[N];
void dfs(int u, int fa) {
  dp[u] = dp[fa] + 1;
  for (auto v : edge[u]) {
    if (v == fa) continue;
    dfs(v, u);
  }
  if (dp[u] > 2) {
    dp[fa] = 1;
    for (auto v : edge[fa]) {
      dp[v] = min(dp[v], dp[u] + 1);
    }
    ans++;
  }
}
int main() {
  init();
  cin >> n;
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dp[1] = -1;
  dfs(1, 1);
  cout << ans << endl;
  return 0;
}
