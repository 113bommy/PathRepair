#include <bits/stdc++.h>
using namespace std;
int D[5007][5007];
int A[5007];
bool marked[5007];
int N, total, i, j, current, f, MIN = INT_MAX;
int main() {
  scanf("%d", &N);
  for (i = 1; i <= N; ++i) scanf("%d", &A[i]), ++A[i];
  for (i = 1; i <= N; ++i)
    for (j = 1; j <= i; ++j)
      if (A[j] > A[i]) ++total;
  for (i = 1; i <= N; ++i) {
    marked[A[i]] = true;
    for (j = 1; j <= N; ++j) D[i][j] = D[i][j - 1] + marked[j - 1];
  }
  for (i = 1; i <= N; ++i)
    for (j = 1; j <= N; ++j) {
      current =
          total + 2 * (D[i][A[i]] + D[j][A[j]] - D[i][A[j]] - D[j][A[i]]) + 1;
      if (current < MIN) {
        MIN = current;
        f = 0;
      }
      if (current == MIN) ++f;
    }
  printf("%d %d\n", MIN, f / 2);
  return 0;
}
