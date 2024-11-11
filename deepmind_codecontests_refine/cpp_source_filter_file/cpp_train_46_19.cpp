#include <bits/stdc++.h>
using namespace std;
long long A[100010], AA[100010], AAA[100010];
int main() {
  long long N;
  scanf("%I64d", &N);
  for (int I = 0; I < N; I++) {
    scanf("%I64d", &A[I]);
  }
  for (int I = 0; I < N - 1; I++) {
    scanf("%I64d", &AA[I]);
  }
  for (int I = 0; I < N - 2; I++) {
    scanf("%I64d", &AAA[I]);
  }
  sort(A, A + N);
  sort(AA, AA + N - 1);
  sort(AAA, AAA + N - 2);
  bool B = 0;
  for (int I = 0; I < N - 1; I++) {
    if (A[I] != AA[I]) {
      printf("%I64d\n", A[I]);
      B = 1;
      break;
    }
  }
  if (!B) printf("%I64\n", A[N - 1]);
  B = 0;
  for (int I = 0; I < N - 2; I++) {
    if (AA[I] != AAA[I]) {
      printf("%I64\n", AA[I]);
      B = 1;
      break;
    }
  }
  if (!B) printf("%I64\n", AA[N - 2]);
  return 0;
}
