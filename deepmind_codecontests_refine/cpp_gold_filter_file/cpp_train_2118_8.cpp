#include <bits/stdc++.h>
using namespace std;
bool debug = false;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int gc(int x, int y) {
  int z = y;
  while (x % y != 0) {
    z = x % y;
    x = y;
    y = z;
  }
  return z;
}
int main() {
  int d, b, g, c = 0, dd;
  scanf("%d%d", &b, &d);
  dd = d;
  while ((g = gc(b, dd)) > 1) {
    dd /= g;
    c++;
  }
  if (dd == 1) {
    printf("2-type\n%d\n", c);
  } else if ((b - 1) % d == 0) {
    puts("3-type");
  } else if ((b + 1) % d == 0) {
    puts("11-type");
  } else if ((b + 1) * (b - 1) / ((b & 1) + 1) % dd == 0) {
    puts("6-type");
  } else {
    puts("7-type");
  }
  return 0;
}
