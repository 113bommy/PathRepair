#include <bits/stdc++.h>
using namespace std;
const int xx[] = {0, 1, 0, -1, -1, 1, -1, 1};
const int yy[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};
char str[100005];
int main() {
  int i, j, k, x, ans, l, n, mn, t, mx, m, sum, u, e, w, h, a, b, c, d;
  char ch, ch1;
  bool key = 1, flag = 1;
  unsigned long long int res, y;
  scanf("%s", str);
  x = 0;
  e = -1;
  res = 1;
  for (i = 1; str[i]; i++) {
    if ((str[i] - '0') + (str[i - 1] - '0') == ('9' - '0')) {
      if (e == -1) {
        e = i - 1;
      }
    } else {
      if (e >= 0) {
        y = i - e;
        if (y % 2) {
          res *= (y / 2) + 1;
        }
      }
      e = -1;
    }
  }
  if (e >= 0) {
    y = i - e;
    if (y % 2) res *= (y / 2) + 1;
  }
  printf("%llu\n", res);
  return 0;
}
