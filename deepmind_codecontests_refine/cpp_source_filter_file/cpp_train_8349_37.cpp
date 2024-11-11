#include <bits/stdc++.h>
int main() {
  int min, hr, i, t, ans;
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    scanf("%d %d", &hr, &min);
    ans = 1440 - ((hr * 60) + min);
    printf("%d", ans);
  }
  return 0;
}
