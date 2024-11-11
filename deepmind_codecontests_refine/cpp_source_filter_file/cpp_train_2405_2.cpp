#include <bits/stdc++.h>
using namespace std;
long long ax, ay, bx, by, cx, cy;
int solve(long long x2, long long y2) {
  if (cx == 0 && cy == 0) {
    if (x2 == 0 && y2 == 0) return 1;
    return 0;
  } else if (cx == 0) {
    long long g, h;
    g = x2 / cy;
    h = y2 / cy;
    if (g * cy == x2 && h * cy == y2) return 1;
    return 0;
  } else if (cy == 0) {
    long long g, h;
    g = x2 / cx;
    h = y2 / cx;
    if (g * cx == x2 && h * cx == y2) return 1;
    return 0;
  } else {
    long long a, b;
    if (cx * cy + cx * cx == 0) return 0;
    b = (x2 * cy - y2 * cx) / (cx * cy + cx * cx);
    a = (x2 - b * cy) / cx;
    if (b * (cx * cy + cx * cx) == (x2 * cy - y2 * cx) &&
        (a * cx == (x2 - b * cy))) {
      return 1;
    }
    return 0;
  }
  return 0;
}
int main() {
  scanf("%lld%lld", &ax, &ay);
  scanf("%lld%lld", &bx, &by);
  scanf("%lld%lld", &cx, &cy);
  if (solve(bx - ax, by - ay)) {
    puts("YES");
    return 0;
  }
  if (solve(bx + ax, by + ay)) {
    puts("YES");
    return 0;
  }
  if (solve(bx - ay, by + ax)) {
    puts("YES");
    return 0;
  }
  if (solve(bx + ay, by - ax)) {
    puts("YES");
    return 0;
  }
  puts("NO");
  return 0;
}
