#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
const int CN = 1e5 + 10;
long long read() {
  long long s = 0, ne = 1;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') ne = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) s = (s << 1) + (s << 3) + c - '0';
  return s * ne;
}
int add(int x, int y) { return x + y >= P ? x + y - P : x + y; }
int qp(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = 1ll * r * a % P;
    a = 1ll * a * a % P, b >>= 1;
  }
  return r;
}
int inv(int x) { return qp(x, P - 2); }
int rev[CN << 2];
void cg(int t[], int n) {
  for (int i = 0; i < n; i++) rev[i] = (rev[i >> 1] >> 1) + (i & 1) * (n >> 1);
  for (int i = 0; i < n; i++)
    if (i < rev[i]) swap(t[i], t[rev[i]]);
}
void ntt(int t[], int n, int tp) {
  cg(t, n);
  for (int w = 2; w <= n; w <<= 1) {
    int l = w >> 1, gn = qp(tp ? 3 : inv(3), (P - 1) / w);
    for (int i = 0; i < n; i += w) {
      int g = 1;
      for (int j = i; j < i + l; j++) {
        int u = t[j], v = 1ll * g * t[j + l] % P;
        t[j] = add(u, v), t[j + l] = add(u, P - v), g = 1ll * g * gn % P;
      }
    }
  }
  if (!tp) {
    int in = inv(n);
    for (int i = 0; i < n; i++) t[i] = 1ll * t[i] * in % P;
  }
}
void conv(int A[], int B[], int n) {
  int N = 1;
  while (N < (n << 1)) N <<= 1;
  ntt(A, N, 1), ntt(B, N, 1);
  for (int i = 0; i < N; i++) A[i] = 1ll * A[i] * B[i] % P;
  ntt(A, N, 0);
  for (int i = n; i < N; i++) A[i] = 0;
  for (int i = 0; i < N; i++) B[i] = 0;
}
int A[CN << 2], B[CN << 2];
int n, m, p[CN], fac[CN], ifac[CN], g[CN];
int main() {
  n = read() + 1, m = read() % (P - 1);
  fac[0] = 1;
  for (int i = 1; i < n; i++) fac[i] = 1ll * fac[i - 1] * i % P;
  ifac[n - 1] = inv(fac[n - 1]);
  for (int i = n - 2; i + 1; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % P;
  for (int i = 0; i < n; i++) p[i] = read();
  for (int i = 0; i < n; i++) A[n - i - 1] = 1ll * fac[i] * p[i] % P;
  for (int i = 0; i < n; i++) B[i] = ifac[i];
  conv(A, B, n);
  for (int i = 0; i < n; i++) g[i] = 1ll * ifac[i] * A[n - i - 1] % P;
  for (int i = 0; i < n; i++) g[i] = 1ll * g[i] * inv(qp(i + 1, m)) % P;
  for (int i = 0; i < n; i++) A[n - i - 1] = 1ll * fac[i] * g[i] % P;
  for (int i = 0; i < n; i++) B[i] = i & 1 ? P - ifac[i] : ifac[i];
  conv(A, B, n);
  for (int i = 0; i < n; i++)
    printf("%d ", int(1ll * ifac[i] * A[n - i - 1] % P));
  puts("");
  return 0;
}
