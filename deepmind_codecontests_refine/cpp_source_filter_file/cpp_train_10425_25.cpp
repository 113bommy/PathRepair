#include <bits/stdc++.h>
int main() {
  int m, x, y;
  scanf("%d %d %d", &m, &x, &y);
  if (((y > (m - 2) / 2) && (y < (m + 2) / 2) && (x > (m - 2) / 2) &&
       (x < (m + 2) / 2)) ||
      (m == 2)) {
    printf("NO");
  } else
    printf("YES");
  return 0;
}
