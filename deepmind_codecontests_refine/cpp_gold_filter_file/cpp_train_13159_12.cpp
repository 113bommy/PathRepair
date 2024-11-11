#include <bits/stdc++.h>
using namespace std;
int main() {
  int C1, C2, C3, C4;
  int N, M;
  scanf("%d%d%d%d%d%d", &C1, &C2, &C3, &C4, &N, &M);
  int A[1000];
  int B[1000];
  int S2 = 0;
  for (int i = 0; i < N; ++i) {
    scanf("%d", &A[i]);
    S2 += A[i];
  }
  for (int i = 0; i < M; ++i) {
    scanf("%d", &B[i]);
    S2 += B[i];
  }
  int S = 0;
  int S1 = 0;
  for (int i = 0; i < N; ++i) {
    S1 += min(C1 * A[i], C2);
  }
  S += min(S1, C3);
  S1 = 0;
  for (int i = 0; i < M; ++i) {
    S1 += min(C1 * B[i], C2);
  }
  S += min(S1, C3);
  S = min(S, min(S2 * C1, C4));
  printf("%d", S);
  return 0;
}
