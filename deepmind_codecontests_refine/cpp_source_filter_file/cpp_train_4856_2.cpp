#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int N = 200000;
struct Poly {
  int a[17];
} cnt1[N];
int cnt2[N], cnt3[N], f[N], a[N], b[N], c[N], n, size[N];
int qpower(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) ans = 1ll * ans * a % mod;
  return ans;
}
void FWT_or(Poly a[]) {
  int n = 1 << 17;
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j += i << 1)
      for (int k = 0; k < i; k++)
        for (int t = 0; t < 17; t++)
          a[i + j + k].a[t] = (a[i + j + k].a[t] + a[j + k].a[t]) % mod;
}
void IFWT_or(Poly a[]) {
  int n = 1 << 17;
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j += i << 1)
      for (int k = 0; k < i; k++)
        for (int t = 0; t < 17; t++)
          a[i + j + k].a[t] = (a[i + j + k].a[t] - a[j + k].a[t]) % mod;
}
void FWT_and(int a[]) {
  int n = 1 << 17;
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j += i << 1)
      for (int k = 0; k < i; k++) a[j + k] = (a[j + k] + a[i + j + k]) % mod;
}
void IFWT_and(int a[]) {
  int n = 1 << 17;
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j += i << 1)
      for (int k = 0; k < i; k++) a[j + k] = (a[j + k] - a[i + j + k]) % mod;
}
void FWT_xor(int a[]) {
  int n = 1 << 17;
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j += i << 1)
      for (int k = 0; k < i; k++) {
        int x = a[j + k], y = a[i + j + k];
        a[j + k] = (x + y) % mod, a[i + j + k] = (x - y) % mod;
      }
}
void IFWT_xor(int a[]) {
  int n = 1 << 17;
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j += i << 1)
      for (int k = 0; k < i; k++) {
        int x = a[j + k], y = a[i + j + k];
        a[j + k] = (x + y) % mod, a[i + j + k] = (x - y) % mod;
      }
  int iv = qpower(n, mod - 2);
  for (int i = 0; i < n; i++) a[i] = 1ll * a[i] * iv % mod;
}
int main() {
  scanf("%d", &n);
  size[0] = 0;
  for (int i = 1; i < (1 << 17); i++) size[i] = size[i >> 1] + (i & 1);
  for (int i = 1, x; i <= n; i++)
    scanf("%d", &x), cnt1[x].a[size[x]]++, cnt2[x]++, cnt3[x]++;
  f[0] = 0, f[1] = 1;
  for (int i = 2; i < (1 << 17); i++) f[i] = (f[i - 1] + f[i - 2]) % mod;
  FWT_or(cnt1), FWT_xor(cnt2);
  for (int i = 0; i < (1 << 17); i++) {
    long long t;
    for (int j = 16; j >= 0; j--) {
      t = 0;
      for (int k = 0; k <= j; k++) t += 1ll * cnt1[i].a[k] * cnt1[i].a[j - k];
      cnt1[i].a[j] = t % mod;
    }
  }
  for (int i = 0; i < (1 << 17); i++) cnt2[i] = 1ll * cnt2[i] * cnt2[i] % mod;
  IFWT_or(cnt1);
  IFWT_xor(cnt2);
  for (int i = 0; i < (1 << 17); i++)
    a[i] = 1ll * f[i] * cnt1[i].a[size[i]] % mod,
    b[i] = 1ll * cnt2[i] * f[i] % mod, c[i] = 1ll * cnt3[i] * f[i] % mod;
  FWT_and(a), FWT_and(b), FWT_and(c);
  for (int i = 0; i < (1 << 17); i++)
    f[i] = 1ll * a[i] * b[i] % mod * c[i] % mod;
  IFWT_and(f);
  int ans = 0;
  for (int i = 0; i < 17; i++) ans = (ans + f[1 << i]) % mod;
  cout << (ans + mod) % mod << endl;
}
