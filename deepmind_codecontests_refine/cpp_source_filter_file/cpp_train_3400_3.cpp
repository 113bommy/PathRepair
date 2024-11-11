#include <bits/stdc++.h>
using namespace std;
const int N = 300010, mod = 998244353;
int n, A, B, top, rev[N], fac[N], inv[N], pw[N], S[N], a[N], b[N];
int ksm(int a, int b) {
  int res = 1;
  for (; b; a = 1ll * a * a % mod, b >>= 1)
    if (b & 1) res = 1ll * res * a % mod;
  return res;
}
void NTT(int a[], int n, int f) {
  for (int i = 0; i < n; i++)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int i = 1; i < n; i <<= 1) {
    int wn =
        ksm(3, f ? (mod - 1) / (i << 1) : (mod - 1) - (mod - 1) / (i << 1));
    for (int p = i << 1, j = 0; j < n; j += p) {
      int w = 1;
      for (int k = 0; k < i; k++, w = 1ll * w * wn % mod) {
        int x = a[j + k], y = 1ll * w * a[i + j + k] % mod;
        a[j + k] = (x + y) % mod;
        a[i + j + k] = (x - y + mod) % mod;
      }
    }
  }
  if (f) return;
  int inv = ksm(n, mod - 2);
  for (int i = 0; i < n; i++) a[i] = 1ll * a[i] * inv % mod;
}
void solve(int l) {
  if (l <= 1) {
    S[l] = 1;
    return;
  }
  if (l & 1) {
    solve(l - 1);
    for (int i = l; i; i--) S[i] = (S[i - 1] + 1ll * S[i] * (l - 1)) % mod;
  } else {
    int m = l >> 1, n = 1, L = 0;
    solve(m);
    for (; n <= l; n <<= 1) L++;
    pw[0] = 1;
    for (int i = (1); i <= (m); i++) pw[i] = 1ll * pw[i - 1] * m % mod;
    for (int i = (0); i <= (m); i++) a[i] = 1ll * S[i] * fac[i] % mod;
    for (int i = (0); i <= (m); i++) b[i] = 1ll * pw[m - i] * inv[m - i] % mod;
    for (int i = 0; i < n; i++)
      rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (L - 1));
    NTT(a, n, 1);
    NTT(b, n, 1);
    for (int i = 0; i < n; i++) a[i] = 1ll * a[i] * b[i] % mod;
    NTT(a, n, 0);
    for (int i = (0); i <= (m); i++)
      a[i] = 1ll * a[i + m] * fac[i] % mod, b[i] = S[i];
    for (int i = (m + 1); i <= (n); i++) a[i] = b[i] = 0;
    NTT(a, n, 1);
    NTT(b, n, 1);
    for (int i = 0; i < n; i++) a[i] = 1ll * a[i] * b[i] % mod;
    NTT(a, n, 0);
    for (int i = (0); i <= (l); i++) S[i] = a[i];
    for (int i = 0; i < n; i++) a[i] = b[i] = 0;
  }
}
int main() {
  scanf("%d%d%d", &n, &A, &B);
  int m = max(A + B, n);
  fac[0] = 1;
  for (int i = (1); i <= (m); i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  inv[m] = ksm(fac[m], mod - 2);
  for (int i = m - 1; ~i; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
  solve(n - 1);
  int ans = 1ll * fac[A + B - 2] * inv[A - 1] % mod * inv[B - 1] % mod *
            S[A + B - 2] % mod;
  printf("%d\n", ans);
  return 0;
}
