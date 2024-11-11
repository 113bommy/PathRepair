#include <bits/stdc++.h>
int main() {
  int n, d;
  int m;
  scanf("%d%d", &n, &d);
  int a[n];
  int i, j;
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  scanf("%d", &m);
  int summ;
  summ = 0;
  if (m > n) {
    summ -= (m - n) * d;
  };
  for (i = 0; i < n; i++) {
    for (j = n - 2; j >= i; j--) {
      if (a[j] > a[j + 1]) {
        int temp;
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      };
    };
  };
  if (m >= n) {
    for (i = 0; i < n; i++) summ += a[i];
  } else {
    for (i = 0; i < m; i++) summ += a[i];
  };
  printf("%d", summ);
  return 0;
};
