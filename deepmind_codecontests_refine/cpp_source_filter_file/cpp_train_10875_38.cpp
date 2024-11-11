#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 52;
int A[MAX_N][MAX_N], a, b, M, N;
int ones[MAX_N][MAX_N], sol = 0x3f3f3f3f;
int main() {
  scanf("%d%d", &N, &M);
  int i, j, tmp;
  for (i = 1; i <= N; ++i)
    for (j = 1; j <= M; ++j) {
      scanf("%d", &A[i][j]);
      ones[i][j] =
          ones[i][j - 1] + ones[i - 1][j] + ones[i - 1][j - 1] + A[i][j];
    }
  scanf("%d%d", &a, &b);
  for (i = 1; i <= N; ++i)
    for (j = 1; j <= M; ++j) {
      if (i - a >= 0 && j - b >= 0) {
        tmp =
            ones[i][j] - (ones[i - a][j] + ones[i][j - b] - ones[i - a][j - a]);
        if (tmp < sol) sol = tmp;
      }
      if (i - b >= 0 && j - a >= 0) {
        tmp =
            ones[i][j] - (ones[i - b][j] + ones[i][j - a] - ones[i - b][j - a]);
        if (tmp < sol) sol = tmp;
      }
    }
  printf("%d\n", sol);
  return 0;
}
