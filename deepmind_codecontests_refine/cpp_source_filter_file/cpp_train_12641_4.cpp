#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::swap;
using std::vector;
void doit(int& xk, int& yk, int w, int h, int x, int y, int z) {
  for (int i = 0; i < x; ++i) {
    swap(xk, yk);
    swap(w, h);
    xk = w - xk + 1;
  }
  if (y) {
    xk = w - xk + 1;
  }
  for (int i = 0; i < x; ++i) {
    swap(xk, yk);
    swap(w, h);
    yk = h - yk + 1;
  }
}
int main() {
  int n, m, x, y, z, p;
  scanf("%d %d %d %d %d %d", &n, &m, &x, &y, &z, &p);
  x %= 4;
  y = y & 1;
  z %= 4;
  while (p--) {
    int xk, yk;
    scanf("\n%d %d", &xk, &yk);
    doit(xk, yk, m, n, x, y, z);
    printf("%d %d\n", xk, yk);
  }
  return 0;
}
