#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.14159265358979;
int ans[1002];
int main() {
  int n, k, m, mn;
  scanf("%d", &n);
  cout << 5 + (n - 1) * 4 << endl;
  cout << fixed << setprecision(10);
  long double xc, yc, p[2], R, tx, ty;
  xc = yc = 0;
  R = 5 / sin(pi / 5);
  p[0] = pi / 2 + pi * 4 / 5;
  p[1] = pi * 3 / 2 - pi * 4 / 5;
  for (int i = 0; i < n;) {
    int k = (i % 2 ? 4 : 1);
    for (int j = min(i, 1); j < 5; ++j) {
      if (j == k) {
        tx = xc + R * cos(p[i % 2] + j * pi * 2. / 5.);
        ty = yc + R * sin(p[i % 2] + j * pi * 2. / 5.);
      }
      cout << xc + R * cos(p[i % 2] + j * pi * 2. / 5.) << ' '
           << yc + R * sin(p[i % 2] + j * pi * 2. / 5.) << endl;
    }
    ++i;
    xc = tx - (R * cos(p[i % 2]));
    yc = ty - (R * sin(p[i % 2]));
  }
  for (int i = 1; i <= n; ++i) {
    if (i % 2)
      cout << 1 + (i / 2) * 8 << ' ' << 2 + (i / 2) * 8 << ' '
           << 3 + (i / 2) * 8 << ' ' << 4 + (i / 2) * 8 << ' '
           << 5 + (i / 2) * 8;
    else
      cout << 2 + (i / 2 - 1) * 8 << ' ' << 6 + (i / 2 - 1) * 8 << ' '
           << 7 + (i / 2 - 1) * 8 << ' ' << 8 + (i / 2 - 1) * 8 << ' '
           << 9 + (i / 2 - 1) * 8;
    cout << endl;
  }
  cout << 1 << ' ';
  for (int i = 1; i <= n; ++i) {
    if (i % 2)
      cout << 4 + (i / 2) * 8 << ' ' << 2 + (i / 2) * 8 << ' ';
    else
      cout << 7 + (i / 2 - 1) * 8 << ' ' << 9 + (i / 2 - 1) * 8 << ' ';
  }
  for (int i = n; i >= 1; --i) {
    if (i % 2)
      cout << 5 + (i / 2) * 8 << ' ' << 3 + (i / 2) * 8 << ' '
           << 1 + (i / 2) * 8 << ' ';
    else
      cout << 6 + (i / 2 - 1) * 8 << ' ' << 8 + (i / 2 - 1) * 8 << ' '
           << 2 + (i / 2 - 1) * 8;
  }
  return 0;
}
