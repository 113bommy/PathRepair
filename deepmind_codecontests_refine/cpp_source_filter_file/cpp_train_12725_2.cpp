#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int mod = 998244353;
long long n, m, L, R;
long long Q_pow(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = 1LL * res * x % mod;
    x = 1LL * x * x % mod;
    y >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> L >> R;
  long long sum = n * m;
  if (sum % 2) {
    cout << Q_pow((R - L + 1) % mod, sum) << '\n';
  } else {
    long long A = Q_pow((R - L + 1) % mod, sum);
    long long B = 0;
    if ((R - L + 1) % 2) {
      if (L % 2)
        B = 1;
      else
        B = -1;
    }
    cout << 1LL * (A + Q_pow((B + mod) % mod, n)) % mod * Q_pow(2, mod - 2) %
                mod
         << '\n';
  }
  return 0;
}
