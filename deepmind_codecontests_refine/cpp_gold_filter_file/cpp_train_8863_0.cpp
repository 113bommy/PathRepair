#include <bits/stdc++.h>
using ll = long long;
const int C = 5001, M = 998244353;
inline ll pow(ll a, ll b, ll M) {
  if (b == 0) return 1;
  ll c = 1;
  while (b > 0) {
    if (b % 2 == 1) c = (c * a) % M;
    b /= 2;
    a = (a * a) % M;
  }
  return c;
}
ll fac[C], af[C], inv[C], pw[C];
void formulate_fac(int n) {
  int i;
  fac[0] = af[0] = 1;
  for (i = 1; i < n; i++) fac[i] = (i * fac[i - 1]) % M;
  for (i = 1; i < n; i++) af[i] = (pow(i, M - 2, M) * af[i - 1]) % M;
}
inline ll cn(int n, int k) {
  if (n < k || n < 0 || k < 0) return 0;
  return (((fac[n] * af[k]) % M) * af[n - k]) % M;
}
int main() {
  int n, i, j, sgn_outer, sgn_inner, k;
  ll res = 0, partial_res, summa = 0, l;
  formulate_fac(C);
  pw[0] = 1;
  for (i = 1; i < C; i++) inv[i] = pow(i, M - 2, M);
  for (i = 1; i < C; i++) pw[i] = (pw[i - 1] * 2) % M;
  scanf("%d %d %lld", &n, &k, &l);
  sgn_outer = -1;
  for (i = k; i <= n; i++) {
    sgn_outer *= (-1);
    partial_res = (((cn(n, i) * pw[i]) % M) * cn(i - 1, k - 1)) % M;
    summa = 0, sgn_inner = -1;
    for (j = 0; j <= i; j++) {
      sgn_inner *= (-1);
      summa = (summa + sgn_inner * cn(i, j) * inv[i + j + 1]) % M;
    }
    res = (res + partial_res * summa * sgn_outer) % M;
  }
  if (res < 0) res += M;
  printf("%lld\n", (l * res) % M);
  return 0;
}
