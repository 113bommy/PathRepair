#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1 << 19 | 7;
const int Inf = 1e9;
int n, K, Top, A[MAXN];
int F[MAXN], Minv[MAXN], Maxv[MAXN];
int Read() {
  int a = 0, c = 1;
  char b = getchar();
  while (b != '-' && (b < '0' || b > '9')) b = getchar();
  if (b == '-') c = -1, b = getchar();
  while (b >= '0' && b <= '9') a = a * 10 + b - 48, b = getchar();
  return a * c;
}
int Min(int A, int B) { return A < B ? A : B; }
int Max(int A, int B) { return A > B ? A : B; }
int main() {
  n = Read(), K = Read(), Top = (1 << K) - 1;
  for (int i = 0; i <= Top; i++) F[i] = Minv[i] = Inf, Maxv[i] = -Inf;
  for (int i = 1; i <= n; i++) A[i] = Read(), Minv[A[i]] = Maxv[A[i]] = 0;
  for (int Nb = 0, Bit = 1; Nb < K; Nb++, Bit <<= 1)
    for (int Ri = 0, Le; Ri <= Top; Ri++) {
      if (~Ri & Bit) continue;
      Le = Ri ^ Bit, F[Le] = F[Ri] = Min(F[Le], F[Ri]);
      int Minr = Minv[Ri], Maxr = Maxv[Ri], Minl = Minv[Le], Maxl = Maxv[Le];
      F[Le] = Min(F[Le], Minr + Bit - Maxl),
      F[Ri] = Min(F[Ri], Minl + Bit - Maxr);
      Minv[Le] = Min(Minl, Minr + Bit), Maxv[Le] = Max(Maxl, Maxr + Bit);
      Minv[Ri] = Min(Minr, Minl + Bit), Maxv[Ri] = Max(Maxr, Maxl + Bit);
    }
  for (int i = 0; i <= Top; i++) printf("%d ", F[i]);
}
