#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
template <class T>
inline T lcm(T a, T b) {
  a = abs(a);
  b = abs(b);
  return (a / gcd(a, b)) * b;
}
template <class T, class X>
inline bool getbit(T a, X i) {
  T t = 1;
  return ((a & (t << i)) > 0);
}
template <class T, class X>
inline T setbit(T a, X i) {
  T t = 1;
  return (a | (t << i));
}
template <class T, class X>
inline T resetbit(T a, X i) {
  T t = 1;
  return (a & (~(t << i)));
}
inline long long power(long long a, long long b) {
  long long multiply = 1;
  for (int i = (0); i < (b); i++) {
    multiply *= a;
  }
  return multiply;
}
long long dp[32][32][52];
int n, m, k;
long long calc(int N, int M, int K) {
  if (dp[N][M][K] != -1) return dp[N][M][K];
  if (K == 0 || N * M == K) return 0;
  if (N * M < K) return 1e7;
  long long ret = 2000000000;
  for (int i = 1; i < N; i++) {
    for (int j = 1; j <= K; j++) {
      ret = min(ret, M * M + calc(i, M, j) + calc(N - i, M, K - j));
    }
  }
  for (int i = 1; i < M; i++) {
    for (int j = 1; j <= K; j++) {
      ret = min(ret, N * N + calc(N, i, j) + calc(N, M - j, K - j));
    }
  }
  return dp[N][M][K] = ret;
}
int main() {
  int test;
  scanf("%d", &test);
  memset(dp, -1, sizeof(dp));
  while (test--) {
    scanf("%d%d%d", &n, &m, &k);
    printf("%lld\n", calc(n, m, k));
  }
  return 0;
}
