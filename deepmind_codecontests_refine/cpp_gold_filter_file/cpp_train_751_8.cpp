#include <bits/stdc++.h>
using namespace std;
const int N = 300300;
const int mod = 998244353;
int pw(int x, int n) {
  int res = 1;
  for (; n > 0; n >>= 1) {
    if (n & 1) {
      res = 1ll * res * x % mod;
    }
    x = 1ll * x * x % mod;
  }
  return res;
}
long long n, a[N];
long long f[N], A[N], B[N], inv[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  long long s = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s += a[i];
  }
  for (int i = 1; i < N; i++) {
    inv[i] = pw(i, mod - 2);
  }
  A[0] = 1;
  for (int i = 1; i <= s; i++) {
    B[i] = B[i - 1] * i % mod * inv[s] % mod + i * inv[s] % mod;
    A[i] = (s - i) * inv[s] % mod * inv[n - 1] % mod;
    long long div =
        1 - (s - i) * inv[s] % mod * (n - 2) % mod * inv[n - 1] % mod;
    div -= A[i - 1] * i % mod * inv[s] % mod;
    div = (div % mod + mod) % mod;
    div = pw(div, mod - 2);
    A[i] = A[i] * div % mod;
    B[i] = B[i] * div % mod;
  }
  for (int i = s - 1; i >= 0; i--) {
    f[i] = (f[i + 1] * A[i] + B[i]) % mod;
  }
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    res += f[a[i]];
  }
  res %= mod;
  res -= (n - 1) * f[0] % mod;
  if (res < 0) {
    res += mod;
  }
  cout << res << "\n";
}
