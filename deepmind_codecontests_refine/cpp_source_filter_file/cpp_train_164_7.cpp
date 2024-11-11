#include <bits/stdc++.h>
using namespace std;
long long pow(long long a) { return a * a; }
int main() {
  long long ax, ay, bx, by, cx, cy;
  scanf("%I64d%I64d%I64d%I64d%I64d%I64d", &ax, &ay, &bx, &by, &cx, &cy);
  bool hasAns = false;
  if (pow(ax - bx) + pow(ay - by) == pow(bx - cx) + pow(by - cy)) hasAns = true;
  long long x1 = ax - bx, y1 = ay - by;
  long long x2 = bx - cx, y2 = by - cy;
  if (x2 * y1 == x1 * y2) hasAns = true;
  if (hasAns)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
