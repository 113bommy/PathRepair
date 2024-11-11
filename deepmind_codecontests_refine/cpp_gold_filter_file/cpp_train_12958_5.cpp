#include <bits/stdc++.h>
using namespace std;
int cond = 1;
inline int absx(int x) { return x < 0 ? -x : x; }
int odl(int a, int b, int c, int d) {
  a = absx(a - c);
  b = absx(b - d);
  return a + b - min(a, b);
}
int xx[9] = {-1, -1, 0, 0, 1, 1, 0, 0, -1};
int yy[9] = {0, 0, -1, -1, 0, 0, 1, 1, 0};
int main() {
  int n, p[9], q[9];
  scanf("%d %d %d", &n, &p[0], &q[0]);
  for (typeof(1) i = (1); i <= (7); ++i) p[i] = p[0], q[i] = q[0];
  for (int i = 0; i < (n - 1); i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x < p[0]) {
      p[0] = x;
      q[0] = y;
    }
    if (x + y < p[1] + q[1]) {
      p[1] = x;
      q[1] = y;
    }
    if (y < q[2]) {
      p[2] = x;
      q[2] = y;
    }
    if (x - y > p[3] - q[3]) {
      p[3] = x;
      q[3] = y;
    }
    if (x > p[4]) {
      p[4] = x;
      q[4] = y;
    }
    if (x + y > p[5] + q[5]) {
      p[5] = x;
      q[5] = y;
    }
    if (y > q[6]) {
      p[6] = x;
      q[6] = y;
    }
    if (x - y < p[7] - q[7]) {
      p[7] = x;
      q[7] = y;
    }
  }
  p[8] = p[0], q[8] = q[0];
  int ret = 0;
  for (int i = 0; i < (8); i++) {
    ret += odl(p[i] + xx[i], q[i] + yy[i], p[i + 1] + xx[i + 1],
               q[i + 1] + yy[i + 1]);
  }
  printf("%d\n", ret);
  return 0;
}
