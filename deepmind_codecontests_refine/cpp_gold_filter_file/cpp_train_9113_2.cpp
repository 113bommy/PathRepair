#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000003;
long long n, k;
long long resA, resB;
long long ksm(int x, long long y) {
  if (y == 0) return 1;
  long long t = ksm(x, y / 2);
  t = t * t % MOD;
  if (y & 1) t = t * x % MOD;
  return t;
}
int main() {
  scanf("%I64d%I64d", &n, &k);
  if (n < 62 && k > (1ll << n)) {
    puts("1 1");
    return 0;
  }
  resB = 1ll * ksm(ksm(2, n), k) % MOD;
  long long cnt = n;
  for (int y = 1; y < 62; y++) cnt += (k - 1) / (1ll << y);
  resB = resB * ksm(ksm(2, MOD - 2), cnt) % MOD;
  if (k < MOD) {
    long long tmp = 1;
    long long now = ksm(2, n);
    for (int i = 1; i <= k; i++) {
      tmp = 1ll * tmp * now % MOD;
      now = (now - 1 + MOD) % MOD;
      if (tmp == 0) break;
    }
    tmp = tmp * ksm(ksm(2, MOD - 2), cnt) % MOD;
    resA = (resB - tmp + MOD) % MOD;
  } else
    resA = resB;
  printf("%I64d %I64d\n", resA, resB);
  return 0;
}
