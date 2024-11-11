#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int N = 200005;
long long fac[N], ifac[N], inv[N];
void pre() {
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = fac[i - 1] * i % mod;
    if (i > 1)
      inv[i] = inv[mod % i] * (mod - (mod / i)) % mod;
    else
      inv[i] = 1;
    ifac[i] = ifac[i - 1] * inv[i] % mod;
  }
}
inline long long modPow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) (ret *= a) %= mod;
    (a *= a) %= mod;
    b >>= 1;
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << setprecision(32);
  pre();
  int n, k;
  cin >> n >> k;
  long long w, sw = 0;
  for (int i = 1; i <= n; i++) {
    cin >> w;
    sw += w;
  }
  if (n == 1) {
    cout << 1 << endl;
    exit(0);
  }
  sw %= mod;
  long long ans = 0;
  for (int j = 0; j < k; j++) {
    long long tmp = modPow(j + 1, n - 1) + (n - 1) * modPow(j + 1, n - 2);
    tmp %= mod;
    tmp *= ifac[j] * ifac[k - 1 - j] % mod;
    tmp %= mod;
    if ((k - 1 - j) % 2 == 0)
      ans += tmp;
    else
      ans += mod - tmp;
  }
  ans %= mod;
  ans *= sw;
  ans %= mod;
  cout << ans << endl;
  return 0;
}
