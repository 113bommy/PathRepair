#include <bits/stdc++.h>
int main() {
  int r, c, r1, r2, c1, c2, ans[3];
  scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
  if (r1 > r2) {
    r = r1;
    r1 = r2;
    r2 = r;
  }
  if (c1 > c2) {
    c = c1;
    c1 = c2;
    c2 = c;
  }
  if (r1 == r2 && c1 == c2)
    ans[0] = ans[1] = ans[2] = 0;
  else {
    if (r1 == r2 || c1 == c2)
      ans[0] = 1;
    else
      ans[0] = 2;
    if ((r2 - r1 + c2 - c1) % 2 == 0) {
      if (r2 - r1 == c2 - c1)
        ans[1] = 1;
      else
        ans[1] = 2;
    } else
      ans[1] = 0;
    if ((r2 - r1) > (c2 - c1))
      ans[2] += (r2 - r1);
    else
      ans[2] += (c2 - c1);
  }
  printf("%d %d %d\n", ans[0], ans[1], ans[2]);
}
