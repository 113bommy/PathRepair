#include <bits/stdc++.h>
int main(void) {
  int N;
  int* A;
  long long* B;
  int i;
  scanf("%d", &N);
  A = (int*)malloc(sizeof(int) * N);
  B = (long long*)malloc(sizeof(long long) * N);
  for (i = 0; i < N; i++) scanf("%d", &A[i]);
  B[N - 1] = A[N - 1];
  for (i = N - 1; 0 <= i; i--) B[i] = A[i] + A[i + 1];
  for (i = 0; i < N; i++) printf("%I64d ", B[i]);
  free(A);
  free(B);
  return 0;
}
