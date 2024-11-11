#include <bits/stdc++.h>
int main() {
  int t, x, y, c;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &x, &y);
    if ((x == 1 && x < y) || (x <= 3 && y > 3)) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
  }
  return 0;
}
