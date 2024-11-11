#include <bits/stdc++.h>
using namespace std;
inline int Read() {
  int x = 0, f = 1, c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
int main() {
  int n = Read();
  double x = 0, y = 0, a = 2 * acos(-1) / n, l = 500;
  if (n <= 3) return puts("No solution"), 0;
  for (int i = 1; i <= n - 2; i++)
    printf("%lf %lf\n", x, y), l += 0.01, x += l * cos(a * i),
        y += l * sin(a * i);
  printf("%lf %lf\n", x, y);
  return printf("%lf %lf\n", x - y / tan(a * (n - 1)), 0.0), 0;
}
