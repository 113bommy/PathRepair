#include <bits/stdc++.h>
using namespace std;
int N, K, P, X, Y;
int A[1000];
int cou;
int sum;
int ans[1000];
int main() {
  scanf("%d%d%d%d%d", &N, &K, &P, &X, &Y);
  for (int i = 0; i < K; i++) {
    scanf("%d", &A[i]);
    if (A[i] >= Y) cou++;
    sum += A[i];
  }
  cou = (N + 1) / 2 - cou;
  if (cou < 0) {
    printf("-1\n");
    return 0;
  }
  for (int i = 0; i < N - K; i++) {
    if (cou > 0) {
      ans[i] = Y;
      cou--;
      sum += ans[i];
    } else {
      ans[i] = 1;
      sum += ans[i];
    }
  }
  if (sum > X) {
    printf("-1\n");
    return 0;
  }
  for (int i = 0; i < N - K; i++) {
    printf("%d", ans[i]);
    if (i == N - K - 1)
      printf("\n");
    else
      printf(" ");
  }
  return 0;
}
