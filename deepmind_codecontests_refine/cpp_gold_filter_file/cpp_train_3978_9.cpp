#include <bits/stdc++.h>
void result(int a[], int b[], int c[], int m, int n) {
  for (int i = 0; i < m; i++) printf("%d ", a[b[i]]);
  printf("\n");
  for (int i = 0; i < n; i++) printf("%d ", a[c[i]]);
  exit(0);
}
void branch(int a[], int n, int i, int b[], int bn, int bq) {
  int cn = 0, cq, c[n];
  c[0] = i;
  if (++cn + bn == n) result(a, b, c, bn, cn);
  int j = i + 1;
  while (j == b[j - 1] && j <= bn) j++;
  c[1] = j;
  cn++;
  cq = a[j] - a[i];
  i = j++;
  while (j < n) {
    while (a[j] - a[i] != cq && j < n - 1) j++;
    if (a[j] - a[i] == cq) c[cn++] = j;
    i = j++;
  }
  if (bn + cn > n) {
    if (b[bn - 1] > c[cn - 1])
      cn--;
    else
      bn--;
    result(a, b, c, bn, cn);
  } else if (bn + cn == n)
    result(a, b, c, bn, cn);
}
int test(int a[], int n, int i, int j) {
  int bn = 2, bq = a[j] - a[i], b[n];
  b[0] = i;
  b[1] = j;
  i = j++;
  while (j < n) {
    while (a[j] - a[i] != bq && j < n - 1) j++;
    if (a[j] - a[i] == bq) b[bn++] = j;
    i = j++;
  }
  i = 0;
  while (i == b[i] && i < bn) i++;
  if (i == n) {
    result(a, b, &b[bn - 1], bn - 1, 1);
  } else {
    branch(a, n, i, b, bn, bq);
    branch(a, n, i, b, bn - 1, bq);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  if (n == 2) {
    printf("%d\n%d", a[0], a[1]);
  } else {
    test(a, n, 0, 1);
    test(a, n, 0, 2);
    test(a, n, 1, 2);
    printf("No solution");
  }
  return 0;
}
