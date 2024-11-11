#include <bits/stdc++.h>
using namespace std;
int i, j, N, Num, Sum, S, Ans, len, len1, size, K, X, Y, M;
int Q[5005], P[5005], C[200005], A[200005], B[200005];
int cmp(const int &i, const int &j) { return A[i] < A[j]; }
int main() {
  scanf("%d", &N);
  for (i = 1; i <= N; ++i) {
    Num = Num % 200000 + 1, ++Sum;
    scanf("%d%d%d%d%d", &K, &A[Num], &X, &Y, &M);
    S = 0, P[i] = Num, B[Num] = i;
    for (j = 2; j <= K; ++j) {
      ++Sum;
      A[Num % 200000 + 1] =
          ((long long)A[Num] * (long long)X + (long long)Y) % (long long)M;
      B[Num % 200000 + 1] = i;
      if (A[Num % 200000 + 1] < A[Num]) ++S;
      Num = Num % 200000 + 1;
    }
    if (S > Ans) Ans = S;
  }
  printf("%d\n", Ans);
  if (Sum <= 200000) {
    for (i = 1; i <= N; ++i) Q[i] = i;
    len = N;
    for (; Num != 0;) {
      size = len1 = 0;
      for (i = 1; i <= len; ++i) {
        for (j = P[Q[i]]; B[j] == Q[i]; ++j) {
          C[++size] = j;
          if (A[j + 1] < A[j]) {
            ++j;
            break;
          }
        }
        P[Q[i]] = j;
        if (B[j] == Q[i]) Q[++len1] = Q[i];
      }
      sort(C + 1, C + size + 1, cmp), Num -= size, len = len1;
      for (i = 1; i <= size; ++i) printf("%d %d\n", A[C[i]], B[C[i]]);
    }
  }
  return 0;
}
