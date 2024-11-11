#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:67108864")
using namespace std;
long long i, N, A[100005], F[100] = {0};
long long f(long long X) {
  if (X == 0) return 0;
  return X & 1 ? f(X >> 1) + 1 : f(X >> 1);
}
int main() {
  scanf("%I64d", &N);
  for (i = 0; i < N; ++i) {
    scanf("%I64d", &A[i]);
    ++F[f(A[i])];
  }
  long long res = 0;
  for (i = 0; i < N; ++i) {
    res += F[f(A[i])] - 1;
    F[f(A[i])]--;
  }
  printf("%I64d\n", res);
  return 0;
}
