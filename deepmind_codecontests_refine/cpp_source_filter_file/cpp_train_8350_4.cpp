#include <bits/stdc++.h>
int main() {
  int i, t, h, m, result;
  scanf("%d", &t);
  for (i = 1; i <= t; i++) {
    scanf("%d%d", &h, &m);
    if ((h >= 0 && h < 24) && (m >= 0 && m < 60)) {
      result = 1440 - ((h * 60) + m);
    }
    printf("%d", result);
  }
  return 0;
}
