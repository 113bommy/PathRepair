#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 998244353;
long long fastPow(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  long long res = 1;
  a %= MOD;
  while (b) {
    if (b & 1) {
      res = (res * a) % MOD;
    }
    b >>= 1;
    a = (a * a) % MOD;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  t = 1;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long num = {1}, den{1};
    for (int i = 1; i <= n - 1; ++i) {
      num = num * (m - i + 1) % MOD;
      den = den * fastPow(i, MOD - 2) % MOD;
    }
    cout << (num * den) % MOD * (n - 2) % MOD * fastPow(2, max(0LL, n - 3)) %
                MOD
         << "\n";
  }
  return 0;
}
