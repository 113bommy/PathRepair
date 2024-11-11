#include <bits/stdc++.h>
using namespace std;
const int NN = 200200;
const int mod = 998244353;
vector<int> adj[NN];
int dp[NN][2];
inline void add(int &a, long long b) { a = (a + b) % mod; }
void dfs(int u) {
  if (adj[u].empty()) {
    dp[u][0] = dp[u][1] = 1;
    return;
  }
  int tmp[3] = {1, 0};
  int all = 1, com = 1;
  for (int v : adj[u]) {
    dfs(v);
    tmp[1] =
        ((long long)tmp[1] * dp[v][1] + (long long)tmp[0] * dp[v][0]) % mod;
    tmp[0] = (long long)tmp[0] * dp[v][1] % mod;
    all = (long long)all * (dp[v][0] + dp[v][1]) % mod;
    com = (long long)com * dp[v][1] % mod;
  }
  dp[u][1] = (all - tmp[1] + mod) % mod;
  dp[u][0] = (all - com + mod) % mod;
}
int main() {
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int p;
    scanf("%d", &p);
    adj[p].push_back(i);
  }
  dfs(1);
  cout << dp[1][1] << endl;
  return 0;
}
