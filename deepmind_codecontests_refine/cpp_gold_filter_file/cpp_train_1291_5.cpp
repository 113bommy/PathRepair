#include <bits/stdc++.h>
int main(void) {
  int r, h;
  int ans;
  scanf("%d %d", &r, &h);
  ans = h / r * 2;
  if (h % r >= sqrt(3) * r / 2) {
    ans += 3;
  } else if (h % r >= 1.0 * r / 2) {
    ans += 2;
  } else {
    ans += 1;
  }
  printf("%d\n", ans);
  return 0;
}
