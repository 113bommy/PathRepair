#include <bits/stdc++.h>
int main() {
  int r, x1, y1, x2, y2;
  scanf("%d %d %d %d %d", &r, &x1, &y1, &x2, &y2);
  int dis = pow((x2 - x1), 2) + pow((y2 - y1), 2);
  double fin = pow(dis, 1.0 / 2);
  double ans = fin / (2.0 * r);
  int final = ceil(ans);
  printf("%d\n", final);
  return 0;
}
