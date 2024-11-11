#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
int x1, Y1, x2, y2;
int inside(int a, int b, int c, int d) {
  if (a <= x1 && b <= Y1 && c >= x2 && d >= y2)
    return 1;
  else
    return 0;
}
int main() {
  int n;
  cin >> n;
  int k;
  int l = 1, h = n, m;
  while (l < h) {
    m = (l + h) >> 1;
    cout << '?' << ' ' << 1 << ' ' << 1 << ' ' << m << ' ' << n << '\n';
    cin >> k;
    if (k > 0)
      h = m;
    else
      l = m + 1;
  }
  x2 = l;
  l = 1, h = n;
  while (l < h) {
    m = (l + h) >> 1;
    cout << '?' << ' ' << 1 << ' ' << 1 << ' ' << x2 << ' ' << m << '\n';
    cin >> k;
    if (k > 0)
      h = m;
    else
      l = m + 1;
  }
  y2 = l;
  l = 1, h = x2;
  while (l < h) {
    m = (l + h + 1) >> 1;
    cout << '?' << ' ' << m << ' ' << 1 << ' ' << x2 << ' ' << y2 << '\n';
    cin >> k;
    if (k > 0)
      l = m;
    else
      h = m - 1;
  }
  x1 = l;
  l = 1, h = y2;
  while (l < h) {
    m = (l + h + 1) >> 1;
    cout << '?' << ' ' << x1 << ' ' << m << ' ' << x2 << ' ' << y2 << '\n';
    cin >> k;
    if (k > 0)
      l = m;
    else
      h = m - 1;
  }
  Y1 = l;
  int x3, y3, x4, y4;
  l = 1, h = n;
  while (l < h) {
    m = (l + h) >> 1;
    cout << '?' << ' ' << 1 << ' ' << 1 << ' ' << m << ' ' << n << '\n';
    cin >> k;
    k -= inside(1, 1, m, n);
    if (k > 0)
      h = m;
    else
      l = m + 1;
  }
  x4 = l;
  l = 1, h = n;
  while (l < h) {
    m = (l + h) >> 1;
    cout << '?' << ' ' << 1 << ' ' << 1 << ' ' << x4 << ' ' << m << '\n';
    cin >> k;
    k -= inside(1, 1, x4, m);
    if (k > 0)
      h = m;
    else
      l = m + 1;
  }
  y4 = l;
  l = 1, h = x4;
  while (l < h) {
    m = (l + h + 1) >> 1;
    cout << '?' << ' ' << m << ' ' << 1 << ' ' << x4 << ' ' << y4 << '\n';
    cin >> k;
    k -= inside(m, 1, x4, y4);
    if (k > 0)
      l = m;
    else
      h = m - 1;
  }
  x3 = l;
  l = 1, h = y2;
  while (l < h) {
    m = (l + h + 1) >> 1;
    cout << '?' << ' ' << x3 << ' ' << m << ' ' << x4 << ' ' << y4 << '\n';
    cin >> k;
    k -= inside(m, 1, x4, y4);
    if (k > 0)
      l = m;
    else
      h = m - 1;
  }
  y3 = l;
  cout << '!' << x1 << ' ' << Y1 << ' ' << x2 << ' ' << y2 << ' ' << x3 << ' '
       << y3 << ' ' << x4 << ' ' << y4 << '\n';
}
