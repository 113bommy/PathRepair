#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
long long f_pow(long long a, long long b) {
  long long res = 1, temp = a;
  while (b) {
    if (b & 1) res = res * temp % mod;
    temp = temp * temp % mod;
    b >>= 1;
  }
  return res;
}
long long fra[2000005];
long long inv[2000005];
long long C(int a, int b) { return fra[a] * inv[b] % mod * inv[a - b] % mod; }
long long pre[2000005];
int main() {
  fra[0] = 1;
  for (int i = 1; i < 2000005; i++) fra[i] = fra[i - 1] * i % mod;
  inv[2000004] = f_pow(fra[2000004], mod - 2);
  for (int i = 2000003; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
  long long n, m;
  pre[0] = 1;
  scanf("%lld %lld", &n, &m);
  for (int i = 1; i <= n; i++) {
    pre[i] = (pre[i - 1] + C(n - i, i)) % mod;
  }
  long long ans = f_pow(m, n);
  for (int i = 0; i < n; i++) {
    ans += f_pow(m, i + 1) * f_pow(2 * m - 1, n - i - 1) % mod;
  }
  printf("%lld\n", ans % mod);
}
