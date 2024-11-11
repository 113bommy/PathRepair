#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  if (n <= 4) {
    puts("No solution");
    return 0;
  }
  double now = 0, x = 0, y = 0, ep = 2 * acos(-1) / n, len = 100;
  now += ep;
  printf("%.5f %.5f\n", x, y);
  for (int i = 1; i < n - 1; i++) {
    x += len * cos(now);
    y += len * sin(now);
    printf("%.5f %.5f\n", x, y);
    len += 0.002;
    now += ep;
  }
  x -= y / tan(now);
  printf("%.5f %.5f\n", x, 0.00);
  return 0;
}
