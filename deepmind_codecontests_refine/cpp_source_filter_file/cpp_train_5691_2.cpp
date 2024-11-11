#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
int fac[maxn];
int ifac[maxn];
inline int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}
inline int dec(int a, int b) {
  a -= b;
  if (a < mod) a += mod;
  return a;
}
inline int mul(int a, int b) { return 1ll * a * b % mod; }
inline int mul(int a, int b, int c) { return 1ll * a * b % mod * c % mod; }
void initial(const int n = 2e5) {
  fac[0] = 1;
  fac[1] = 1;
  for (int i = 2; i <= n; i++) fac[i] = mul(i, fac[i - 1]);
  ifac[0] = 1;
  ifac[1] = 1;
  for (int i = 2; i <= n; i++) ifac[i] = mul(dec(mod, mod / i), ifac[mod % i]);
  for (int i = 2; i <= n; i++) ifac[i] = mul(ifac[i], ifac[i - 1]);
}
inline int C(int n, int m) { return mul(fac[n], ifac[m], ifac[n - m]); }
int quickpow(int a, int n) {
  int res = 1;
  a %= mod;
  while (n) {
    if (n & 1) res = mul(res, a);
    a = mul(a, a);
    n >>= 1;
  }
  return res;
}
int s(int n, int k) {
  int res = 0;
  for (int j = 0; j <= k; j++) {
    int update = mul(C(k, j), quickpow(j, n));
    if ((j + k) & 1)
      res = dec(res, update);
    else
      res = add(res, update);
  }
  res = mul(res, ifac[k]);
  return res;
}
int main(void) {
  initial();
  int n, k;
  scanf("%d%d", &n, &k);
  int res = add(s(n, k), mul(n - 1, s(n - 1, k)));
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    sum = add(sum, x);
  }
  res = mul(res, sum);
  printf("%d\n", res);
  return 0;
}
