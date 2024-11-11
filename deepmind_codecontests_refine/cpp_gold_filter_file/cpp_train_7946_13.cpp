#include <bits/stdc++.h>
int a[10000], b[10000];
void sort(int l, int r) {
  int i, j, x, y;
  i = l;
  j = r;
  x = a[(l + r) / 2];
  y = b[(l + r) / 2];
  while (i < j) {
    while (b[i] > y || (b[i] == y && a[i] < x)) i++;
    while (y > b[j] || (b[j] == y && x < a[j])) j--;
    if (i <= j) {
      a[0] = a[i];
      a[i] = a[j];
      a[j] = a[0];
      b[0] = b[i];
      b[i] = b[j];
      b[j] = b[0];
      i++;
      j--;
    }
  }
  if (i < r) sort(i, r);
  if (l < j) sort(l, j);
}
int main() {
  int n, t1, t2, k, i, j, k1;
  int p1, p2;
  scanf("%d%d%d%d", &n, &t1, &t2, &k);
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &j, &k1);
    p1 = j * t1 * (100 - k) + k1 * t2 * 100;
    p2 = k1 * t1 * (100 - k) + j * t2 * 100;
    b[i] = (p1 > p2) ? p1 : p2;
    a[i] = i;
  }
  sort(1, n);
  for (i = 1; i <= n; i++) printf("%d %.2lf\n", a[i], b[i] / 100.0);
  return 0;
}
