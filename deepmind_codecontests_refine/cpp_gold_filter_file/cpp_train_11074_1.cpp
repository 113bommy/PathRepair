#include <bits/stdc++.h>
int abs(int a) {
  if (a < 0) return -1 * a;
  return a;
}
int big(int a, int b) {
  if (a > b) return a;
  return b;
}
int small(int a, int b) {
  if (a < b) return a;
  return b;
}
int compare(const void *a, const void *b) {
  int *p1 = (int *)a;
  int *p2 = (int *)b;
  return *p1 - *p2;
}
int a[100100] = {};
void sieve() {
  int sum, min, i, j, k;
  a[0] = a[1] = 1;
  for (i = 2; i < 320; i++) {
    if (a[i] == 0) {
      for (j = i * i; j < 100100; j += i) a[j] = 1;
    }
  }
}
int b[500][500];
int r[500] = {}, c[500] = {};
int main() {
  sieve();
  int sum, min, n, m, i, j, k, x, y, t;
  scanf("%d", &n);
  scanf("%d", &m);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      scanf("%d", &x);
      k = x;
      while (a[k]) k++;
      b[i][j] = k - x;
    }
  for (i = 0; i < n; i++) {
    sum = 0;
    for (j = 0; j < m; j++) sum += b[i][j];
    r[i] = sum;
  }
  for (i = 0; i < m; i++) {
    sum = 0;
    for (j = 0; j < n; j++) sum += b[j][i];
    c[i] = sum;
  }
  min = 1000000000;
  for (i = 0; i < n; i++) {
    if (r[i] < min) min = r[i];
  }
  for (i = 0; i < m; i++) {
    if (c[i] < min) min = c[i];
  }
  printf("%d", min);
  return 0;
}
