#include <bits/stdc++.h>
const long long modulo = (int)1e9 + 7;
long long ok(long long x) {
  x %= modulo;
  if (x < 0) x += modulo;
  return x;
}
long long pow(long long x, int b) {
  long long r = 1;
  for (; b; b >>= 1) {
    if (b & 1) r = ok(r * x);
    x = ok(x * x);
  }
  return r;
}
long long rev(long long x) { return pow(x, modulo - 2); }
int main() {
  int n, k;
  assert(scanf("%d%d", &n, &k) == 2);
  long long fact[n + 1];
  fact[0] = fact[1] = 1;
  for (int i = 2; i <= n; i++) fact[i] = ok(fact[i - 1] * i);
  long long F[n + 1];
  F[1] = F[2] = 1;
  for (int N = 3; N <= n; N++) {
    long long tmp = F[N - 1] * (1 + ok(fact[N - 3] * rev(fact[N - 2])));
    if (N - 1 - k >= 1) {
      long long tmp2 = fact[N - 3] * rev(fact[N - k - 2]);
      tmp -= F[N - k - 1] * ok(tmp2);
    }
    F[N] = ok((N - 2) * ok(tmp));
  }
  long long ans = fact[n];
  for (int T = 1; T <= n; T++) {
    long long tmp = F[T] * fact[n - 1];
    tmp = ok(tmp) * rev(fact[T - 1]);
    ans = ok(ans - ok(tmp));
  }
  printf("%d\n", (int)ans);
  return 0;
}
