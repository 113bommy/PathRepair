#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
const ll P = 1e9 + 7;
int primes[N], mu[N], tot;
bool isnp[N];
ll dp[N];
void init() {
  mu[1] = 1;
  isnp[0] = isnp[1] = 1;
  for (int i = 2; i < N; ++i) {
    if (!isnp[i]) {
      primes[tot++] = i;
      mu[i] = -1;
    }
    for (int j = 0; j < tot; ++j) {
      if (i * primes[j] >= N) break;
      isnp[i * primes[j]] = 1;
      if (i % primes[j] == 0) break;
      mu[i * primes[j]] = -mu[i];
    }
  }
}
ll quick_pow(ll a, ll b, ll mod) {
  ll ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}
ll inv(ll a, ll p = P) { return quick_pow(a % p, p - 2, p); }
ll count(ll x, ll y, ll m) {
  ll ret = 0;
  ll n = x / y;
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i) continue;
    ret = (ret + mu[i] * (m / (y * i))) % P;
    if (i * i == n) continue;
    ret = (ret + mu[n / i] * (m / (y * (n / i)))) % P;
  }
  return ret;
}
ll solve(ll x, ll m) {
  if (x == 1) return 0;
  if (dp[x]) return dp[x];
  ll sum = 0;
  for (ll i = 1; i * i <= x; ++i) {
    if (x % i) continue;
    sum = (sum + solve(i, m) * count(x, i, m)) % P;
    if (i * i == x || i == 1) continue;
    sum = (sum + solve(x / i, m) * count(x, x / i, m)) % P;
  }
  ll ret = inv(1 - count(x, x, m) * inv(m)) % P * (1 + sum * inv(m) % P) % P;
  return dp[x] = (ret + P) % P;
}
int main() {
  int m;
  init();
  cin >> m;
  ll ans = 0;
  for (int i = 1; i <= m; ++i) {
    ans = (ans + solve(i, m)) % P;
  }
  ans = (1 + ans * inv(m)) % P;
  cout << ans << "\n";
}
