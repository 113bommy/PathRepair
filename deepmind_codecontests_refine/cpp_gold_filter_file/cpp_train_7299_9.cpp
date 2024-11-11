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
const int mxN = 1e5;
int n, m, k, li, ri, pi, ai, bi, xi, yi;
vector<pair<int, int>> a[mxN], st[1 << 18];
void o(int i) {
  sort(st[i].begin(), st[i].end());
  int b = 0;
  for (int j = 0; j < st[i].size(); ++j) {
    if (j && st[i][j].first == st[i][j - 1].first) continue;
    while (b && st[i][b - 1].second >= st[i][j].second) --b;
    st[i][b++] = st[i][j];
  }
  st[i].resize(b);
}
void bld(int i = 1, int l2 = 0, int r2 = n - 1) {
  if (l2 == r2) {
    st[i] = a[l2];
    o(i);
    return;
  }
  int m2 = (l2 + r2) / 2;
  bld(2 * i, l2, m2);
  bld(2 * i + 1, m2 + 1, r2);
  for (int i1 = 0, i2 = 0;
       i1 < st[2 * i].size() && i2 < st[2 * i + 1].size();) {
    st[i].push_back({min(st[2 * i][i1].first, st[2 * i + 1][i2].first),
                     max(st[2 * i][i1].second, st[2 * i + 1][i2].second)});
    if (st[2 * i][i1].first == st[2 * i + 1][i2].first) {
      ++i1;
      ++i2;
    } else if (st[2 * i][i1].first < st[2 * i + 1][i2].first)
      ++i1;
    else
      ++i2;
  }
}
int qry(int l1, int r1, int x, int i = 1, int l2 = 0, int r2 = n - 1) {
  if (l1 <= l2 && r2 <= r1) {
    int p = lower_bound(st[i].begin(), st[i].end(), pair<int, int>{x, 0}) -
            st[i].begin();
    return p >= st[i].size() ? 1e9 + 69 : st[i][p].second;
  }
  int m2 = (l2 + r2) / 2;
  return max(l1 <= m2 ? qry(l1, r1, x, 2 * i, l2, m2) : 0,
             m2 < r1 ? qry(l1, r1, x, 2 * i + 1, m2 + 1, r2) : 0);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  while (k--) {
    cin >> li >> ri >> pi, --pi;
    a[pi].push_back({li, ri});
  }
  bld();
  while (m--) {
    cin >> ai >> bi >> xi >> yi, --ai, --bi;
    cout << (qry(ai, bi, xi) <= yi ? "yes" : "no") << endl;
  }
}
