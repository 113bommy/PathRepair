#include <bits/stdc++.h>
using namespace std;
long long n, k, h[200005], num;
long long fac[200005], inv[200005];
const long long mo = 998244353;
long long ans;
long long qpow(long long a, long long b) {
  long long s = 1;
  while (b) {
    if (b & 1) s = s * a % mo;
    a = a * a % mo;
    b >>= 1;
  }
  return s;
}
void init() {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mo;
  inv[n] = qpow(fac[n], mo - 2);
  for (int i = n - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mo;
}
long long C(int n, int m) { return fac[n] * inv[m] % mo * inv[n - m] % mo; }
int main() {
  scanf("%lld%lld", &n, &k);
  init();
  for (int i = 1; i <= n; i++) scanf("%lld", &h[i]);
  h[n + 1] = h[1];
  for (int i = 1; i <= n; i++)
    if (h[i] != h[i + 1]) num++;
  for (int i = 1; i <= num; i++) {
    long long tmp = qpow(2, i);
    if ((i & 1) == 0) tmp = (tmp - C(i, i >> 1) + mo) % mo;
    ans =
        (ans + qpow(k - 2, num - i) * tmp % mo * inv[2] % mo * C(num, i) % mo) %
        mo;
  }
  ans = (ans * qpow(k, n - num)) % mo;
  printf("%lld", ans);
  return 0;
}
