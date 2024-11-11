#include <bits/stdc++.h>
using namespace std;
void file() {
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}
int n, l, r, m, x1, x2, y111, y2, x3, x4, y3, y4;
bool is(int x1, int x2, int y111, int y2) {
  int f;
  cout << "? " << x1 << " " << x2 << " " << y111 << " " << y2 << endl;
  cin >> f;
  return (f > 0);
}
bool is1(int x, int y, int x8, int y8) {
  int f;
  cout << "? " << x << " " << y << " " << x8 << " " << y8 << endl;
  int k = 0;
  if (x1 >= x && x1 <= x8 && x2 >= x && x2 <= x8 && y111 >= y && y111 <= y8 &&
      y2 >= y && y2 <= y8)
    k = 1;
  cin >> f;
  return (f - k > 0);
}
int main() {
  cin >> n;
  l = 1;
  r = n;
  while (l < r - 1) {
    m = (l + r) / 2;
    if (is(1, 1, n, m))
      r = m;
    else
      l = m;
  }
  if (is(1, 1, n, l))
    y2 = l;
  else
    y2 = r;
  l = 1;
  r = y2;
  while (l < r - 1) {
    m = (l + r) / 2;
    if (is(1, m, n, y2))
      l = m;
    else
      r = m;
  }
  if (is(1, r, n, y2))
    y111 = r;
  else
    y111 = l;
  l = 1;
  r = n;
  while (l < r - 1) {
    m = (l + r) / 2;
    if (is(1, y111, m, y2))
      r = m;
    else
      l = m;
  }
  if (is(1, y111, l, y2))
    x2 = l;
  else
    x2 = r;
  l = 1;
  r = x2;
  while (l < r - 1) {
    m = (l + r) / 2;
    if (is(m, y111, x2, y2))
      l = m;
    else
      r = m;
  }
  if (is(r, y111, x2, y2))
    x1 = r;
  else
    x1 = l;
  l = 1;
  r = n;
  while (l < r - 1) {
    m = (l + r) / 2;
    if (is1(1, 1, n, m))
      r = m;
    else
      l = m;
  }
  if (is1(1, 1, n, l))
    y4 = l;
  else
    y4 = r;
  l = 1;
  r = y4;
  while (l < r - 1) {
    m = (l + r) / 2;
    if (is1(1, m, n, y4))
      l = m;
    else
      r = m;
  }
  if (is1(1, r, n, y4))
    y3 = r;
  else
    y3 = l;
  l = 1;
  r = n;
  while (l < r - 1) {
    m = (l + r) / 2;
    if (is1(1, y3, m, y4))
      r = m;
    else
      l = m;
  }
  if (is1(1, y3, l, y4))
    x4 = l;
  else
    x4 = r;
  l = 1;
  r = x4;
  while (l < r - 1) {
    m = (l + r) / 2;
    if (is1(m, y3, x4, y4))
      l = m;
    else
      r = m;
  }
  if (is1(r, y3, x4, y4))
    x3 = r;
  else
    x3 = l;
  cout << "! " << x1 << " " << x2 << " " << y111 << " " << y2 << " " << x3
       << " " << y3 << " " << x4 << " " << y4 << endl;
}
