#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long a[22], m, ans;
int inv[22], n;
int power(int a, int b) {
  int c = 1;
  while (b) {
    if (b & 1) c = (long long)c * a % mod;
    a = (long long)a * a % mod;
    b >>= 1;
  }
  return c;
}
int C(long long y, int x) {
  if (y < 0 || x < 0 || y < x) return 0;
  y %= mod;
  if (y == 0 || x == 0) return 1;
  int ans = 1;
  for (int i = 0; i < x; ++i) ans = (long long)ans * (y - i) % mod;
  for (int i = 1; i <= x; ++i) ans = (long long)ans * inv[i] % mod;
  return ans;
}
int main() {
  for (int i = 1; i <= 20; ++i) inv[i] = power(i, mod - 2);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int x = 0; x < 1 << n; ++x) {
    if (x == 0) {
      ans = (ans + C(n + m - 1, n)) % mod;
    } else {
      long long t = n + m;
      int p = 0;
      for (int i = 0; i < n; ++i) {
        if (x >> i & 1) {
          ++p;
          t -= a[i + 1];
        }
      }
      t -= p + 1;
      if (p & 1)
        ans = (ans - C(t, n - 1)) % mod;
      else
        ans = (ans + C(t, n - 1)) % mod;
    }
  }
  cout << (ans % mod + mod) % mod << endl;
  return 0;
}
