#include <bits/stdc++.h>
int main() {
  int n = 0, i = 0, j = 0, k = 0, A[2000], B[2000];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  for (i = 0; i < n; i++) {
    k = 1;
    for (j = 0; j < n; j++) {
      if ((A[j] > A[i]) && (i != j)) {
        k++;
      }
    }
    B[i] = k;
  }
  for (i = 0; i < n; i++) printf("%d ", B[i]);
  return 0;
}
