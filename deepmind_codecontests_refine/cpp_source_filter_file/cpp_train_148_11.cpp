#include <bits/stdc++.h>
void radix_sort(int a[], int n) {
  int i, x[n + 1], m = 0, exp = 1;
  for (i = 1; i <= n; i++)
    if (a[i] > m) m = a[i];
  while (m / exp > 0) {
    int box[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (i = 0; i < n; i++) box[a[i] / exp % 10]++;
    for (i = 1; i < 10; i++) box[i] += box[i - 1];
    for (i = n - 1; i >= 0; i--) {
      x[--box[a[i] / exp % 10]] = a[i];
    }
    for (i = 0; i < n; i++) {
      a[i] = x[i];
    }
    exp *= 10;
  }
}
int h[200];
int aa[5];
int main() {
  int t, w, i, m, p, j, s = 0, d;
  int n = 5;
  for (i = 0; i < n; i++) {
    scanf("%d", &aa[i]);
    s = s + aa[i];
  }
  if (s % 5 == 0)
    printf("%d", s / 5);
  else
    printf("-1");
  return 0;
}
