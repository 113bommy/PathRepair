#include <bits/stdc++.h>
using namespace std;
long long int Pow(long long int a, long long int b, long long int md,
                  long long int ans = 1) {
  for (; b; b >>= 1, a = a * a % md)
    if (b & 1) ans = ans * a % md;
  return ans % md;
}
const long long int MAXN = 3e5 + 10;
const long long int INF = 8e18;
const long long int MOD = 1e9 + 7;
long long int dp[3][MAXN], n;
vector<long long int> adj[MAXN];
void DFS(long long int v, long long int p = -1) {
  dp[1][v] = dp[2][v] = 1;
  for (long long int u : adj[v]) {
    if (u == p) continue;
    DFS(u, v);
  }
  for (long long int u : adj[v]) {
    if (u == p) continue;
    dp[1][v] = dp[1][v] * ((dp[0][u] + dp[1][u]) % MOD) % MOD;
    dp[2][v] = dp[2][v] * ((dp[0][u] + dp[0][u] + dp[1][u]) % MOD) % MOD;
  }
  for (long long int u : adj[v]) {
    if (u == p) continue;
    long long int soroush =
        dp[2][v] * Pow((dp[0][u] + dp[0][u] + dp[1][u]) % MOD, MOD - 2, MOD) %
        MOD;
    dp[0][v] = (dp[0][v] + soroush * dp[2][u] % MOD) % MOD;
  }
}
int main() {
  scanf("%lld", &n);
  for (long long int i = 1; i <= n - 1; i++) {
    long long int u, v;
    scanf("%lld%lld", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  DFS(1);
  printf("%lld\n", (dp[0][1] + dp[1][1]) % MOD);
  return 0;
}
