#include <bits/stdc++.h>
int main() {
  int n, i, a[100], j = 0, k, m;
  char s[100], tg;
  scanf("%d", &n);
  getchar();
  gets(s);
  for (i = 1; i <= n; i++) {
    if (n % i == 0) {
      a[j] = i;
      j++;
    }
  }
  for (k = 0; k < j; k++) {
    for (m = 0; m <= floor(a[k] / 2 - 1); m++) {
      tg = s[m];
      s[m] = s[a[k] - m - 1];
      s[a[k] - m - 1] = tg;
    }
  }
  printf("%s", s);
  return 0;
}
