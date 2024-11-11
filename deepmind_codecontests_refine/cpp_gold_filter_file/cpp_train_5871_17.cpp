#include <bits/stdc++.h>
int a[100200], b[100200];
int bs(int);
void burbuja(int n);
int main() {
  int n, all, i, neg, j, sum, min;
  scanf("%d", &n);
  n = bs(n);
  all = 2 * n - 1;
  if (n % 2) n = all;
  scanf("%d", &a[0]);
  min = bs(a[0]);
  neg = 0;
  for (i = 1; i < all; i++) {
    scanf("%d", &a[i]);
    if (bs(a[i]) < min) min = bs(a[i]);
  }
  burbuja(all);
  for (i = j = 0; i < all; i++) {
    if (a[i] < 0) a[i] = -a[i], neg++;
  }
  for (sum = i = 0; i < all; i++) {
    sum += a[i];
  }
  printf("%d\n", (n % 2 == 0 && neg && neg % 2) ? sum - (2 * min) : sum);
}
void burbuja(int all) {
  int i, j, aux;
  for (i = 0; i < all - 1; i++) {
    for (j = 0; j < all - 1 - i; j++) {
      if ((a[j]) > (a[j + 1])) {
        aux = a[j];
        a[j] = a[j + 1];
        a[j + 1] = aux;
      }
    }
  }
}
int bs(int a) { return (a < 0) ? -a : a; }
