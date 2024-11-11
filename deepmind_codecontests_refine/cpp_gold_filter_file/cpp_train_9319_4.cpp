#include <bits/stdc++.h>
int main() {
  long int a[5000], b[5000], i, j, k, s1, s2, ans, n;
  ans = 0;
  scanf("%ld", &n);
  for (i = 0; i < n; i++) {
    scanf("%ld", &a[i]);
  }
  for (i = 0; i < n; i++) {
    scanf("%ld", &b[i]);
  }
  for (i = 0; i < n; i++)
    for (j = i; j < n; j++) {
      s1 = s2 = 0;
      for (k = i; k <= j; k++) {
        s1 = s1 | a[k];
        s2 = s2 | b[k];
      }
      if (ans < (s1 + s2)) ans = s1 + s2;
    }
  printf("%ld\n", ans);
  return 0;
}
