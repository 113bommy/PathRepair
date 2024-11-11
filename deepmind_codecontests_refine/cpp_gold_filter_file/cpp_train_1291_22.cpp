#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
int h, r;
int can(long double x, long double y) {
  long double d = sqrt(abs(x * x + y * y));
  if (y < 0 || d < r / 2.0 + 1e-10) return 1;
  return 0;
}
int main() {
  scanf("%d%d", &r, &h);
  int k = h / r;
  if (can(r / 2.0, (k + 0.5) * r - h)) {
    if (can(0, (k + 1 + sqrt(abs(3.0 / 4)) - 0.5) * r - h))
      printf("%d\n", 2 * k + 3);
    else
      printf("%d\n", 2 * k + 2);
  } else if (k == 0)
    printf("1\n");
  else if (can(0, (k + sqrt(abs(3.0 / 4)) - 0.5) * r - h))
    printf("%d\n", 2 * k + 1);
  else
    printf("%d\n", 2 * k);
  return 0;
}
