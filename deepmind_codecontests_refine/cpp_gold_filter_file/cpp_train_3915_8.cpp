#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
long long int power(long long int a, long long int b) {
  long long int res = 1;
  a = a % MOD;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % MOD;
      b--;
    }
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
long long int fermat_inv(long long int y) { return power(y, MOD - 2); }
long long int gcd(long long int a, long long int b) {
  return (b == 0) ? a : gcd(b, a % b);
}
long long int min(long long int a, long long int b) { return (a > b) ? b : a; }
long long int max(long long int a, long long int b) { return (a > b) ? a : b; }
bool prime[1000001];
vector<int> primes;
void SieveOfEratosthenes(int n) {
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (int p = 2; p < 1000001; p++)
    if (prime[p]) primes.push_back(p);
}
long long int fact[100005];
long long int finv[100005];
void factorial(int n) {
  fact[0] = 1;
  finv[0] = 1;
  for (int i = 1; i <= n; i++)
    fact[i] = fact[i - 1] * i, fact[i] %= MOD, finv[i] = fermat_inv(fact[i]);
}
long long int ncr(long long int n, long long int r) {
  if (n < r)
    return 0;
  else {
    long long int x = finv[r] * finv[n - r] % MOD;
    return fact[n] * x % MOD;
  }
}
void dfs(int i, vector<int> adj[], int vis[], int l) {
  if (vis[i] != -1) return;
  vis[i] = l++;
  for (int j : adj[i]) dfs(j, adj, vis, l);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int d1[n + 1], d2[n + 1];
    memset(d1, -1, sizeof(d1));
    memset(d2, -1, sizeof(d2));
    dfs(1, adj, d1, 0);
    dfs(x, adj, d2, 0);
    long long int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (d2[i] >= d1[i]) continue;
      ans = max(ans, 2 * d1[i]);
    }
    cout << ans;
  }
}
