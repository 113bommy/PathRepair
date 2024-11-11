#include <bits/stdc++.h>
const long long maxn = int(2e5) + 7, mod = int(1e9) + 9;
long long n, a, b, pow_ab[maxn], k, sum;
long long base_ab, base_a, base_b, flag[maxn];
char str[maxn];
long long power_mod(long long p, long long q) {
  long long ret = 1;
  while (q) {
    if (q & 1) ret = ret * p % mod;
    p = p * p % mod;
    q >>= 1;
  }
  return ret;
}
void init() {
  pow_ab[0] = power_mod(a, n);
  base_b = b;
  base_a = power_mod(a, mod - 2);
  for (int i = 1; i < k; i++)
    pow_ab[i] = pow_ab[i - 1] * base_a % mod * base_b % mod;
  base_ab = power_mod(power_mod(a, k), mod - 2) * power_mod(b, k) % mod;
}
int main() {
  std::cin >> n >> a >> b >> k >> str;
  if (n + 1 < k) k = n + 1;
  init();
  for (int i = 0; i < k; i++) flag[i] = (str[i] == '-' ? -1 : 1);
  long long t = (n + 1) / k;
  if (a == b)
    for (int i = 0; i < k; i++)
      sum = (sum + (pow_ab[i] * flag[i] + mod) % mod * t % mod) % mod;
  else {
    long long tmp = (1ll - power_mod(base_ab, t) + mod) % mod;
    tmp = tmp * power_mod((1ll - base_ab + mod) % mod, mod - 2) % mod;
    for (int i = 0; i < k; i++)
      sum = (sum + (pow_ab[i] * flag[i] + mod) % mod * tmp % mod) % mod;
  }
  std::cout << sum % mod << std::endl;
  return 0;
}
