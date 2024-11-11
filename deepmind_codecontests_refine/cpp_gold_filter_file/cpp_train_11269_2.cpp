#include <bits/stdc++.h>
using namespace std;
static const int INF = 500000000;
template <class T>
void debug(T a, T b) {
  for (; a != b; ++a) cerr << *a << ' ';
  cerr << endl;
}
long long int k, w;
long long int mod = 1000000007;
long long int inv[1000005];
long long int factorial[1000005];
long long int invfact[1000005];
long long int mpow(long long int a, long long int k) {
  long long int res = 1;
  while (k) {
    if (k & 1) res = res * a % mod;
    a = a * a % mod;
    k >>= 1;
  }
  return res;
}
int main() {
  inv[1] = 1;
  for (int i = 2; i < 1000005; ++i)
    inv[i] = (-inv[mod % i] * (mod / i) % mod + mod) % mod;
  factorial[0] = 1;
  invfact[0] = 1;
  for (int i = 0; i < 1000005 - 1; ++i) {
    factorial[i + 1] = factorial[i] * (i + 1) % mod;
    invfact[i + 1] = invfact[i] * inv[i + 1] % mod;
  }
  cin >> k >> w;
  long long int ans = 0;
  for (int t = 1; t <= k; ++t) {
    long long int a = 0, b = 0;
    if (t < w)
      a = factorial[k] * factorial[k] % mod * t % mod * mpow(k, w - t - 1) %
          mod * invfact[k - t] % mod * invfact[k - t] % mod;
    else
      a = factorial[k] * factorial[k - t + w - 1] % mod * w % mod *
          invfact[k - t] % mod * invfact[k - t] % mod;
    if (k - t - 1 >= 0) {
      if (t < w - 1)
        b = factorial[k] * factorial[k] % mod * t % mod * mpow(k, w - t - 2) %
            mod * invfact[k - t] % mod * invfact[k - t - 1] % mod;
      else
        b = factorial[k] * factorial[k - t + w - 2] % mod * (w - 1) % mod *
            invfact[k - t] % mod * invfact[k - t - 1] % mod;
    }
    ans += a + b;
  }
  ans %= mod;
  cout << ans << endl;
  return 0;
}
