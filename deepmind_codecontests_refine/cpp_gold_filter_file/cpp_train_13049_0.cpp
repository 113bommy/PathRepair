#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
inline long long getint() {
  long long _x = 0, _tmp = 1;
  char _tc = getchar();
  while ((_tc < '0' || _tc > '9') && _tc != '-') _tc = getchar();
  if (_tc == '-') _tc = getchar(), _tmp = -1;
  while (_tc >= '0' && _tc <= '9') _x *= 10, _x += (_tc - '0'), _tc = getchar();
  return _x * _tmp;
}
inline long long add(long long _x, long long _y,
                     long long _mod = 1000000007LL) {
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline long long sub(long long _x, long long _y,
                     long long _mod = 1000000007LL) {
  _x -= _y;
  return _x < 0 ? _x + _mod : _x;
}
inline long long mul(long long _x, long long _y,
                     long long _mod = 1000000007LL) {
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}
long long mypow(long long _a, long long _x, long long _mod) {
  if (_x == 0) return 1LL;
  long long _ret = mypow(mul(_a, _a, _mod), _x >> 1, _mod);
  if (_x & 1) _ret = mul(_ret, _a, _mod);
  return _ret;
}
long long mymul(long long _a, long long _x, long long _mod) {
  if (_x == 0) return 0LL;
  long long _ret = mymul(add(_a, _a, _mod), _x >> 1, _mod);
  if (_x & 1) _ret = add(_ret, _a, _mod);
  return _ret;
}
inline bool equal(double _x, double _y) {
  return _x > _y - 1e-9 && _x < _y + 1e-9;
}
int __ = 1, _cs;
int C[111][111];
void build() {
  for (int i = 0; i < 111; i++) C[i][0] = C[i][i] = 1;
  for (int i = 2; i < 111; i++)
    for (int j = 1; j < i; j++) C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
}
int n, a[111];
void init() {
  n = getint();
  for (int i = 0; i < 10; i++) a[i] = getint();
}
int dp[111][111];
int cal(int len) {
  for (int i = 0; i <= 10; i++)
    for (int j = 0; j <= len; j++) dp[i][j] = 0;
  dp[10][0] = 1;
  for (int i = 9; i >= 0; i--)
    for (int j = 0; j <= len; j++) {
      int pre = dp[i + 1][j];
      if (pre == 0) continue;
      for (int jj = a[i]; j + jj <= len; jj++) {
        if (i or jj == 0) {
          int tdp = mul(pre, C[j + jj][jj]);
          dp[i][j + jj] = add(dp[i][j + jj], tdp);
        } else {
          int tdp = mul(pre, C[j + jj - 1][jj]);
          dp[i][j + jj] = add(dp[i][j + jj], tdp);
        }
      }
    }
  return dp[0][len];
}
void solve() {
  int tot = accumulate(a, a + 10, 0);
  if (tot > n) {
    puts("0");
    exit(0);
  }
  int ans = 0;
  for (int l = max(tot, 1); l <= n; l++) ans = add(ans, cal(l));
  printf("%d\n", ans);
}
int main() {
  build();
  while (__--) {
    init();
    solve();
  }
}
