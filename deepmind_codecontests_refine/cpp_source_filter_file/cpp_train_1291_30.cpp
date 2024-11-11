#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, h;
  scanf("%d %d", &r, &h);
  int res = ((2 * h + r) / 2 / r);
  res *= 2;
  int res2 = 1 + 2 * ((int)((h + r) - r * 0.5 * sqrt(3.0))) / r;
  printf("%d ", max(res, res2));
  return 0;
}
