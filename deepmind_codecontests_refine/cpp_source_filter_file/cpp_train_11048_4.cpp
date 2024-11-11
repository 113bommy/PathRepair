#include <bits/stdc++.h>
using namespace std;
inline long long scan() {
  long long _x = 0, _tmp = 1;
  char _tc = getchar();
  while ((_tc < '0' || _tc > '9') && _tc != '-') _tc = getchar();
  if (_tc == '-') _tc = getchar(), _tmp = -1;
  while (_tc >= '0' && _tc <= '9') _x *= 10, _x += (_tc - '0'), _tc = getchar();
  return _x * _tmp;
}
int main() {
  int n = scan();
  int x = 0, y = 0;
  for (int i = 0; i < 2 * n; ++i) {
    int xx, yy;
    xx = scan();
    yy = scan();
    x += xx;
    y += yy;
  }
  cout << x / n << " " << y / n << endl;
}
