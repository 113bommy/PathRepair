#include <bits/stdc++.h>
long long mod = 998244353;
long long Pow(long long x, long long y) {
  long long ans = 1;
  for (long long i = 1; y; i <<= 1, x = x * x % mod)
    if (y & i) {
      ans = ans * x % mod;
      y ^= i;
    }
  return ans;
}
long long prod[1100] = {0};
long long Comb(long long x, long long y) {
  return prod[x] * Pow(prod[y], mod - 2) % mod * Pow(prod[x - y], mod - 2) %
         mod;
}
int val[1100] = {0};
long long all[1100] = {0};
int main() {
  prod[0] = 1;
  for (int i = 1; i <= 1000; i++) prod[i] = prod[i - 1] * i % mod;
  int num;
  scanf("%d", &num);
  for (int i = 1; i <= num; i++) scanf("%d", &val[i]);
  all[num + 1] = 1;
  for (int i = num; i > 0; i--)
    if (val[i] <= 0 || i + val[i] > num)
      all[i] = all[i + 1];
    else {
      long long yes = 0;
      for (int pos = i + val[i]; pos <= num; pos++)
        yes += Comb(pos - i - 1, val[i] - 1) * all[pos + 1] % mod;
      all[i] = (yes + all[i + 1]) % mod;
    }
  printf("%I64d\n", all[1] - 1);
  return 0;
}
