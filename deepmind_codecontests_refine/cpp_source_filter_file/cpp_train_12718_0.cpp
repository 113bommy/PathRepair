#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, MAX = 1e5 + 5;
long long powN(long long a, long long p) {
  if (p == 0) return 1;
  long long z = powN(a, p / 2);
  z = (z * z) % MOD;
  if (p % 2) z = (z * a) % MOD;
  return z;
}
vector<bool> is_prime(MAX + 1, true);
void Sieve() {
  is_prime[0] = is_prime[1] = false;
  int i, j;
  for (i = 2; i * i <= MAX; i++) {
    if (is_prime[i]) {
      for (j = i * i; j <= MAX; j += i) is_prime[j] = false;
    }
  }
}
vector<vector<int> > V(2 * MAX);
vector<long long> dp(2 * MAX);
vector<int> vis(2 * MAX);
vector<int> siz(2 * MAX);
long long dfs(int i) {
  vis[i] = true;
  dp[i] += 1ll;
  siz[i] += 1;
  for (auto j : V[i]) {
    if (vis[j]) continue;
    dfs(j);
    dp[i] += dp[j] + siz[j];
    siz[i] += siz[j];
  }
  return dp[i];
}
vector<int> A(2 * MAX);
long long dfsr(int i) {
  vis[i] = true;
  A[i] = dp[i];
  for (auto j : V[i]) {
    if (vis[j]) continue;
    dp[i] -= (dp[j] + siz[j]);
    siz[i] -= siz[j];
    dp[j] += (dp[i] + siz[i]);
    siz[j] += siz[i];
    dfsr(j);
    siz[j] -= siz[i];
    dp[j] -= (dp[i] + siz[i]);
    siz[i] += siz[j];
    dp[i] += (dp[j] + siz[j]);
  }
  return A[i];
}
int main() {
  int n;
  cin >> n;
  V.resize(n + 1);
  dp.resize(n + 1);
  vis.resize(n + 1);
  A.resize(n + 1);
  siz.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    V[u].push_back(v);
    V[v].push_back(u);
  }
  dp[1] = dfs(1);
  for (int i = 1; i <= n; i++) vis[i] = false;
  A[1] = dfsr(1);
  sort(A.begin(), A.end());
  cout << A[n] << endl;
}
