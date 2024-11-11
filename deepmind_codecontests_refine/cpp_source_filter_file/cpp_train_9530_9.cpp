#include <bits/stdc++.h>
int main() {
  int b[200], n, c[200], i, j, d[200] = {0}, k = 0;
  char a[20];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s %d %d", a, &b[i], &c[i]);
    if (b[i] >= 2400) {
      if (c[i] > 2400) d[i] = 1;
    }
  }
  for (i = 0; i < n; i++) {
    if (d[i] == 1) {
      printf("YES");
      break;
    } else
      k++;
  }
  if (k == n) printf("NO");
  return 0;
}
