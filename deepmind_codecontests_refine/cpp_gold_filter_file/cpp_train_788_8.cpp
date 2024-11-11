#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long maxn = 2e5 + 10;
const long long mod = 1e9 + 7;
long long n, N;
long long fact[maxn], a[maxn];
pair<long long, long long> gcd(long long a, long long b) {
  if (b == 0) return make_pair(a, 0);
  pair<long long, long long> p = gcd(b, a % b);
  return make_pair(p.second, p.first - ((a / b) * p.second));
}
long long varoon(long long a) { return (gcd(a, mod).first + mod) % mod; }
long long C(long long n, long long k) {
  return (fact[n] * ((varoon(fact[k]) * varoon(fact[n - k])) % mod)) % mod;
}
long long f(long long q) {
  long long ans = 0;
  for (long long i = 1; i <= N; i++) {
    ans = (ans + C(N - 1, i - 1) * a[2 * i + q]) % mod;
  }
  return ans;
}
int main() {
  fact[0] = 1;
  for (long long i = 1; i <= maxn - 1; i++) fact[i] = (fact[i - 1] * i) % mod;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] %= mod;
  }
  if (n % 2) {
    long long manfi = 1;
    for (long long i = 1; i <= n - 1; i++) {
      a[i] = (a[i] + (manfi * a[i + 1])) % mod;
      manfi *= -1;
    }
    n--;
  }
  if (n < 10) {
    long long manfi = 1;
    for (long long i = 0; i < n - 1; i++) {
      for (long long j = 1; j <= n - i - 1; j++) {
        a[j] = (a[j] + (manfi * a[j + 1])) % mod;
        manfi *= -1;
      }
    }
    cout << ((a[1] % mod) + mod) % mod;
    return 0;
  }
  N = n / 2;
  long long manfi = ((n % 4 == 0) ? -1 : 1);
  cout << (((f(-1) + (manfi * f(0))) % mod) + mod) % mod;
}
