#include <bits/stdc++.h>
using namespace std;
long long powerMOD(long long a, long long b, long long c) {
  long long ret = 1;
  while (b > 0) {
    if (b & 1) {
      ret = (ret * a) % c;
    }
    a = (a * a) % c;
    b >>= 1;
  }
  return (ret % c);
}
int main() {
  long long n, k, i;
  scanf("%lld %lld", &n, &k);
  if (n <= 62) {
    if (k > (1 << n)) {
      printf("1 1\n");
      return 0;
    }
  }
  long long pw = 0, t1 = 2;
  for (i = 1; i <= 62; i++) {
    pw += (k - 1) / t1;
    t1 *= 2;
  }
  long long MOD = 1e6 + 3;
  if ((k - 1) >= MOD) {
    long long temp = powerMOD(2, k - 1, MOD);
    temp = powerMOD(temp, n, MOD);
    long long t2 = powerMOD(2, pw, MOD);
    temp = (temp * powerMOD(t2, MOD - 2, MOD)) % MOD;
    printf("%lld %lld\n", temp, temp);
  } else {
    long long num = 1;
    for (i = 1; i <= (k - 1); i++) {
      num = (num * (((powerMOD(2, n, MOD) - i) % MOD) + MOD)) % MOD;
    }
    long long temp = powerMOD(2, k - 1, MOD);
    temp = powerMOD(temp, n, MOD);
    long long t2 = powerMOD(2, pw, MOD);
    num = (num * powerMOD(t2, MOD - 2, MOD)) % MOD;
    temp = (temp * powerMOD(t2, MOD - 2, MOD)) % MOD;
    num = (temp - num) % MOD;
    if (num < 0) {
      num += MOD;
    }
    printf("%lld %lld\n", num, temp);
  }
  return 0;
}
