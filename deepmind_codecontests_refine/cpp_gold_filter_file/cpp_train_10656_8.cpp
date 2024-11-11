#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int *A = new int[n], *B = new int[n];
  int min = 1000000001, max = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
    scanf("%d", &B[i]);
    if (A[i] < min) min = A[i];
    if (B[i] > max) max = B[i];
  }
  for (int i = 0; i < n; i++) {
    if (A[i] == min) {
      if (B[i] == max) {
        printf("%d", i + 1);
        exit(0);
      }
    }
  }
  printf("%d", -1);
  return 0;
}
