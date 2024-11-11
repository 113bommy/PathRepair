#include <bits/stdc++.h>
int main() {
  int time = 90;
  int N;
  scanf("%d", &N);
  int A[N];
  int i;
  for (i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  int diff[N + 1];
  diff[0] = A[0] - 1;
  for (i = 1; i < N; i++) {
    diff[i] = A[i] - A[i - 1];
  }
  diff[N] = 90 - A[N - 1];
  for (i = 0; i < N + 1; i++) {
    if (diff[i] > 15) {
      if (i == 0)
        time = 15;
      else
        time = A[i - 1] + 15;
      break;
    }
  }
  printf("%d\n", time);
}
