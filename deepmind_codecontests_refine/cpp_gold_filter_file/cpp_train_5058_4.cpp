#include <bits/stdc++.h>
using namespace std;
int N, M;
int A[200005], B[200005], C[200005], D[200005];
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &C[i], &A[i]);
  }
  scanf("%d", &M);
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &B[i], &D[i]);
  }
  sort(A, A + N);
  sort(B, B + M);
  sort(C, C + N);
  sort(D, D + M);
  printf("%d", max(max(0, C[N - 1] - D[0]), max(0, B[M - 1] - A[0])));
  return 0;
}
