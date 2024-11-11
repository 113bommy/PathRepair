#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const long long mod = 998244353, inv2 = (mod + 1) / 2;
long long fac[maxn], inv[maxn];
int n, k, h[maxn];
void up(long long &a, long long b) {
  a += b;
  a %= mod;
}
long long power(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return res;
}
void init() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < maxn; i++)
    fac[i] = fac[i - 1] * i % mod, inv[i] = power(fac[i], mod - 2);
}
long long C(int n, int m) {
  if (n < m) return 0;
  return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i <= n - 1; i++) cin >> h[i];
  int num = n;
  long long coef = 1;
  for (int i = 0; i <= n - 1; i++) {
    if (h[i] == h[(i + 1) % n]) coef = coef * k % mod, num--;
  }
  init();
  long long ans = 0;
  for (int i = 0; i <= num; i++) {
    long long cur = power(k - 2, i) * C(num, i) % mod;
    long long cur2 = power(2, num - i);
    if ((num - i) % 2 == 0)
      cur2 = (cur2 - C(num - i, (num - i) / 2) + mod) % mod;
    cur2 = cur2 * inv2 % mod;
    up(ans, cur * cur2);
  }
  cout << ans * coef % mod << endl;
}
