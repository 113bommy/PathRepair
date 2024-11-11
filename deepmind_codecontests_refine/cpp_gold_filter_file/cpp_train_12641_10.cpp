#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
void rot(int &x, int &y, int &n, int &m) {
  int tx = x, ty = y;
  y = n - tx + 1;
  x = ty;
  swap(n, m);
}
int main() {
  int n, m;
  int a, b, c;
  scanf("%d%d", &n, &m);
  scanf("%d%d%d", &a, &b, &c);
  a &= 3;
  b &= 1;
  c &= 3;
  int d;
  scanf("%d", &d);
  for (int i = 0; i < d; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    int _n = n, _m = m;
    for (int k = 0; k < a; ++k) rot(x, y, _n, _m);
    for (int k = 0; k < b; ++k) y = _m - y + 1;
    for (int k = 0; k < c; ++k)
      for (int j = 0; j < 3; ++j) rot(x, y, _n, _m);
    printf("%d %d\n", x, y);
  }
  return 0;
}
