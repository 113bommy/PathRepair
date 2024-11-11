#include <bits/stdc++.h>
using namespace std;
long long getint() {
  long long _x = 0, _tmp = 1;
  char _tc = getchar();
  while ((_tc < '0' || _tc > '9') && _tc != '-') _tc = getchar();
  if (_tc == '-') _tc = getchar(), _tmp = -1;
  while (_tc >= '0' && _tc <= '9') _x *= 10, _x += (_tc - '0'), _tc = getchar();
  return _x * _tmp;
}
long long mypow(long long _a, long long _x, long long _mod) {
  if (_x == 0) return 1ll;
  long long _tmp = mypow(_a, _x / 2, _mod);
  _tmp = (_tmp * _tmp) % _mod;
  if (_x & 1) _tmp = (_tmp * _a) % _mod;
  return _tmp;
}
bool equal(double _x, double _y) { return _x > _y - 1e-9 && _x < _y + 1e-9; }
int __ = 1, cs;
int n, a[2][1010], b[1010];
int ls[2][1010], rs[2][1010];
void build() {}
void init() {
  n = getint();
  for (int i = 0; i < 2; i++)
    for (int j = 1; j < n; j++) a[i][j] = getint();
  for (int i = 1; i <= n; i++) b[i] = getint();
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j < n; j++) ls[i][j] = ls[i][j - 1] + a[i][j - 1];
    for (int j = n; j; j--) rs[i][j] = rs[i][j + 1] + a[i][j];
  }
}
void solve() {
  vector<int> vans;
  for (int i = 1; i <= n; i++) vans.push_back(ls[0][i] + rs[1][i] + b[i]);
  sort((vans).begin(), (vans).end());
  printf("%d\n", vans[0] + vans[1]);
}
int main() {
  build();
  while (__--) {
    init();
    solve();
  }
}
