#include <bits/stdc++.h>
using namespace std;
void ga(int N, int *A) {
  for (int i(0); i < N; i++) scanf("%d", A + i);
}
int N, M, A[(1 << 18)], D, K, Z, b, e, I, J, B[(1 << 18)], L;
long long pw(long long n, long long k) {
  long long r(1);
  while (k) {
    if (k & 1) r *= n, r %= M;
    n *= n, n %= M;
    k >>= 1;
  }
  return r;
}
long long inv(long long a) { return pw(a, M - 2); }
set<int> S;
void go(int d, int *A, int N) {
  for (int i(0); i < N; i++) S.insert(A[i]);
  b = e = *A, S.erase(*A);
  while (S.count((b - d + M) % M)) b = (b - d + M) % M, S.erase(b);
  while (S.count((e + d) % M)) e = (e + d) % M, S.erase(e);
}
int main(void) {
  scanf("%d%d", &M, &N), ga(N, A), Z = abs(A[1] - *A);
  if (N == 1) return printf("%d 0\n", *A), 0;
  if (N == M) return printf("1 1\n"), 0;
  for (int i(0); i < N; i++) S.insert(A[i]);
  for (int i(0); i < N; i++) K += S.count((A[i] + Z) % M);
  K = N - K, D = Z * inv(K) % M, go(D, A, N);
  if (S.empty()) return printf("%d %d\n", b, D), 0;
  if (M > 2e5) return puts("-1"), 0;
  for (int i(0); i < N; i++) S.insert(A[i]);
  for (int i(0); i < M; i++)
    if (!S.count(i)) B[L++] = i;
  Z = abs(B[1] - *B), S.clear(), K = 0;
  for (int i(0); i < L; i++) S.insert(B[i]);
  for (int i(0); i < L; i++) K += S.count((B[i] + Z) % M);
  K = L - K, D = Z * inv(K) % M, go(D, B, L);
  if (!S.empty()) return puts("-1"), 0;
  printf("%d %d\n", (b + D * (M - N)) % M, D);
  return 0;
}
