#include <bits/stdc++.h>
char a[2005];
int main(void) {
  int i, j, k;
  int n, m;
  int T;
  int max, len;
  scanf("%d", &n);
  scanf("%s", a);
  len = strlen(a);
  m = len / n;
  max = 0;
  for (i = 1; i <= m; i++) {
    if ((a[n * i - 1] == a[n * i - 2]) && (a[n * i - 1] == a[n * i - 3]))
      if (n * m != len) max++;
  }
  printf("%d\n", max);
  return 0;
}
