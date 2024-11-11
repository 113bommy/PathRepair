#include <bits/stdc++.h>
int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  if (c == 0 && a == b) {
    printf("YES");
    return 0;
  } else if (c == 0 && a != b) {
    printf("NO");
    return 0;
  } else if (c > 0) {
    b = b - a;
    if (b <= 0) {
      printf("NO");
      return 0;
    } else {
      if (b % c == 0)
        printf("YES");
      else
        printf("NO");
      return 0;
    }
  } else {
    b = b - a;
    if (b >= 0) {
      printf("NO");
    } else {
      if (b % c == 0)
        printf("YES");
      else
        printf("NO");
    }
  }
}
