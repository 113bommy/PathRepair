#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int mod = 998244353;
int n, k, a[N];
long long pow_mod(long long x, int p) {
  long long s = 1;
  while (p) {
    if (p & 1) {
      s = s * x % mod;
    }
    x = x * x % mod;
    p >>= 1;
  }
  return s;
}
long long fac[N], rev[N], P[N];
long long C(int n, int m) { return fac[n] * rev[m] % mod * rev[n - m] % mod; }
long long solve(int p) {
  fac[0] = 1;
  rev[0] = 1;
  P[0] = 1;
  for (int i = 1; i <= p; i++) {
    fac[i] = fac[i - 1] * i % mod;
    P[i] = P[i - 1] * 2 % mod;
  }
  rev[p] = pow_mod(fac[p], mod - 2);
  for (int i = p; i > 1; i--) {
    rev[i - 1] = rev[i] * i % mod;
  }
  long long ret = 0;
  long long cur;
  for (int i = 1; i <= p; i++) {
    cur = C(p, i) * pow_mod(k - 2, p - i) % mod;
    if (i % 2 == 1) {
      cur = cur * P[i - 1];
    } else {
      cur = cur * (P[i] - C(i, i / 2) + mod) % mod * rev[2] % mod;
    }
    ret += cur;
  }
  return ret % mod;
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  a[0] = a[n];
  if (k == 1) {
    puts("0");
    return 0;
  }
  int p = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == a[i - 1]) {
      p++;
    }
  }
  int q = n - p;
  long long ans = solve(q);
  printf("%I64d\n", ans * pow_mod(k, p) % mod);
  return 0;
}
