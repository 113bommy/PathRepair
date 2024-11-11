#include <bits/stdc++.h>
using namespace std;
long long int N, X, Y, C;
inline long long int sqr(long long int X) {
  if (X <= 0) return 0LL;
  return X * X;
}
inline long long int SumFirstX(long long int X) {
  if (X <= 0) return 0LL;
  return X * (X + 1LL) / 2LL;
}
int main(void) {
  scanf("%I64d %I64d %I64d %I64d", &N, &X, &Y, &C);
  long long int L = 0LL, R = 2LL * N, Sol = 2LL * N;
  while (L <= R) {
    long long int M = (L + R) >> 1;
    long long int Cnt = 2LL * M * M + 2LL * M + 1LL;
    Cnt -= sqr(M - X + 1);
    Cnt -= sqr(M - N + X);
    Cnt -= sqr(M - Y + 1);
    Cnt -= sqr(M - N + Y);
    Cnt += SumFirstX(M - X - Y + 1);
    Cnt += SumFirstX(M - N + X - Y);
    Cnt += SumFirstX(M - N + X - N + Y);
    Cnt += SumFirstX(M - X - N + Y);
    if (Cnt >= C) {
      Sol = M;
      R = M - 1;
    } else
      L = M + 1;
  }
  printf("%I64d\n", Sol);
  return 0;
}
