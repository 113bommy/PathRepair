#include <bits/stdc++.h>
using namespace std;
char A[100100], B[100100];
int cnt[10], N, M;
int main(void) {
  scanf("%s\n%s\n", &A, &B);
  N = strlen(A);
  M = strlen(B);
  int i, j, k;
  for (i = 0; i < M; i++) cnt[B[i] - '0']++;
  for (i = 0; i < N; i++) {
    if (M == 0) break;
    int next = 0;
    for (j = 9; j >= 1; j--)
      if (cnt[j] > 0) {
        next = j;
        break;
      }
    if (next > (A[i] - '0')) {
      A[i] = next + '0';
      M--;
      cnt[next]--;
      continue;
    }
  }
  printf("%s\n", A);
  return 0;
}
