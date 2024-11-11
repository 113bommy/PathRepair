#include <bits/stdc++.h>
int main() {
  int x, y, z, t1, t2, t3, k, s;
  scanf("%d %d %d %d %d %d", &x, &y, &z, &t1, &t2, &t3);
  k = (abs(y - x) * t1);
  s = (abs(z - x) * t2 + (3 * t3) + abs(y - x) * t2);
  if (s < k)
    printf("YES");
  else
    printf("NO");
  return 0;
}
