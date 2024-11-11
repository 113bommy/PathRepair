#include <bits/stdc++.h>
using ll = long long;
const int C = 600001, M = 998244353;
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
void butterfly(int n, int dp[]) {
  int m = n / 2, i, curcon = 1, j;
  dp[0] = 0;
  for (j = 1; j < n;) {
    for (i = 0; i < curcon; i++, j++) dp[j] = dp[j - curcon] + m;
    curcon *= 2, m /= 2;
  }
}
ll tmp[C];
int dp[C];
void dft(ll poly[], int n, ll w[], ll M, ll res[]) {
  int i, d, cur, beg, tzar, md;
  ll nw;
  butterfly(n, dp);
  for (i = 0; i < n; i++) res[i] = poly[dp[i]];
  for (cur = 2, d = 1; cur <= n; cur *= 2, d++) {
    for (beg = 0; beg < n; beg += cur) {
      nw = 1;
      tzar = cur / 2;
      for (i = 0; i < cur; i++) {
        md = (i >= tzar ? i - tzar : i);
        tmp[beg + i] = (res[beg + md] + nw * res[beg + tzar + md]) % M;
        nw = (nw * w[d]) % M;
      }
    }
    for (i = 0; i < n; i++) res[i] = tmp[i];
  }
}
const int D = 21;
ll res1[C], res2[C], full_mul[C], w[D], iw[D];
void ntt_full(ll a[], int n, ll b[], int m, ll M, ll finale[]) {
  int i = 1, mn = n + m, close = 0, p0 = 1;
  for (i = 1;; i <<= 1) {
    if ((i ^ mn) == 0) break;
    if ((i ^ mn) < mn) mn ^= i, close = 1;
    p0++;
  }
  if (close == 1) mn <<= 1, p0++;
  ll inn = pow(mn, M - 2, M);
  ll root = 3;
  ll w0 = pow(root, 17 * 7 * (1 << (23 - p0)), M);
  w[p0] = w0;
  iw[p0] = pow(w0, M - 2, M);
  for (i = p0 - 1; i >= 0; i--) w[i] = (w[i + 1] * w[i + 1]) % M;
  for (i = p0 - 1; i >= 0; i--) iw[i] = (iw[i + 1] * iw[i + 1]) % M;
  dft(a, mn, w, M, res1);
  dft(b, mn, w, M, res2);
  for (i = 0; i < mn; i++) full_mul[i] = (res1[i] * res2[i]) % M;
  dft(full_mul, mn, iw, M, finale);
  for (i = 0; i < mn; i++) finale[i] = (finale[i] * inn) % M;
}
ll tmp2[C], a_pow_polynom[C];
int pow_polynominal(ll pol[], int n, ll b, ll M, ll res[]) {
  int res_ln = 1, a_ln = n, i;
  for (i = 0; i < n; i++) a_pow_polynom[i] = pol[i];
  res[0] = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      ntt_full(res, res_ln, a_pow_polynom, a_ln, M, tmp2);
      res_ln = res_ln + a_ln - 1;
      for (i = 0; i < res_ln; i++) res[i] = tmp2[i];
    }
    b /= 2;
    if (b > 0) {
      ntt_full(a_pow_polynom, a_ln, a_pow_polynom, a_ln, M, tmp2);
      a_ln = a_ln + a_ln - 1;
      for (i = 0; i < a_ln; i++) a_pow_polynom[i] = tmp2[i];
    }
  }
  return res_ln;
}
ll polynominal[C], result[C];
int a[C];
int main() {
  int n, i, b = 0, res_len;
  ll h, sum = 0;
  scanf("%d %lld", &n, &h);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  for (i = 0; i < n; i++) {
    if (a[i] != a[(i + 1) % n]) b += 1;
  }
  polynominal[0] = polynominal[2] = 1;
  polynominal[1] = h - 2;
  res_len = pow_polynominal(polynominal, 3, b, M, result);
  for (i = res_len / 2 + 1; i < res_len; i++) sum = sum + result[i] % M;
  printf("%lld\n", (sum * pow(h, n - b, M)) % M);
  return 0;
}
