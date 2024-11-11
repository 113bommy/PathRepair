#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M, i;
  scanf("%d %d", &N, &M);
  int A[N], L[M];
  for (i = 0; i < N; i++) scanf("%d", &A[i]);
  int S[N], count = 0;
  int rng[100007] = {0};
  for (i = (N - 1); i >= 0; i--) {
    if (rng[A[i]] == 0) {
      rng[A[i]] = 1;
      count++;
    }
    S[i] = count;
  }
  for (i = 0; i < M; i++) {
    scanf("%d", &L[i]);
    printf("%d\n", S[L[i] - 1]);
  }
  return 0;
}
