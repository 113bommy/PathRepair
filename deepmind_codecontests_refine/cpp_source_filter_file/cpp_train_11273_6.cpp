#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
const int mod = 998244353;
long long a[N], fact[N];
long long binpow(long long u, long long p) {
  if (p == 0) return 1;
  if (p == 1) return u;
  long long t = binpow(u, p / 2);
  if (p & 1)
    return t * t % mod * u % mod;
  else
    return t * t % mod;
}
long long nCk(long long n, long long k) {
  return fact[n] * binpow(fact[k], mod - 2) % mod *
         binpow(fact[n - k], mod - 2) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  if (fopen("A.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  long long n;
  cin >> n;
  n = n * 2;
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  long long ans = 0;
  for (int i = 1; i <= (n / 2); i++) {
    ans = ans - a[i] + a[n - i + 1];
  }
  cout << ans * nCk(n, n / 2) % mod;
}
