#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long mod7 = 1000000007LL;
inline long long getint() {
  long long _x = 0, _tmp = 1;
  char _tc = getchar();
  while ((_tc < '0' || _tc > '9') && _tc != '-') _tc = getchar();
  if (_tc == '-') _tc = getchar(), _tmp = -1;
  while (_tc >= '0' && _tc <= '9') _x *= 10, _x += (_tc - '0'), _tc = getchar();
  return _x * _tmp;
}
inline long long add(long long _x, long long _y, long long _mod = mod7) {
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline long long sub(long long _x, long long _y, long long _mod = mod7) {
  _x -= _y;
  return _x < 0 ? _x + _mod : _x;
}
inline long long mul(long long _x, long long _y, long long _mod = mod7) {
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}
long long mypow(long long _a, long long _x, long long _mod) {
  if (_x == 0) return 1ll;
  long long _ret = mypow(mul(_a, _a, _mod), _x >> 1, _mod);
  if (_x & 1) _ret = mul(_ret, _a, _mod);
  return _ret;
}
long long mymul(long long _a, long long _x, long long _mod) {
  if (_x == 0) return 0ll;
  long long _ret = mymul(add(_a, _a, _mod), _x >> 1, _mod);
  if (_x & 1) _ret = add(_ret, _a, _mod);
  return _ret;
}
void sleep(double sec = 1021) {
  clock_t s = clock();
  while (clock() - s < CLOCKS_PER_SEC * sec)
    ;
}
int __ = 1, _cs;
const int mxN = 20;
int n, m, s;
long long k, a[mxN][mxN], ans;
unordered_map<long long, int> mps[mxN];
void dfs1(int i, int j, long long x) {
  if (i >= n || j >= m) return;
  x ^= a[i][j];
  if (i + j == s - 1) {
    ++mps[i][x];
    return;
  }
  dfs1(i + 1, j, x);
  dfs1(i, j + 1, x);
}
void dfs2(int i, int j, long long x) {
  if (i < 0 || j < 0) return;
  if (i + j == s - 1) {
    ans += mps[i][x ^ k];
    return;
  }
  x ^= a[i][j];
  dfs2(i - 1, j, x);
  dfs2(i, j - 1, x);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> a[i][j];
  s = max(n, m);
  for (int i = 0; i < s; ++i) mps[s].reserve(1 << s);
  dfs1(0, 0, 0);
  dfs2(n - 1, m - 1, 0);
  cout << ans;
}
