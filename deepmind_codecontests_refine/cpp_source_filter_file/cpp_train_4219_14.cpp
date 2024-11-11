#include <bits/stdc++.h>
int main() {
  int m, n, a[100];
  scanf("%d", &n);
  scanf("%d", &m);
  int i, j;
  for (j = 0; j < n; j++) {
    scanf("%d", &a[j]);
  }
  for (i = 0; i < n; i++) {
    int tmp = a[i];
    int pos = i;
    while (tmp < a[pos - 1] && pos > 0) {
      a[pos] = a[pos - 1];
      pos--;
    }
    a[pos] = tmp;
  }
  i = 0;
  while (m > 0 && i < n) {
    m -= a[i];
    i++;
  }
  printf("%d\n", i);
}
