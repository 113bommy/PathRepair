#include <bits/stdc++.h>
int main(void) {
  int n, N, A, sum = 0;
  scanf("%d", &N);
  for (n = 1; n <= N; n++) {
    scanf("%d", &A);
    sum += n * A;
  }
  printf("%d", sum);
  return 0;
}
