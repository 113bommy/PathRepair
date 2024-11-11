#include <bits/stdc++.h>
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
                     long long _mod = 1000000007ll) {
  long long _ = _x + _y;
  if (_ >= _mod) _ -= _mod;
  return _;
}
inline long long sub(long long _x, long long _y,
                     long long _mod = 1000000007ll) {
  long long _ = _x - _y;
  if (_ < 0) _ += _mod;
  return _;
}
inline long long mul(long long _x, long long _y,
                     long long _mod = 1000000007ll) {
  long long _ = _x * _y;
  if (_ >= _mod) _ %= _mod;
  return _;
}
long long mypow(long long _a, long long _x, long long _mod) {
  if (_x == 0) return 1ll;
  long long _tmp = mypow(_a, _x / 2, _mod);
  _tmp = mul(_tmp, _tmp, _mod);
  if (_x & 1) _tmp = mul(_tmp, _a, _mod);
  return _tmp;
}
long long mymul(long long _a, long long _x, long long _mod) {
  if (_x == 0) return 0ll;
  long long _tmp = mymul(_a, _x / 2, _mod);
  _tmp = add(_tmp, _tmp, _mod);
  if (_x & 1) _tmp = add(_tmp, _a, _mod);
  return _tmp;
}
inline bool equal(double _x, double _y) {
  return _x > _y - 1e-9 && _x < _y + 1e-9;
}
int __ = 1, _cs;
void build() {}
int n, m, q, x[202020], y[202020];
vector<pair<int, int> > qry;
int ql[202020], qr[202020], qs[202020], qt[202020];
bool ans[202020];
int mn[1010][1010];
inline void add(int idx) {
  mn[x[idx]][y[idx]] = mn[y[idx]][x[idx]] = idx;
  for (int i = 1; i <= n; i++) {
    mn[x[idx]][i] = min(mn[x[idx]][i], mn[y[idx]][i]);
    mn[y[idx]][i] = min(mn[y[idx]][i], mn[x[idx]][i]);
  }
}
void init() {
  n = getint();
  m = getint();
  q = getint();
  for (int i = 1; i <= m; i++) {
    x[i] = getint();
    y[i] = getint();
  }
  for (int i = 0; i < q; i++) {
    ql[i] = getint();
    qr[i] = getint();
    qs[i] = getint();
    qt[i] = getint();
    qry.push_back({ql[i], i});
    if (qs[i] == qt[i]) ans[i] = true;
  }
  sort((qry).begin(), (qry).end());
  reverse((qry).begin(), (qry).end());
}
void solve() {
  int midx = m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) mn[i][j] = 1010;
  for (size_t _ = 0; _ < qry.size(); _++) {
    int i = qry[_].second;
    while (midx >= 1 && midx >= ql[i]) add(midx--);
    if (mn[qs[i]][qt[i]] <= qr[i]) ans[i] = true;
  }
  for (int i = 0; i < q; i++) puts(ans[i] ? "Yes" : "No");
}
int main() {
  build();
  while (__--) {
    init();
    solve();
  }
}
