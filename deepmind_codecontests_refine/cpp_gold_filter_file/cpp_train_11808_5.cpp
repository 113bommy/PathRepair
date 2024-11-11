#include <bits/stdc++.h>
using namespace std;
int N, M, ans;
int A[3333], F[3333][3333];
bool B[3333], C[3333];
int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
  }
  for (int i = N; i > 0; i--) {
    B[i] = B[i + 1];
    B[i] |= A[i] == 100;
  }
  for (int i = N; i > 0; i--) {
    C[i] = C[i + 1];
    C[i] |= A[i] > 0;
  }
  for (int i = 1; i <= N + 2; i++)
    for (int j = 1; j <= N + 2; j++) {
      F[i][j] = 3333;
    }
  F[1][2] = 0;
  for (int i = 1; i <= N; i++)
    for (int j = i + 1; j <= N; j++) {
      if (A[i] > 0 && !B[j]) {
        F[i][j + 1] = min(F[i][j + 1], F[i][j] + 1);
      }
      if (C[j] && A[i] < 100) {
        F[j][j + 1] = min(F[j][j + 1], F[i][j] + 1);
      }
      if (A[i] > 0 && C[j]) {
        F[j + 1][j + 2] = min(F[j + 1][j + 2], F[i][j] + 1);
      }
    }
  for (int i = 1; i <= N + 1; i++)
    for (int j = i + 1; j <= N + 2; j++) {
      ans += F[i][j] <= M;
    }
  printf("%d\n", ans);
  return 0;
}
