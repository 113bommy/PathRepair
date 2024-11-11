#include <bits/stdc++.h>
using namespace std;
int F[611][311][311];
int N, K;
int A[311][311];
int main(int argc, char *argv[]) {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      scanf("%d", &A[i][j]);
    }
  int K = (N - 1) << 1;
  F[0][0][0] = A[0][0];
  for (int k = 1; k <= K; k++)
    for (int i = 0; i < N; i++)
      if (k - i < N && k - i >= 0) {
        for (int j = 0; j < N; j++)
          if (k - j < N && k - j >= 0) {
            int x1 = k - i;
            int x2 = k - j;
            int t = A[x1][i] + A[x2][j];
            if (x1 == x2 && i == j) {
              t >>= 1;
            }
            F[k][i][j] = -1000 * K * K;
            if (i > 0 && j > 0) {
              F[k][i][j] = max(F[k][i][j], F[k - 1][i - 1][j - 1]);
            }
            if (i > 0 && x2 > 0) {
              F[k][i][j] = max(F[k][i][j], F[k - 1][i - 1][j]);
            }
            if (x1 > 0 && j > 0) {
              F[k][i][j] = max(F[k][i][j], F[k - 1][i][j - 1]);
            }
            if (x1 > 0 && x2 > 0) {
              F[k][i][j] = max(F[k][i][j], F[k - 1][i][j]);
            }
            F[k][i][j] += t;
          }
      }
  printf("%d\n", F[K][N - 1][N - 1]);
  return 0;
}
