#include <bits/stdc++.h>
using namespace std;
int s, n, x, y;
int yoo(int x) {
  int ret = 1;
  for (; x--;) ret *= 2;
  return ret;
}
void calc(int sz, int n, bool wh, bool cl) {
  if (!sz) return;
  int q = yoo(2 * sz - 2), l = yoo(sz - 1);
  if (cl) {
    if (wh)
      if (n < q)
        calc(sz - 1, n, wh, cl ^ 1);
      else if (n < 2 * q)
        x -= l, calc(sz - 1, n - q, wh, cl);
      else if (n < 3 * q)
        x -= l, y -= l, calc(sz - 1, n - 2 * q, wh, cl);
      else if (n < 4 * q)
        y -= 2 * l - 1, x -= l - 1, calc(sz - 1, n - 3 * q, wh ^ 1, cl ^ 1);
    if (!wh)
      if (n < q)
        calc(sz - 1, n, wh, cl ^ 1);
      else if (n < 2 * q)
        x += l, calc(sz - 1, n - q, wh, cl);
      else if (n < 3 * q)
        x += l, y += l, calc(sz - 1, n - 2 * q, wh, cl);
      else if (n < 4 * q)
        y += 2 * l - 1, x += l - 1, calc(sz - 1, n - 3 * q, wh ^ 1, cl ^ 1);
  } else {
    if (wh)
      if (n < q)
        calc(sz - 1, n, wh, cl ^ 1);
      else if (n < 2 * q)
        y -= l, calc(sz - 1, n - q, wh, cl);
      else if (n < 3 * q)
        x -= l, y -= l, calc(sz - 1, n - 2 * q, wh, cl);
      else if (n < 4 * q)
        x -= 2 * l - 1, y -= l - 1, calc(sz - 1, n - 3 * q, wh ^ 1, cl ^ 1);
    if (!wh)
      if (n < q)
        calc(sz - 1, n, wh, cl ^ 1);
      else if (n < 2 * q)
        y += l, calc(sz - 1, n - q, wh, cl);
      else if (n < 3 * q)
        x += l, y += l, calc(sz - 1, n - 2 * q, wh, cl);
      else if (n < 4 * q)
        x += 2 * l - 1, y += l - 1, calc(sz - 1, n - 3 * q, wh ^ 1, cl ^ 1);
  }
}
int main() {
  cin >> s >> n;
  calc(s, n, 0, 0);
  cout << x << ' ' << y << endl;
  return 0;
}
