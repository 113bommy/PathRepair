#include <bits/stdc++.h>
int main(void) {
  int n, N, A, sum = 0;
  scanf("%d", &N);
  for (n = 0; n < N; n++) {
    scanf("%d", &A);
    sum += A * A;
  }
  printf("%d", sum);
  return 0;
}
