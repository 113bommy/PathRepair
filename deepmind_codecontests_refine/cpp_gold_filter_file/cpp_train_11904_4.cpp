#include <bits/stdc++.h>
int main(int argc, char *argv[]) {
  int s, a, b, c;
  scanf("%d%d%d%d", &s, &a, &b, &c);
  if (a == 0 && b == 0 && c == 0) {
    puts("0.0 0.0 0.0");
    return 0;
  }
  double x = a / double(a + b + c) * s;
  double y = b / double(a + b + c) * s;
  double z = c / double(a + b + c) * s;
  printf("%.20f %.20f %.20f\n", x, y, z);
  return 0;
}
