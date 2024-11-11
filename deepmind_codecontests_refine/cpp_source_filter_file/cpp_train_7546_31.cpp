#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long f[100001], inv[100001];
long long fastPower(long long a, long long b) {
  if (b == 0) return 1;
  long long res = fastPower(a, b / 2);
  if (b % 2 == 1) return ((res * res) % mod * a) % mod;
  return (res * res) % mod;
}
long long nCk(long long n, long long k) {
  return ((f[n] * inv[k]) % mod * inv[n - k]) % mod;
}
int main() {
  f[0] = 1;
  inv[0] = fastPower(1, mod - 2);
  for (int i = 1; i <= 100000; ++i) {
    f[i] = (i * f[i - 1]) % mod;
    inv[i] = fastPower(f[i], mod - 2);
  }
  int n;
  cin >> n;
  long long ans = nCk(2 * n, n);
  ans = ans - n;
  cout << ans << endl;
  return 0;
}
