#include <bits/stdc++.h>
using namespace std;
int n, k;
const long long mod = 998244353;
long long a[200010], inv[200010];
long long binpow(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
void compute() {
  long long ans = 1;
  a[0] = 1;
  inv[0] = 1;
  for (int i = 1; i <= n; i++) {
    ans *= i;
    ans %= mod;
    a[i] = ans;
    inv[i] = binpow(a[i], mod - 2);
  }
}
long long c(long long x, long long y) {
  long long ans = a[y] * inv[y - x] % mod;
  ans *= inv[x];
  ans %= mod;
  return ans;
}
int main() {
  cin >> n >> k;
  if (k >= n) {
    cout << 0;
    return 0;
  }
  compute();
  long long ans = 0;
  int dau = 1;
  int j = n - k;
  for (int i = j; i >= 1; i--) {
    long long add = c(i, j) * binpow(i, n);
    add %= mod;
    ans += (dau * add);
    ans += mod;
    ans %= mod;
    dau = 0 - dau;
  }
  ans *= c(j, n);
  ans %= mod;
  if (k) ans <<= 1;
  ans %= mod;
  cout << ans << endl;
}
