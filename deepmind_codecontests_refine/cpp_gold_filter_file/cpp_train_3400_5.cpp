#include <bits/stdc++.h>
using namespace std;
const int __SIZE = 1 << 18;
char ibuf[__SIZE], *iS, *iT;
template <typename T>
inline void read(T &x) {
  char ch, t = 0;
  x = 0;
  while (!isdigit(ch = (iS == iT
                            ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                               (iS == iT ? EOF : *iS++))
                            : *iS++)))
    t |= ch == '-';
  while (isdigit(ch))
    x = x * 10 + (ch ^ 48),
    ch = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                      (iS == iT ? EOF : *iS++))
                   : *iS++);
  x = t ? -x : x;
}
inline int read_int() {
  int x;
  return read(x), x;
}
inline long long read_ll() {
  long long x;
  return read(x), x;
}
template <typename T>
inline void chkmin(T &a, T b) {
  a = a < b ? a : b;
}
template <typename T>
inline void chkmax(T &a, T b) {
  a = a > b ? a : b;
}
const int mod = 998244353;
const int MAXN = 132000;
inline int Mod(int x) { return x >= mod ? x - mod : x; }
inline int fsp(int x, int k = mod - 2) {
  int s = 1;
  while (k) {
    if (k & 1) s = 1LL * s * x % mod;
    x = 1LL * x * x % mod, k >>= 1;
  }
  return s;
}
int tN;
int N, ivN;
int G[MAXN];
int p[MAXN];
inline void Prework(int n) {
  tN = 1;
  while (tN <= n) tN <<= 1;
  int delta = (G[0] = 1, G[1] = fsp(3, (mod - 1) / tN));
  for (int i = 1; i < tN; i++) G[i] = 1LL * G[i - 1] * delta % mod;
}
inline void init(int n) {
  N = 1;
  while (N <= n) N <<= 1;
  ivN = fsp(N);
  for (int i = 1; i < N; i++) p[i] = (p[i >> 1] >> 1) | (i & 1 ? N >> 1 : 0);
}
inline void NTT(int a[], int k) {
  for (int i = 1; i < N; i++)
    if (i < p[i]) swap(a[i], a[p[i]]);
  for (int l = 2; l <= N; l <<= 1) {
    int len = l >> 1, delta = tN / l;
    for (int i = 0; i < N; i += l) {
      int *g = G;
      for (int j = i; j < i + len; j++) {
        int tmp = 1LL * (*g) * a[j + len] % mod;
        a[j + len] = Mod(a[j] + mod - tmp);
        a[j] = Mod(a[j] + tmp);
        g += delta;
      }
    }
  }
  if (k == 1) return;
  reverse(a + 1, a + N);
  for (int i = 0; i < N; i++) a[i] = 1LL * a[i] * ivN % mod;
}
int S[MAXN];
int A[MAXN];
int B[MAXN];
int fac[MAXN];
int ifac[MAXN];
inline void Solve(int n) {
  if (n == 0) return S[0] = 1, void();
  if (n == 1) return S[1] = 1, void();
  int hf = n >> 1;
  Solve(hf);
  init(n);
  int pw = 1;
  for (int i = 0; i <= hf; i++) {
    A[i] = 1LL * fac[i] * S[i] % mod;
    B[hf - i] = 1LL * pw * ifac[i] % mod;
    pw = 1LL * pw * hf % mod;
  }
  NTT(A, 1), NTT(B, 1);
  for (int i = 0; i < N; i++) A[i] = 1LL * A[i] * B[i] % mod, B[i] = 0;
  NTT(A, 0);
  for (int i = 0; i <= hf; i++)
    A[i] = 1LL * A[i + hf] * ifac[i] % mod, A[i + hf] = 0;
  NTT(A, 1), NTT(S, 1);
  for (int i = 0; i < N; i++) S[i] = 1LL * S[i] * A[i] % mod, A[i] = 0;
  NTT(S, 0);
  if (n & 1)
    for (int i = n; i >= 1; i--) S[i] = (S[i - 1] + 1LL * (n - 1) * S[i]) % mod;
}
int main() {
  int n = read_int() - 1, A = read_int() - 1, B = read_int() - 1;
  Prework(n);
  if (A + B > n || A < 0 || B < 0) return puts("0"), 0;
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1LL * fac[i - 1] * i % mod;
  ifac[n] = fsp(fac[n]);
  for (int i = n; i >= 1; i--) ifac[i - 1] = 1LL * ifac[i] * i % mod;
  Solve(n);
  cout << 1LL * S[A + B] * fac[A + B] % mod * ifac[A] % mod * ifac[B] % mod
       << endl;
  return 0;
}
