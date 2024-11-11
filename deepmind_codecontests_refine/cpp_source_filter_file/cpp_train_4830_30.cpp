#include <bits/stdc++.h>
using namespace std;
int n;
double x, y;
double pi;
int main() {
  scanf("%d", &n);
  pi = acos(-1);
  if (n <= 4) {
    puts("No solution");
    return 0;
  }
  printf("%.9lf %.9lf\n", x, y);
  for (int i = 1; i <= n - 2; i++) {
    double now = 2 * pi / n * i;
    double nowl = 100 + i;
    x += nowl * cos(now);
    y += nowl * sin(now);
    printf("%.9lf %.9lf\n", x, y);
  }
  double now = 2 * pi / n * (n - 1);
  x -= y / tan(now);
  y = 0;
  printf("%.9lf %.9lf\n", x, y);
  return 0;
}
