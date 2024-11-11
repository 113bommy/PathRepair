#include <bits/stdc++.h>
using namespace std;
const long long inf = 9e18;
const long long mod = 998244353;
const long long maxn = 3e5 + 10, maxk = 25, mlg = 25;
long long n;
long long dp[maxn][3], mark[maxn];
vector<long long> nei[maxn];
void dfs(long long u) {
  mark[u] = 1;
  dp[u][0] = 1;
  dp[u][1] = 1;
  for (auto v : nei[u]) {
    if (!mark[v]) {
      dfs(v);
      dp[u][2] = ((dp[u][2] * ((dp[v][2] * 2 + dp[v][0]) % mod)) % mod +
                  (dp[u][1] * (dp[v][1])) % mod) %
                 mod;
      dp[u][1] = (dp[u][1] * ((2 * dp[v][2] + dp[v][0]) % mod)) % mod;
      dp[u][0] = (dp[u][0] * ((dp[v][0] + dp[v][2]) % mod)) % mod;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    long long u, v;
    cin >> u >> v;
    nei[u].push_back(v);
    nei[v].push_back(u);
  }
  dfs(1);
  cout << (dp[1][0] + dp[1][2]) % mod << endl;
}
