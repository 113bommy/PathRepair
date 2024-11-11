#include <bits/stdc++.h>
const long long inf = 0x3f3f3f3f3f3f3f3LL;
using namespace std;
template <class T>
void smin(T& a, T val) {
  if (a > val) a = val;
}
template <class T>
void smax(T& a, T val) {
  if (a < val) a = val;
}
const long long N = 2 * (long long)1e5 + 10;
long long n, a[N];
long long mod;
long long power(long long a, long long b, long long m = mod) {
  if (b < 0) b += m - 1;
  long long r = 1;
  while (b) {
    if (b & 1) r = (r * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return r;
}
long long fact[N + 10], ifact[N + 10];
void pre(long long N) {
  fact[0] = 1;
  for (long long i = 1; i <= N; ++i) {
    fact[i] = (i * fact[i - 1]) % mod;
  }
  ifact[N] = power(fact[N], -1);
  for (long long i = N - 1; i >= 0; --i) {
    ifact[i] = ((i + 1) * ifact[i + 1]) % mod;
  }
}
long long nCr(long long n, long long r) {
  if (n < r) return 0;
  return ((fact[n] * ifact[r]) % mod * ifact[n - r]) % mod;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> mod;
  pre(N);
  long long ans = 0;
  for (long long k = 1; k <= n; ++k) {
    long long sum = fact[k] * fact[n - k + 1] % mod;
    sum *= (n - k + 1);
    sum %= mod;
    ans += sum;
    ans %= mod;
  }
  cout << ans;
  return 0;
}
