#include <bits/stdc++.h>
using namespace std;
const int M = 1000005;
int A[M], B[M];
int main() {
  int n, m, p = -1, q = -1;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    printf("? 1 %d\n", i);
    fflush(stdout);
    scanf("%d", &A[i]);
    if (p == -1 || A[i] < A[p]) p = i;
  }
  for (int j = 2; j <= n; ++j) {
    printf("? %d %d\n", j, p);
    fflush(stdout);
    scanf("%d", &B[j]);
    if (q == -1 || B[j] < B[q]) q = j;
  }
  printf("! %d\n", B[q]);
  fflush(stdout);
  return 0;
}
