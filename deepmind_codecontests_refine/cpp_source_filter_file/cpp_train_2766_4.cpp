#include <bits/stdc++.h>
using namespace std;
const int G = 3, Mod = 998244353;
int rev[1 << 16];
inline long long Qpow(long long x, int p) {
  static long long res;
  for (res = 1; p; p >>= 1, x = x * x % Mod)
    if (p & 1) res = res * x % Mod;
  return res;
}
inline void ntt(int X[], const int n, const char op) {
  for (int i = 1; i < n; ++i)
    if (rev[i] > i) swap(X[rev[i]], X[i]);
  for (int i = 1; i < n; i <<= 1) {
    long long wx = Qpow(G, op ? (Mod - 1) - (Mod - 1) / (i << 1)
                              : (Mod - 1) / (i << 1)),
              x, y;
    for (int j = 0, k = 0; j < n; k = j += i << 1)
      for (long long wn = 1; k < j + i; ++k, wn = wn * wx % Mod) {
        x = X[k], y = X[k + i] * wn % Mod;
        X[k] = x + y >= Mod ? x + y - Mod : x + y;
        X[k + i] = x < y ? x + Mod - y : x - y;
      }
  }
  if (op) {
    long long Inv = Qpow(n, Mod - 2);
    for (int i = 0; i < n; ++i) X[i] = X[i] * Inv % Mod;
  }
}
int N, K, n, f[1 << 15], g[1 << 15], h[1 << 15], A[1 << 16], B[1 << 16],
    C[1 << 16];
inline void Inc() {
  for (int i = 0; i <= K; ++i) f[i] = g[i], g[i] = h[i];
  h[0] = g[0];
  for (int i = 1; i <= K; ++i) {
    (h[i] = (g[i] + g[i - 1])) >= Mod && (h[i] -= Mod);
    (h[i] += f[i - 1]) >= Mod && (h[i] -= Mod);
  }
}
inline void Shift() {
  memcpy(A, f, sizeof(int) * n), ntt(A, n, 0);
  memcpy(B, g, sizeof(int) * n), ntt(B, n, 0);
  memcpy(C, h, sizeof(int) * n), ntt(C, n, 0);
  long long wx = Qpow(G, (Mod - 1) / n), a, b, c;
  for (int i = 0, wn = 1; i < n; ++i, wn = wn * wx % Mod) {
    a = A[i], b = B[i], c = C[i];
    A[i] = (b * b + a * a % Mod * wn) % Mod;
    B[i] = (b * c + a * b % Mod * wn) % Mod;
    C[i] = (c * c + b * b % Mod * wn) % Mod;
  }
  ntt(A, n, 1), ntt(B, n, 1), ntt(C, n, 1);
  memcpy(f, A, sizeof(int) * (K + 1));
  memcpy(g, B, sizeof(int) * (K + 1));
  memcpy(h, C, sizeof(int) * (K + 1));
}
int main() {
  scanf("%d %d", &N, &K), h[0] = 1;
  int r;
  for (r = 1; (1 << r) < N; ++r)
    ;
  for (n = 1; n <= K + K; n <<= 1)
    ;
  for (int i = 1; i < n; ++i) rev[i] = rev[i >> 1] >> 1 | (i & 1 ? n >> 1 : 0);
  for (int i = r; ~i; --i) {
    Shift();
    if (N >> i & 1) Inc();
  }
  for (int i = 1; i <= K; ++i) printf("%d ", h[i]);
  return 0;
}
