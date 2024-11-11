#include <bits/stdc++.h>
int p[4], a, b, min, ans;
int main() {
  scanf("%d%d%d%d%d%d", &p[0], &p[1], &p[2], &p[3], &a, &b);
  min = 1000000;
  for (int i = 0; i < 4; i++)
    if (p[i] > min) min = p[i];
  if (b + 1 < min) min = b + 1;
  ans = b - min;
  if (ans < 0) ans = 0;
  printf("%d", ans);
  return 0;
}
