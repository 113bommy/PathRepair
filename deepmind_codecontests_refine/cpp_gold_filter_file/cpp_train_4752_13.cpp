#include <bits/stdc++.h>
using namespace std;
int inv[1000005];
int ModExp(int a, int n, int mod) {
  long long x = a, y = 1 % mod;
  while (n) {
    if (n % 2) y = (y * x) % mod;
    x = (x * x) % mod;
    n /= 2;
  }
  return y;
}
int ModInv(int a, int mod) { return ModExp(a, mod - 2, mod); }
pair<long long, long long> ExtentedGCD(int a, int b) {
  if (b == 0)
    return make_pair(1ll, 0ll);
  else {
    long long x, y;
    tie(x, y) = ExtentedGCD(b, a % b);
    return make_pair(y, x - (a / b) * y);
  }
}
void Initialise(int p) {
  for (int i = 1; i < p; ++i) {
    inv[i] = ModInv(i, p);
  }
}
int GetM(int a, int p) {
  int x = 1 % p, m;
  for (m = 1;; ++m) {
    x = (1ll * x * a) % p;
    if (x == 1) break;
  }
  return m;
}
int main() {
  int a, b, p, m, k1, k2;
  long long x, N, ans = 0;
  cin >> a >> b >> p >> x;
  Initialise(p);
  m = GetM(a, p);
  tie(k1, k2) = ExtentedGCD(m, p);
  N = 1ll * m * p;
  for (int i = 0, y = 1; i < m; ++i, y = (1ll * y * a) % p) {
    int j = (1ll * b * inv[y]) % p;
    long long z = 1ll * j * k1 * m + 1ll * i * k2 * p;
    z %= N;
    z = (z + N) % N;
    ans += (x / N);
    if (x % N != 0) ans += (x % N >= z);
    if (z == 0) --ans;
  }
  cout << ans << '\n';
  return 0;
}
