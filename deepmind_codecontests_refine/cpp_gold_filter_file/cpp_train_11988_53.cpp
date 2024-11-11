#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  if ((n == 2) || (n == 3) || (n == 4) || (n == 5) || (n == 12) || (n == 30) ||
      (n == 35) || (n == 43) || (n == 46) || (n == 52) || (n == 64) ||
      (n == 86)) {
    printf("YES");
  } else {
    printf("NO");
  }
}
