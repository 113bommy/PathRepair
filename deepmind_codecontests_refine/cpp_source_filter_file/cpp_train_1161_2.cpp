#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const long long N = 2e5 + 10;
long long gcd(long long a, long long b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}
long long power(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % MOD;
    b /= 2;
    a = (a * a) % MOD;
  }
  return ans;
}
long long deg[N];
vector<long long> vp[N];
long long fact[N];
int32_t main() {
  long long n;
  cin >> n;
  fact[1] = 1;
  for (long long i = 2; i <= n; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= MOD;
  }
  for (long long i = 0; i < n - 1; i++) {
    long long u, v;
    cin >> u >> v;
    vp[u].push_back(v);
    vp[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  long long ans = 1;
  for (long long i = 1; i <= n; i++) {
    ans = ans * fact[deg[i]];
    ans = ans % MOD;
  }
  cout << ans * n << endl;
}
