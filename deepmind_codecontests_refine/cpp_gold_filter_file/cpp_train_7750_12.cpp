#include <bits/stdc++.h>
int main() {
  int n, s, ar[100][100], a[100] = {0}, j = 0, count = 0;
  scanf("%d %d", &n, &s);
  int i, dif, max;
  for (i = 0; i < n; i++) {
    for (j = 0; j < 2; j++) {
      scanf("%d", &ar[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    if (ar[i][0] > s || (ar[i][0] == s && ar[i][1] > 0))
      count++;
    else if (ar[i][1] != 0) {
      dif = 100 - ar[i][1];
      a[j] = dif;
      j++;
    }
  }
  if (count == n)
    printf("-1");
  else {
    max = a[0];
    for (i = 1; i < j; i++) {
      if (a[i] > max) max = a[i];
    }
    printf("%d", max);
  }
  return 0;
}
