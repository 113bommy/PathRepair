#include <bits/stdc++.h>
using namespace std;
const long long N = 505, M = 1e9 + 7;
long long K, m, n, a[N], H[N], num[N], F[N], G[N], x, ans[N], C[N];
inline long long ksm(long long x, long long y) {
  long long ans = 1;
  for (; y; y >>= 1, x = x * x % M)
    if (y & 1) (ans *= x) %= M;
  return ans;
}
inline void cf1(long long A[]) {
  memset(C, 0, sizeof C);
  for (long long i = 0; i < 250; i++)
    for (long long j = 0; j < 250; j++) (C[i + j] += A[i] * A[j]) %= M;
  long long Inv = ksm(num[250], M - 2);
  for (long long i = 499; i >= 250; i--) {
    long long t = Inv * C[i] % M;
    for (long long j = 0; j <= 250; j++)
      (C[-250 + j + i] += M - t * num[j] % M) %= M;
  }
  for (long long i = 0; i < N; i++) A[i] = C[i];
}
inline void cf(long long A[], long long B[]) {
  memset(C, 0, sizeof C);
  for (long long i = 0; i < 250; i++)
    for (long long j = 0; j < 250; j++) (C[i + j] += A[i] * B[j]) %= M;
  long long Inv = ksm(num[250], M - 2);
  for (long long i = 499; i >= 250; i--) {
    long long t = Inv * C[i] % M;
    for (long long j = 0; j <= 250; j++)
      (C[-250 + j + i] += M - t * num[j] % M) %= M;
  }
  for (long long i = 0; i < N; i++) A[i] = C[i];
}
signed main() {
  scanf("%lld%lld%lld", &K, &m, &n);
  for (long long i = 1; i <= K; i++) scanf("%lld", &a[i]);
  while (m--) {
    scanf("%lld", &x);
    (num[250 - x] += M - 1) %= M;
  }
  num[250]++;
  ans[0] = 1;
  for (long long i = 1; i < 250; i++)
    for (long long j = 1; j <= i; j++)
      (ans[i] += M - ans[i - j] * num[250 - j] % M) %= M;
  for (long long i = 1; i <= K; i++) {
    memset(F, 0, sizeof F);
    memset(G, 0, sizeof G);
    F[1] = 1;
    long long y = a[i];
    G[0] = 1;
    for (; y; y >>= 1, cf1(F))
      if (y & 1) cf(G, F);
    for (long long j = 0; j < 250; j++) (H[j] += G[j]) %= M;
  }
  memset(G, 0, sizeof G);
  G[0] = 1;
  for (; n; n >>= 1, cf1(H))
    if (n & 1) cf(G, H);
  long long Ans = 0;
  for (long long i = 0; i < 250; i++) (Ans += G[i] * ans[i]) %= M;
  printf("%lld\n", Ans);
}
