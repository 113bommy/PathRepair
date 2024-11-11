#include <bits/stdc++.h>
int main() {
  char arr[110];
  int i, j, jp, g, t, cl, jm, a, m, n;
  scanf("%d%d", &cl, &jm);
  scanf("%c", &arr[0]);
  for (i = 1; i <= cl; i++) scanf("%c", &arr[i]);
  for (i = 1; i <= cl; i++) {
    if (arr[i] == 'G') {
      g = i;
    }
    if (arr[i] == 'T') {
      t = i;
    }
  }
  if (g > t) {
    m = t;
    n = g;
    a = g - t;
  } else {
    m = g;
    n = t;
    a = t - g;
  }
  for (i = m; i < n; i = i + jm) {
    if (arr[i] == '#') {
      printf("NO\n");
      return 0;
    }
  }
  if ((a / jm) != 0)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
