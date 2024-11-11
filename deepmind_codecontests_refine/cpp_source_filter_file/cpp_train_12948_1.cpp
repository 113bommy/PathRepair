#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int n_ = 1e5 + 1000;
long long gcd(long long a, long long b) { return (a ? gcd(b % a, a) : b); }
long long power(long long a, long long n) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
    }
    n >>= 1;
    a *= a;
  }
  return p;
}
long long power(long long a, long long n, long long mod) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
      p %= mod;
    }
    n >>= 1;
    a *= a;
    a %= mod;
  }
  return p % mod;
}
long long n, a[n_], dp[n_][2];
vector<int> e[n_];
int dfs(int u, int p = -1) {
  long long &mn = dp[u][1], &mx = dp[u][0];
  for (auto v : e[u]) {
    if (v == p) continue;
    dfs(v, u);
    mn = max(mn, dp[v][1]);
    mx = max(mx, dp[v][0]);
  }
  long long tmp = mx - mn + a[u];
  if (tmp < 0) {
    dp[u][0] -= tmp;
  } else {
    dp[u][1] += tmp;
  }
  return dp[u][0] + dp[u][1];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    e[u].push_back(v), e[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << dfs(0) << "\n";
  return 0;
}
