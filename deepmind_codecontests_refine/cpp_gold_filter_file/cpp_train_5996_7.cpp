#include <bits/stdc++.h>
void cutout(int a[], int i, int total);
int main() {
  int n, k, i, temp, i1;
  scanf("%d%d", &n, &k);
  int a[n], b[k], c[k];
  for (i = 0; i < k; i++) {
    scanf("%d", &b[i]);
  }
  for (i = 0; i < n; i++) {
    a[i] = i + 1;
  }
  temp = 0;
  i = 0;
  while (i < k) {
    temp = b[i] - n * (b[i] / n) + temp;
    if (temp >= n) temp = temp - n;
    c[i] = a[temp];
    cutout(a, temp, n);
    n--;
    i++;
  }
  for (i = 0; i < k; i++) printf("%d ", c[i]);
  return 0;
}
void cutout(int a[], int i, int total) {
  int i1;
  for (i1 = i; i1 < total; i1++) a[i1] = a[i1 + 1];
}
