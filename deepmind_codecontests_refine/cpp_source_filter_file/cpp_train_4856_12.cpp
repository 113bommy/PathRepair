#include <bits/stdc++.h>
const int lim = 1 << 17, mod = 1000000007, il = 742744451;
int cnt[lim], a[17][lim], t[17][lim], b[lim], c[lim], f[lim];
void reduce(int &x) { x += x >> 31 & mod; }
void fwt_xor(int *A, int typ) {
  for (int i = 1; i < lim; i <<= 1)
    for (int j = 0; j < lim; j += i << 1)
      for (int k = 0; k < i; ++k) {
        const int x = A[k + j], y = A[k + j + i];
        reduce(A[k + j] += y - mod), reduce(A[k + j + i] = x - y);
      }
  if (!typ)
    for (int i = 0; i < lim; ++i) A[i] = (long long)A[i] * il % mod;
}
void fwt(int *A) {
  for (int i = 1; i < lim; i <<= 1)
    for (int j = 0; j < lim; j += i << 1)
      for (int k = 0; k < i; ++k) reduce(A[k + j + i] += A[k + j] - mod);
}
void ifwt(int *A) {
  for (int i = 1; i < lim; i <<= 1)
    for (int j = 0; j < lim; j += i << 1)
      for (int k = 0; k < i; ++k) reduce(A[k + j + i] -= A[k + j]);
}
int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n, x;
  std::cin >> n;
  while (n--) std::cin >> x, ++cnt[x];
  for (int i = 0; i < lim; ++i)
    b[i] = cnt[i], t[__builtin_popcount(i)][i] = cnt[i];
  for (int i = 0; i < 17; ++i) fwt(t[i]);
  for (int i = 0; i < 17; ++i)
    for (int j = 0; i + j < 17; ++j)
      for (int k = 0; k < lim; ++k)
        a[i + j][k] = (a[i + j][k] + (long long)t[i][k] * t[j][k]) % mod;
  for (int i = 0; i < 17; ++i) ifwt(a[i]);
  for (int i = 0; i < lim; ++i) c[i] = a[__builtin_popcount(i)][i];
  fwt_xor(b, 1);
  for (int i = 0; i < lim; ++i) b[i] = (long long)b[i] * b[i] % mod;
  fwt_xor(b, 0);
  f[1] = 1;
  for (int i = 2; i < lim; ++i) reduce(f[i] = f[i - 1] + f[i - 2] - mod);
  for (int i = 0; i < lim; ++i)
    b[i] = (long long)b[i] * f[i] % mod, c[i] = (long long)c[i] * f[i] % mod,
    cnt[i] = (long long)cnt[i] * f[i] % mod;
  std::reverse(b, b + lim), std::reverse(c, c + lim),
      std::reverse(cnt, cnt + lim);
  fwt(b), fwt(c), fwt(cnt);
  for (int i = 0; i < lim; ++i)
    cnt[i] = (long long)b[i] * c[i] % mod * cnt[i] % mod;
  ifwt(cnt), std::reverse(cnt, cnt + lim);
  int ans = 0;
  for (int i = 1; i < lim; i <<= 1) reduce(ans += cnt[i] - mod);
  std::cout << ans << '\n';
  return 0;
}
