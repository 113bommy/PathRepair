#include <bits/stdc++.h>
using namespace std;
void ga(int N, int *A) {
  for (int i(0); i < N; i++) scanf("%d", A + i);
}
int L[(1 << 17)], H[(1 << 17)], C[(1 << 17)][8], f[(1 << 17)][8], X;
void gen(void) {
  for (int i(0); i < (1 << 17); i++) H[i] = i;
  for (int i(2); i < (1 << 17); ++i)
    if (H[i] > 1)
      for (int j(i), c(0); j < (1 << 17); j += i, c = 0) {
        while (!(H[j] % i)) H[j] /= i, ++c;
        if (c) C[j][L[j]] = c, f[j][L[j]++] = i;
      }
}
long long pw(long long n, long long k) {
  long long r(1);
  while (k) {
    if (k & 1) r *= n;
    n *= n, k >>= 1;
  }
  return r;
}
struct fn {
  int F[(1 << 17)];
  void clr() {
    (memset(F, 0, sizeof(F)));
    if (!X++) gen();
  }
  void ad(int a) {
    for (int i(0); i < L[a]; i++) F[f[a][i]] += C[a][i];
  }
  void sb(int a) {
    for (int i(0); i < L[a]; i++) F[f[a][i]] -= C[a][i];
  }
  long double ev() {
    long double S = 1;
    for (int i(0); i < (1 << 17); i++)
      if (F[i] > 0)
        S *= pow(i, F[i]);
      else if (F[i] < 0)
        S /= pow(i, -F[i]);
    return S;
  }
} F;
void fc(int N) {
  for (int k(2); k < N + 1; k++) F.ad(k);
}
void iv(int N) {
  for (int k(2); k < N + 1; k++) F.sb(k);
}
int K, N, I, A[(1 << 17)], S;
int main(void) {
  scanf("%d%d%d", &K, &N, &I), --I, ga(N, A), --K, assert(~--A[I]),
      S = accumulate(A, A + N, 0), F.clr();
  if (S < K) return puts("-1");
  if (S - A[I] < K) return puts("1");
  fc(S - A[I]), iv(K), iv(S - A[I] - K);
  iv(S), fc(K), fc(S - K);
  printf("%.30lf\n", double(1 - F.ev()));
  return 0;
}
