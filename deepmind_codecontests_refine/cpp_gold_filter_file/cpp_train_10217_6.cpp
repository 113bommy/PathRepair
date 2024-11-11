#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
using namespace std;
void solve();
signed main() {
  srand(time(0));
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.precision(10);
  solve();
  return 0;
}
const long long MOD = 1e9 + 7, MAXN = 1e6 + 10, INF = 1e9 + 10, BASE = 37;
long long fact[MAXN], rfact[MAXN];
long long bin_pow(long long num, long long n) {
  if (n == 0) {
    return 1;
  }
  if (n & 1) {
    return num * bin_pow(num, n - 1) % MOD;
  } else {
    long long tmp = bin_pow(num, n / 2);
    return tmp * tmp % MOD;
  }
}
long long C(long long n, long long k) {
  if (n - k < 0) {
    return 0;
  }
  return (fact[n] * rfact[k] % MOD) * rfact[n - k] % MOD;
}
long long A(long long n, long long k) {
  if (n - k < 0) {
    return 0;
  }
  return fact[n] * rfact[n - k] % MOD;
}
long long f(long long first, long long second) {
  if (first - second - 1 < 0) {
    return 1;
  }
  return second * bin_pow(first, first - second - 1) % MOD;
}
void solve() {
  fact[0] = 1, rfact[0] = 1;
  for (long long i = 1; i < MAXN; ++i) {
    fact[i] = fact[i - 1] * i % MOD;
    rfact[i] = bin_pow(fact[i], MOD - 2);
  }
  long long n, m, a, b;
  cin >> n >> m >> a >> b;
  long long ans = 0;
  for (long long edge = 1; edge < n; ++edge) {
    ans = (ans + (((A(n - 2, edge - 1) * C(m - 1, edge - 1)) % MOD *
                   bin_pow(m, n - edge - 1)) %
                  MOD * f(n, edge + 1) % MOD)) %
          MOD;
  }
  cout << ans << '\n';
}
