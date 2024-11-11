#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e5 + 20, mod = 998244353;
long long n, dp1[maxn], dp2[maxn], dp3[maxn], pd1[maxn], pd2[maxn], pd3[maxn];
vector<long long> adj[maxn];
void dfs(long long v, long long p) {
  dp1[v] = 0;
  dp2[v] = 1;
  dp3[v] = 1;
  for (auto u : adj[v]) {
    if (u != p) {
      dfs(u, v);
      pd1[v] += (dp1[v] % mod) * (dp1[u] % mod + dp3[u] % mod);
      pd1[v] %= mod;
      pd2[v] += (dp2[v] % mod) * (dp1[u] % mod + dp3[u] % mod);
      pd2[v] %= mod;
      pd3[v] += (dp3[v] % mod) * (dp1[u] % mod + dp3[u] % mod);
      pd3[v] %= mod;
      pd1[v] +=
          (dp2[v] % mod) * (dp2[u] % mod) + (dp1[v] % mod) * (dp1[u] % mod);
      pd1[v] %= mod;
      pd2[v] += (dp2[v] % mod) * (dp1[u] % mod);
      pd2[v] %= mod;
      dp1[v] = pd1[v];
      dp2[v] = pd2[v];
      dp3[v] = pd3[v];
      pd1[v] = 0;
      pd2[v] = 0;
      pd3[v] = 0;
    }
  }
  return;
}
int32_t main() {
  cin >> n;
  for (long long i = 0; i < n - 1; i++) {
    long long x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, 1);
  cout << (dp1[1] + dp3[1]) % mod;
}
