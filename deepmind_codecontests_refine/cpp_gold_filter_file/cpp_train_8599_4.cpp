#include <bits/stdc++.h>
using namespace std;
const int mo = 998244353;
const int FFTN = 1 << 16;
const int N = FFTN + 5;
int w[N], W[N], R[N];
int A[N], B[N], C[N];
int D[N], E[N], F[N];
unsigned long long p[N];
int power(int x, int y) {
  int s = 1;
  for (; y; y /= 2, x = 1ll * x * x % mo)
    if (y & 1) s = 1ll * s * x % mo;
  return s;
}
void FFTinit() {
  W[0] = 1;
  W[1] = power(3, (mo - 1) / FFTN);
  for (int i = (int)(2); i <= (int)(N - 1); i++)
    W[i] = 1ll * W[i - 1] * W[1] % mo;
}
int FFTinit(int n) {
  int L = 1;
  for (; L <= n; L <<= 1)
    ;
  for (int i = (int)(0); i <= (int)(L - 1); i++)
    R[i] = (R[i >> 1] >> 1) | ((i & 1) ? (L >> 1) : 0);
  return L;
}
void DFT(int *a, int n) {
  for (int i = (int)(0); i <= (int)(n - 1); i++) p[R[i]] = a[i];
  for (int d = 1; d < n; d <<= 1) {
    int len = FFTN / (d << 1);
    for (int i = 0, j = 0; i < d; i++, j += len) w[i] = W[j];
    for (int i = 0; i < n; i += (d << 1))
      for (int j = 0; j < d; j++) {
        int y = p[i + j + d] * w[j] % mo;
        p[i + j + d] = p[i + j] + mo - y;
        p[i + j] += y;
      }
  }
  for (int i = (int)(0); i <= (int)(n - 1); i++) a[i] = p[i] % mo;
}
void IDFT(int *a, int n) {
  for (int i = (int)(0); i <= (int)(n - 1); i++) p[R[i]] = a[i];
  for (int d = 1; d < n; d <<= 1) {
    int len = FFTN / (d << 1);
    for (int i = 0, j = FFTN; i < d; i++, j -= len) w[i] = W[j];
    for (int i = 0; i < n; i += (d << 1))
      for (int j = 0; j < d; j++) {
        int y = p[i + j + d] * w[j] % mo;
        p[i + j + d] = p[i + j] + mo - y;
        p[i + j] += y;
      }
  }
  int val = power(n, mo - 2);
  for (int i = (int)(0); i <= (int)(n - 1); i++) a[i] = p[i] * val % mo;
}
int n, g[N];
int g0[N], g1[N], g2[N];
int f0[N], f1[N], f2[N];
void divide(int l, int r) {
  if (l == r) {
    f0[l] = (f0[l] + g0[l]) % mo;
    f1[l] = (f1[l] + g1[l]) % mo;
    f2[l] = (f2[l] + g2[l]) % mo;
    return;
  }
  int mid = (l + r) / 2;
  divide(l, mid);
  int L = FFTinit(r - l + 10);
  for (int i = (int)(0); i <= (int)(L - 1); i++)
    A[i] = B[i] = C[i] = D[i] = E[i] = F[i] = 0;
  for (int i = (int)(l); i <= (int)(mid); i++)
    A[i - l] = f0[i], B[i - l] = f1[i], C[i - l] = f2[i];
  for (int i = (int)(0); i <= (int)(r - l); i++)
    D[i] = g0[i], E[i] = g1[i], F[i] = g2[i];
  DFT(A, L);
  DFT(B, L);
  DFT(C, L);
  DFT(D, L);
  DFT(E, L);
  DFT(F, L);
  for (int i = (int)(0); i <= (int)(L - 1); i++) {
    C[i] = 1ll * C[i] * F[i] % mo;
    F[i] = 1ll * F[i] * B[i] % mo;
    B[i] = 1ll * B[i] * E[i] % mo;
    E[i] = 1ll * E[i] * A[i] % mo;
    A[i] = 1ll * A[i] * D[i] % mo;
  }
  IDFT(A, L);
  IDFT(B, L);
  IDFT(C, L);
  IDFT(D, L);
  IDFT(E, L);
  IDFT(F, L);
  for (int i = (int)(mid + 1); i <= (int)(r); i++) {
    f0[i] = (1ll * f0[i] + A[i - l - 1] + (i >= l + 3 ? B[i - l - 3] : 0)) % mo;
    f1[i] = (1ll * f1[i] + E[i - l - 1] + (i >= l + 3 ? F[i - l - 3] : 0)) % mo;
    f2[i] = (1ll * f2[i] + B[i - l - 1] + (i >= l + 3 ? C[i - l - 3] : 0)) % mo;
  }
  divide(mid + 1, r);
}
int main() {
  FFTinit();
  scanf("%d", &n);
  g[0] = 1;
  g[2] = 1;
  for (int i = 4; i <= n; i += 2) g[i] = (g[i - 2] + g[i - 4]) % mo;
  for (int i = (int)(0); i <= (int)(n); i++) {
    g0[i] = 1ll * g[i] * i * i % mo;
    g1[i] = 1ll * g[i] * (i + 1) * (i + 1) % mo;
    g2[i] = 1ll * g[i] * (i + 2) * (i + 2) % mo;
  }
  divide(0, n);
  int ans = 0;
  ans = (ans + 1ll * n * g0[n - 1]) % mo;
  ans = (ans + 1ll * n * g2[n - 3]) % mo;
  for (int i = (int)(0); i <= (int)(n - 2); i++)
    ans = (ans + 1ll * g0[i] * f0[n - i - 2] % mo * (i + 1)) % mo;
  for (int i = (int)(0); i <= (int)(n - 4); i++)
    ans = (ans + 2ll * g1[i] * f1[n - i - 4] % mo * (i + 2)) % mo;
  for (int i = (int)(0); i <= (int)(n - 6); i++)
    ans = (ans + 1ll * g2[i] * f2[n - i - 6] % mo * (i + 3)) % mo;
  printf("%d\n", ans);
}
