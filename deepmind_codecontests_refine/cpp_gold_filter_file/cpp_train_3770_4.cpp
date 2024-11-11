#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 998244353;
const ll root = 3;
ll binpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
ll modInv(ll a) { return binpow(a, MOD - 2); }
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll NINFLL = 0xc0c0c0c0c0c0c0c0;
const int mxN = 200001;
int arr[mxN];
vector<int> adj[mxN];
ll dp[mxN][4];
int n;
void dfs(int u, int p = -1) {
  if (adj[u].size() == 1 && p != -1) {
    dp[u][0] = 1;
    dp[u][1] = 0;
    dp[u][2] = 0;
    dp[u][3] = 1;
    return;
  }
  int parid = -1;
  for (int i = (0); i < (adj[u].size()); ++i) {
    if (adj[u][i] == p)
      parid = i;
    else
      dfs(adj[u][i], u);
  }
  if (parid == -1) return;
  dp[u][0] = 1;
  bool pass = 0;
  for (int i = (0); i < (adj[u].size()); ++i) {
    int v = adj[u][i];
    if (i == parid)
      continue;
    else if (i < parid) {
      dp[u][0] = (dp[u][0] * (dp[v][0] + dp[v][1])) % MOD;
    } else {
      dp[u][0] = (dp[u][0] * (dp[v][1] + dp[v][2] + dp[v][3])) % MOD;
    }
  }
  ll curr = 1;
  for (int i = (0); i < (adj[u].size()); ++i) {
    if (i == parid) continue;
    int v = adj[u][i];
    curr = (curr * (dp[v][1] + dp[v][2] + dp[v][3])) % MOD;
  }
  for (int i = (0); i < (parid); ++i) {
    int v = adj[u][i];
    curr = (curr * modInv(dp[v][1] + dp[v][2] + dp[v][3])) % MOD;
    curr = (curr * (dp[v][2] + dp[v][3])) % MOD;
    dp[u][1] = (dp[u][1] + curr) % MOD;
    curr = (curr * modInv(dp[v][2] + dp[v][3])) % MOD;
    curr = (curr * (dp[v][0] + dp[v][1])) % MOD;
  }
  for (int i = (parid + 1); i < (adj[u].size()); ++i) {
    int v = adj[u][i];
    curr = (curr * modInv(dp[v][1] + dp[v][2] + dp[v][3])) % MOD;
    curr = (curr * (dp[v][2] + dp[v][3])) % MOD;
    dp[u][2] = (dp[u][2] + curr) % MOD;
    curr = (curr * modInv(dp[v][2] + dp[v][3])) % MOD;
    curr = (curr * (dp[v][0] + dp[v][1])) % MOD;
  }
  dp[u][3] = 1;
  for (int i = (0); i < (adj[u].size()); ++i) {
    if (i == parid) continue;
    int v = adj[u][i];
    dp[u][3] = (dp[u][3] * (dp[v][0] + dp[v][1])) % MOD;
  }
}
int main() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  int a, b;
  for (int i = (0); i < (n - 1); ++i) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  adj[0].push_back(1);
  adj[1].push_back(0);
  dfs(0);
  ll res = (dp[1][1] + dp[1][2] + dp[1][3]) % MOD;
  cout << res << "\n";
  return 0;
}
