#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int x1, y1, x2, y2;
  scanf("%d %d %d %d %d ", &n, &x1, &y1, &x2, &y2);
  int res1, res2;
  if ((y2 == y1)) {
    res1 = (n - y1) + (n - y2);
    res2 = (y1) + (y2);
    printf("%d", abs(x1 - x2) + min(res1, res2));
    return 0;
  }
  if ((x1 == x2)) {
    res1 = (n - x1) + (n - x2);
    res2 = (x1) + (x2);
    printf("%d", abs(y1 - y2) + min(res1, res2));
    return 0;
  }
  if (((y1 == n) || (y1 == 0)) && ((y2 == n) || (y2 == 0))) {
    res1 = n + (n - x1) + (n - x2);
    res2 = n + (x1) + (x2);
    printf("%d", min(res1, res2));
    return 0;
  }
  if (((x1 == n) || (x1 == 0)) && ((x2 == n) || (x2 == 0))) {
    res1 = n + (n - y1) + (n - y2);
    res2 = n + (y1) + (y2);
    printf("%d", min(res1, res2));
    return 0;
  }
  printf("%d", abs(x1 - x2) + abs(y1 - y2));
  return 0;
}
