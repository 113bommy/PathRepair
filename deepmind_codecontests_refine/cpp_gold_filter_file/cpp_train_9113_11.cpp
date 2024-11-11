#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000003;
long long n, k;
inline long long fpow(long long x, long long n, long long MOD) {
  long long ret = 1;
  x %= MOD;
  n %= (MOD - 1);
  while (n) {
    if (n & 1) ret = ret * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return ret;
}
int main() {
  scanf("%I64d %I64d", &n, &k);
  if (n <= 62 && (1ll << n) < k) {
    printf("1 1\n");
  } else {
    long long tmp = k, nn = n, sum = 0;
    while (tmp > 0) {
      nn--;
      tmp = (tmp + 1) >> 1;
      if (tmp == 1) {
        sum += nn + 1;
        break;
      } else
        sum += tmp;
      if (nn == 0) break;
    }
    long long m = sum;
    long long inv = fpow(2, m, MOD);
    inv = fpow(inv, MOD - 2, MOD);
    long long den = fpow(2, k, MOD);
    den = fpow(den, n, MOD) * inv % MOD;
    if (k >= MOD) {
      printf("%I64d %I64d\n", den, den);
    } else {
      long long mul = fpow(2, n, MOD), tp = inv;
      for (int i = 0; i < k; i++) {
        tp = tp * mul % MOD;
        if (--mul < 0) mul += MOD;
      }
      long long num = (den - tp + MOD) % MOD;
      printf("%I64d %I64d\n", num, den);
    }
  }
  return 0;
}
