#include <bits/stdc++.h>
using namespace std;
inline int min(int _a, int _b) { return _a < _b ? _a : _b; }
inline int max(int _a, int _b) { return _a > _b ? _a : _b; }
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
template <class _T>
inline void rd(_T &_a) {
  int _f = 0, _ch = getchar();
  _a = 0;
  while (_ch < '0' || _ch > '9') {
    if (_ch == '-') _f = 1;
    _ch = getchar();
  }
  while (_ch >= '0' && _ch <= '9')
    _a = (_a << 1) + (_a << 3) + _ch - '0', _ch = getchar();
  if (_f) _a = -_a;
}
int n, len;
char s[100][100];
long long f[1 << 21];
double ans[1 << 21], res;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  len = strlen(s[1]);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      int same = 0;
      for (int k = 0; k < len; ++k) {
        if (s[i][k] != s[j][k]) continue;
        same |= (1 << k);
      }
      f[same] |= (1ll << j);
    }
  }
  for (int i = (1 << len) - 1; i >= 0; --i) {
    for (int j = 0; j < len; ++j) {
      if (i & (1 << j)) f[i ^ (1 << j)] |= f[i];
    }
  }
  ans[0] = 1;
  for (int i = 0; i < (1 << len); ++i) {
    int cnt = 0;
    for (int j = 0; j < len; ++j)
      if (i & (1 << j)) ++cnt;
    for (int j = 0; j < len; ++j) {
      if (i & (1 << j)) continue;
      ans[i | (1 << j)] += ans[i] / (len - cnt);
    }
    for (int j = 0; j < n; ++j) {
      if (f[i] & (1ll << j)) res += ans[i];
    }
  }
  printf("%.10lf\n", res / n);
  return 0;
}
