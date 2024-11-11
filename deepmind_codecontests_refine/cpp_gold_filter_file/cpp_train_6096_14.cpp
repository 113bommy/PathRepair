#include <bits/stdc++.h>
using namespace std;
int n;
int x11, y11, x12, y12, x21, y21, x22, y22;
void f(int &x1, int &x2, int &y1, int &y2, int xl, int yl, int xr, int yr) {
  int l = xl, r = xr;
  while (l < r) {
    int m = (l + r) / 2;
    printf("? %d %d %d %d\n", xl, yl, m, yr);
    fflush(stdout);
    int x;
    cin >> x;
    if (x)
      r = m;
    else
      l = m + 1;
  }
  x2 = l;
  l = xl;
  r = xr;
  while (l < r) {
    int m = (l + r + 1) / 2;
    printf("? %d %d %d %d\n", m, yl, xr, yr);
    fflush(stdout);
    int x;
    cin >> x;
    if (x)
      l = m;
    else
      r = m - 1;
  }
  x1 = l;
  l = yl;
  r = yr;
  while (l < r) {
    int m = (l + r) / 2;
    printf("? %d %d %d %d\n", xl, yl, xr, m);
    fflush(stdout);
    int x;
    cin >> x;
    if (x)
      r = m;
    else
      l = m + 1;
  }
  y2 = l;
  l = yl;
  r = yr;
  while (l < r) {
    int m = (l + r + 1) / 2;
    printf("? %d %d %d %d\n", xl, m, xr, yr);
    fflush(stdout);
    int x;
    cin >> x;
    if (x)
      l = m;
    else
      r = m - 1;
  }
  y1 = l;
}
int main() {
  cin >> n;
  int l = 0, r = n;
  bool ff = 0;
  while (l < r) {
    int m = (l + r + 1) / 2;
    printf("? %d %d %d %d\n", 1, 1, m, n);
    fflush(stdout);
    int x;
    cin >> x;
    if (x == 0)
      l = m;
    else
      r = m - 1;
  }
  l++;
  if (l != n) {
    printf("? %d %d %d %d\n", l + 1, 1, n, n);
    fflush(stdout);
    int xx;
    cin >> xx;
    if (xx == 1) ff = 1;
  }
  if (ff) {
    f(x11, x12, y11, y12, 1, 1, l, n);
    f(x21, x22, y21, y22, l + 1, 1, n, n);
  } else {
    l = 0;
    r = n;
    while (l < r) {
      int m = (l + r + 1) / 2;
      printf("? %d %d %d %d\n", 1, 1, n, m);
      fflush(stdout);
      int x;
      cin >> x;
      if (x == 0)
        l = m;
      else
        r = m - 1;
    }
    l++;
    f(x11, x12, y11, y12, 1, 1, n, l);
    f(x21, x22, y21, y22, 1, l + 1, n, n);
  }
  printf("! %d %d %d %d %d %d %d %d\n", x11, y11, x12, y12, x21, y21, x22, y22);
  fflush(stdout);
}
