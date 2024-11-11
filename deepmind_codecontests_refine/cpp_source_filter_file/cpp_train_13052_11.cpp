#include <bits/stdc++.h>
using namespace std;
namespace INPUT {
const int L = 1 << 15;
char _buf[L], *S, *T, c;
char _gc() {
  if (S == T) {
    T = (S = _buf) + fread(_buf, 1, L, stdin);
    if (S == T) return EOF;
  }
  return *S++;
}
void readi(int &X) {
  for (c = _gc(); c < '0' || c > '9'; c = _gc())
    ;
  X = c & 15;
  for (c = _gc(); c >= '0' && c <= '9'; X = X * 10 + (c & 15), c = _gc())
    ;
}
}  // namespace INPUT
using INPUT::readi;
const int Maxn = 1005;
const int Mod = 1E9 + 7;
int N, K;
int fac[Maxn];
int C[Maxn][Maxn];
int f[Maxn][Maxn][4];
int F[Maxn];
void PrePare() {
  int N = 1000;
  fac[0] = 1;
  for (int i = 1; i <= N; ++i) fac[i] = (long long)fac[i - 1] * i % Mod;
  for (int i = 0; i <= N; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % Mod;
  }
}
int main() {
  readi(N), readi(K), PrePare();
  f[0][0][0] = 1;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j <= i; ++j)
      for (int k = 0; k < 4; ++k) {
        (f[i + 1][j][k >> 1] += f[i][j][k]) %= Mod;
        if (i > 0 && !(k & 1)) (f[i + 1][j + 1][k >> 1] += f[i][j][k]) %= Mod;
        if (i + 1 < N) (f[i + 1][j + 1][2 + (k >> 1)] += f[i][j][k]) %= Mod;
      }
  for (int j = 0; j <= N; ++j)
    for (int k = 0; k < 4; ++k)
      F[j] = (F[j] + (long long)f[N][j][k] * fac[N - j]) % Mod;
  for (int i = N; i >= 1; --i)
    for (int j = i + 1; j <= N; ++j)
      F[i] = (F[i] - (long long)F[j] * C[j][i] % Mod + Mod) % Mod;
  printf("%d", F[K]);
  return 0;
}
