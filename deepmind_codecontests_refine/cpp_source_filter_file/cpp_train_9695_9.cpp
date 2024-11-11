#include <bits/stdc++.h>
int n;
int temp[110];
int A[110];
void mers(int *A, int s, int m, int e) {
  int i, p1 = s, p2 = m + 1;
  for (i = s; i <= e; i++) {
    if (p1 > m || (p2 <= e && A[p1] < A[p2]))
      temp[i] = A[p2++];
    else
      temp[i] = A[p1++];
  }
  for (i = s; i <= e; i++) {
    A[i] = temp[i];
  }
}
void msort(int *A, int s, int e) {
  if (s >= e) return;
  int m = (s + e) / 2;
  msort(A, s, m);
  msort(A, m + 1, e);
  mers(A, s, m, e);
}
int main() {
  scanf("%d", &n);
  int i;
  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  msort(A, 0, n - 1);
  int add = 0;
  for (i = 0; i < n; i++) {
    add += A[i * 2] - A[i * 2 + 1];
  }
  printf("%d\n", add);
}
