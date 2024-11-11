#include <bits/stdc++.h>
using namespace std;
long long MOD, L, R, d, k, ans;
map<long long, long long> F;
long long fib(long long x) {
  if (x < 2) return 1 % MOD;
  if (F.count(x)) return F[x];
  long long k = x / 2;
  if (x % 2)
    return F[x] = (fib(k) * fib(k + 1) % MOD + fib(k) * fib(k - 1) % MOD) % MOD;
  return F[x] = (fib(k) * fib(k) % MOD + fib(k - 1) * fib(k - 1) % MOD) % MOD;
}
void cmon(long long x) {
  if (x && R / x - (L - 1) / x >= k) ans = max(ans, x);
}
void check(long long x) {
  long long l, r;
  for (l = 1; l <= x; l = r + 1) {
    r = x / (x / l);
    cmon(l - 1);
    cmon(l);
    cmon(l + 1);
    cmon(r - 1);
    cmon(r);
    cmon(r + 1);
  }
}
int main() {
  scanf("%lld %lld %lld %lld", &MOD, &L, &R, &k);
  d = R - L + 1;
  ans = d / k;
  check(R);
  check(L - 1);
  printf("%lld\n", fib(ans - 1));
  return 0;
}
