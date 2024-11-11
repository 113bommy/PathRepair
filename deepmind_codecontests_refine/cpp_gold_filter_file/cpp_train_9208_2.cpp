#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
vector<int> G[maxn];
long long dp[maxn][2];
void dfs(int u) {
  dp[u][1] = 1;
  dp[u][0] = 0;
  if (G[u].empty()) return;
  for (int i = 0; i < (int)G[u].size(); ++i) {
    int v = G[u][i];
    dfs(v);
    long long add1 = (dp[u][1] * dp[v][0] + dp[u][0] * dp[v][1]) % mod;
    long long add0 = (dp[u][0] * dp[v][0] + dp[u][1] * dp[v][1]) % mod;
    dp[u][1] = (dp[u][1] + add1) % mod;
    dp[u][0] = (dp[u][0] + add0) % mod;
  }
  dp[u][0] = dp[u][0] * 2 % mod;
  dp[u][1] = dp[u][1] * 2 % mod;
  long long odd[2], even = 1;
  odd[0] = 1;
  odd[1] = 0;
  for (int i = 0; i < (int)G[u].size(); ++i) {
    int v = G[u][i];
    even = (even + even * dp[v][0]) % mod;
    long long add0 = odd[1] * dp[v][1] % mod;
    long long add1 = odd[0] * dp[v][1] % mod;
    odd[0] = (odd[0] + add0) % mod;
    odd[1] = (odd[1] + add1) % mod;
  }
  dp[u][1] -= even;
  if (dp[u][1] < 0) dp[u][1] += mod;
  dp[u][0] -= odd[1];
  if (dp[u][0] < 0) dp[u][0] += mod;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) {
    int p;
    scanf("%d", &p);
    G[p].push_back(i);
  }
  dfs(1);
  printf("%I64d\n", (dp[1][1] + dp[1][0]) % mod);
  return 0;
}
