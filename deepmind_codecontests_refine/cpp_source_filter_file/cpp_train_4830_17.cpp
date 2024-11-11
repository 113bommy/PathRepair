#include <bits/stdc++.h>
inline int read() {
  register int x = 0;
  register int y = 1;
  register char c = std::getchar();
  while (c < '0' || c > '9') {
    if (c == '-') y = 0;
    c = std::getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + (c ^ 48);
    c = std::getchar();
  }
  return y ? x : -x;
}
int main() {
  int n = read();
  if (n < 5) return puts("No solution"), 0;
  double pi = 3.14159265759;
  double change = pi - pi * (n - 2) / (double)n, ang = change;
  puts("0 0");
  double x = 0, y = 0, len = 100;
  for (register int i = 2; i < n; i++) {
    x += len * std::cos(ang);
    y += len * std::sin(ang);
    printf("%lf %lf\n", x, y);
    len += 0.01;
    ang += change;
  }
  len = -y / std::sin(ang);
  printf("%lf 0", x + len * std::cos(ang));
  return 0;
}
