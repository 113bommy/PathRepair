#include <bits/stdc++.h>
int main() {
  int n, m, a[105], b[105], sum;
  while (~scanf("%d", &n))
    ;
  {
    sum = 0;
    scanf("%d", &m);
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &a[i], &b[i]);
      if (m == a[i] || 7 - m == a[i]) {
        sum = 1;
      }
      if (m == b[i] || 7 - m == b[i]) {
        sum = 1;
      }
    }
    if (sum == 1) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
  }
  return 0;
}
