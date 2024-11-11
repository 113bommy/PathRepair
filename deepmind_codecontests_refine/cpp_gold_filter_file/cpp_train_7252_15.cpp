#include <bits/stdc++.h>
using namespace std;
struct node {
  double x, y;
  bool operator<(const node &a) const { return x == a.x ? y < a.y : x < a.x; }
} a[5], b[5];
int main() {
  for (register int i = 1; i <= 4; ++i) {
    scanf("%lf%lf", &a[i].x, &a[i].y);
  }
  sort(a + 1, a + 5);
  swap(a[3], a[4]);
  for (register int i = 1; i <= 4; ++i) {
    scanf("%lf%lf", &b[i].x, &b[i].y);
  }
  sort(b + 1, b + 5);
  swap(b[3], b[4]);
  double x = (b[1].x + b[3].x) * 0.5, y = (b[2].y + b[4].y) * 0.5;
  if (x <= a[4].x && x >= a[1].x && y <= a[2].y && y >= a[1].y) {
    return puts("Yes"), 0;
  }
  if (x <= a[4].x && x >= a[1].x) {
    double L = min(fabs(y - a[2].y), fabs(y - a[1].y));
    if (L <= b[4].y - y) return puts("Yes"), 0;
    return puts("No"), 0;
  }
  if (y <= a[2].y && y >= a[1].y) {
    double L = min(fabs(x - a[1].x), fabs(x - a[3].x));
    if (L <= b[3].x - x) return puts("Yes"), 0;
    return puts("No"), 0;
  }
  double L = b[4].y - y;
  double nx = min(fabs(x - a[1].x), fabs(x - a[3].x)) + a[4].x;
  double ny = a[4].y - min(fabs(y - a[2].y), fabs(y - a[1].y));
  if (ny + L - nx + a[4].x >= a[4].y)
    puts("Yes");
  else
    puts("No");
  return 0;
}
