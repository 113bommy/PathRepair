#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const long long INF = 1e9 + 10;
const int MOD = 1e9 + 7;
long long dp[N][2], color[N];
vector<vector<int>> tree;
long long arr = 1;
void dfs(int go, int cur) {
  dp[go][0] = 1;
  for (auto v : tree[go]) {
    if (v == cur) continue;
    dfs(v, go);
    dp[go][1] = (dp[go][1] * dp[v][0]) % MOD;
    dp[go][1] = (dp[go][1] + (dp[v][1] * dp[go][0]) % MOD) % MOD;
    dp[go][0] = (dp[go][0] * dp[v][0]) % MOD;
  }
  if (color[go])
    dp[go][1] = dp[go][0];
  else
    dp[go][0] += dp[go][1];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  tree.assign(n, vector<int>(0));
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    tree[i].push_back(p);
    tree[p].push_back(i);
  }
  for (int i = 0; i < n; i++) cin >> color[i];
  dfs(0, 0);
  cout << dp[0][1];
}
