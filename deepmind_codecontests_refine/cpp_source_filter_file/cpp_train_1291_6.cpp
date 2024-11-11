#include <bits/stdc++.h>
using namespace std;
int Max(int x, int y) { return x > y ? x : y; }
int main() {
  int ans;
  double h, r;
  scanf("%lf%lf", &r, &h);
  if (h < 2 * r)
    ans = 1;
  else
    ans = Max(2 + 2 * int((h - r / 2) / r),
              1 + 2 * int((h + r * (2 - sqrt(3.0)) / 2) / r));
  printf("%d\n", ans);
  return 0;
}
