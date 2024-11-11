#include <bits/stdc++.h>
int main() {
  int a = 0, b = 0;
  scanf("%d %d", &a, &b);
  if (a == b || abs(a - b) <= 1) {
    if (a && b)
      printf("YES");
    else
      printf("NO");
  } else {
    printf("NO");
  }
  return 0;
}
