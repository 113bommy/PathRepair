#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > adj(100005);
vector<int> stk;
int cost[100005], dfs_num[100005], dfs_low[100005];
bool in_stk[100005];
long long sum = 0, ans = 1, num = 1;
const int MOD = 1000000007;
void SCC(int u) {
  dfs_num[u] = dfs_low[u] = num++;
  in_stk[u] = 1;
  stk.push_back(u);
  for (int x : adj[u]) {
    if (dfs_num[x] == -1) SCC(x);
    if (in_stk[x]) dfs_low[u] = min(dfs_low[u], dfs_low[x]);
  }
  if (dfs_num[u] == dfs_low[u]) {
    int mn = 1e9 + 1, cnt = 0;
    for (int i = (int)stk.size() - 1; i >= 0; i--) {
      mn = min(mn, cost[stk[i]]);
      if (stk[i] == u) break;
    }
    while (1) {
      int v = stk.back();
      stk.pop_back();
      in_stk[v] = 0;
      if (cost[v] == mn) cnt++;
      if (v == u) break;
    }
    sum += mn;
    ans = (ans % MOD * cnt % MOD) % MOD;
  }
}
int main() {
  int n, m, x, y;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> cost[i];
  cin >> m;
  while (m--) {
    cin >> x >> y;
    adj[x].push_back(y);
  }
  memset(dfs_num, -1, sizeof dfs_num);
  for (int i = 1; i < n; i++)
    if (dfs_num[i] == -1) SCC(i);
  cout << sum << " " << ans << "\n";
  return 0;
}
