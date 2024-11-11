#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  if (n < 5) return puts("No solution"), 0;
  double x = 0, y = 0, L = 100, step = M_PI * 2 / n, cur = 0;
  for (int i = 1; i <= n - 1; i++) {
    printf("%.lf %.lf\n", x, y);
    cur += step;
    x += L * cos(cur);
    y += L * sin(cur);
    L += 0.02;
  }
  printf("%lf %lf\n", x - y * tan(cur), 0.0);
  return 0;
}
