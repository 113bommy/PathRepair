#include <bits/stdc++.h>
int main() {
  int t, h, m, x = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &h, &m);
    if (h == 0) {
      x = 1440 - (h + m);
    } else {
      x = 1440 - (h * 60 + m);
    }
    printf("%d\n", x);
  }
  return 0;
}
