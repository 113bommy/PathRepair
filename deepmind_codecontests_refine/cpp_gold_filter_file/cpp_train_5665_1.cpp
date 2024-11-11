#include <bits/stdc++.h>
int main() {
  int n, i, a, b, k = 0, s1 = 0, s2 = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);
    if ((a % 2 == 0 && b % 2 == 1) || (a % 2 == 1 && b % 2 == 0)) {
      k = 1;
    }
    s1 = s1 + a;
    s2 = s2 + b;
  }
  if (s1 % 2 == 0 && s2 % 2 == 0) {
    printf("0\n");
  } else if (s1 % 2 == 1 && s2 % 2 == 1 && k == 1) {
    printf("1\n");
  } else {
    printf("-1\n");
  }
  return 0;
}
