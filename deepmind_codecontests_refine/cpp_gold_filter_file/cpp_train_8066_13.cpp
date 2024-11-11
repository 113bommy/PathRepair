#include <bits/stdc++.h>
void swap(int *x, int *y);
int main() {
  int a[100], b[100], i, j, n, k, max_sum, s, l, r, bools_max_ind, max_ind;
  scanf("%d", &n);
  for (i = 0; i < 100; ++i) a[i] = b[i] = 0;
  max_ind = -1;
  bools_max_ind = 0;
  for (i = 0; i < n; ++i) {
    scanf("%d %d", a + i, b + i);
    if (*(a + i) == 0) {
      max_ind = i;
      bools_max_ind = 1;
    }
  }
  for (i = 0; i < n - 1; ++i)
    for (j = 0; j < n - 1; ++j)
      if (a[j] > a[j + 1]) {
        swap(a + j, a + j + 1);
        swap(b + j, b + j + 1);
      }
  max_sum = (bools_max_ind == 1) ? b[max_ind] : 0;
  k = 0;
  while (0 > a[k]) ++k;
  if (bools_max_ind == 1) {
    l = max_ind - 1;
    r = max_ind + 1;
  } else {
    r = k;
    l = --k;
  }
  s = (n - 1 - r > l) ? 1 : 0;
  while (1) {
    if (s == 1 && r >= n || s == 0 && l < 0) break;
    max_sum += (s == 1) ? b[r] : b[l];
    (s == 1) ? ++r : --l;
    s = 1 - s;
  }
  printf("%d", max_sum);
  return 0;
}
void swap(int *x, int *y) {
  int z;
  z = *x;
  *x = *y;
  *y = z;
}
