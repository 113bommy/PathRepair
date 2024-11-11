#include <bits/stdc++.h>
int main() {
  int w1, h1, w2, h2;
  scanf("%d%d%d%d", &w1, &h1, &w2, &h2);
  int ans = 0;
  ans += 4;
  ans += w1;
  ans += 2 * h1;
  ans += 2 * h2;
  ans += w2;
  if (w1 > w2)
    ans += w1 - w2;
  else if (w2 > w1)
    ans += w2 - w1;
  printf("%d\n", ans);
  return 0;
}
