#include <bits/stdc++.h>
const int inf = int(1e9) + 7;
const double eps = 1e-9;
using namespace std;
const int maxn = int(1e5 + 10);
const long long MOD = 998244353;
inline long long fuc(long long v) {
  long long res = 1;
  for (long long i = 1; i <= v; ++i) (res *= i) %= MOD;
  return res;
}
long long bin_pow(long long a, int n) {
  if (n == 0) return 1LL;
  if (n % 2 == 0) {
    long long b = bin_pow(a, n / 2);
    return (b * b) % MOD;
  } else
    return (a * bin_pow(a, n - 1)) % MOD;
}
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (k == 0)
    cout << m;
  else
    cout << (((fuc(n - 1LL) *
               bin_pow((fuc(k) * fuc(n - k - 1LL) % MOD), MOD - 2LL) % MOD) *
              m % MOD) *
             bin_pow((m - 1LL), k)) %
                MOD;
  return 0;
}
