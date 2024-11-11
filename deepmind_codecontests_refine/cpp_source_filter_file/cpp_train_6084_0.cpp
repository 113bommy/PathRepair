#include <bits/stdc++.h>
bool sym[1030];
int F[20];
int main() {
  int N, i, j, k, m;
  while (scanf("%d", &N) == 1) {
    F[0] = 1;
    F[1] = 2;
    F[2] = 3;
    for (i = 4; i < N; i++) {
      memset(sym, 0, sizeof(sym));
      for (j = 0; j < i; j++) sym[F[j]] = 1;
      for (j = 0; j < i; j++)
        for (k = 0; k < i; k++)
          for (m = 0; m < i; m++) {
            if (j == k || k == m || m == j)
              continue;
            else if (0 < F[m] + F[k] - F[j])
              sym[F[m] + F[k] - F[j]] = 1;
          }
      for (j = 1; j <= 1000; j++)
        if (!sym[j]) break;
      F[i] = j;
    }
    for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
        if (j > 0) printf(" ");
        if (i == j)
          printf("0");
        else
          printf("%d", F[i] + F[j]);
      }
      printf("\n");
    }
  }
  return 0;
}
