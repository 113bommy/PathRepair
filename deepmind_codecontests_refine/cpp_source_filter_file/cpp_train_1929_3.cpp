#include <bits/stdc++.h>
int px, py;
double co, si;
void print(double x, double y) {
  printf("%.10f %.10f\n", x * si + y * co + px, x * co + y * si + py);
}
int main() {
  int vx, vy;
  scanf("%d %d %d %d", &px, &py, &vx, &vy);
  co = vx / hypot(vx, vy);
  si = vy / hypot(vx, vy);
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  print(0, b);
  print(-a * 0.5, 0);
  print(-c * 0.5, 0);
  print(-c * 0.5, -d);
  print(c * 0.5, -d);
  print(c * 0.5, 0);
  print(a * 0.5, 0);
  return 0;
}
