#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int oo = 2100000000;
const long long MOD = 1000000007;
long long n, k;
long long a[2003];
long long com[2003];
long long pow_mod(long long x, long long y, long long z) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = (ans * x) % z;
    x = x * x % z;
    y >>= 1;
  }
  return ans;
}
long long com_mod(long long x, long long y) {
  if (y == 0) return 1;
  long long ans = 1;
  for (long long i = 1; i <= y; i++) {
    ans = ans * (x - y + i) % MOD;
    ans = ans * pow_mod(i, MOD - 2, MOD) % MOD;
  }
  return ans;
}
int main() {
  while (scanf("%I64d %I64d", &n, &k) == 2) {
    for (int i = 1; i <= n; i++) scanf("%I64d", a + i);
    long long sum[2003] = {0};
    for (long long i = 1; i <= n; i++) com[i] = com_mod(k + i - 2, i - 1);
    for (long long i = 1; i <= n; i++) {
      for (long long j = i; j <= n; j++) {
        sum[j] += a[i] * com[j - i + 1];
        sum[j] %= MOD;
      }
    }
    for (int i = 1; i <= n; i++) {
      printf("%I64d ", sum[i]);
    }
    printf("\n");
  }
  return (0);
}
