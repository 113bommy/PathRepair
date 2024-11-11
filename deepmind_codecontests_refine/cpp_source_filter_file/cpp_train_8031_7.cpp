#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int n, m;
char s[256][256];
int stop;
inline int right(int i) {
  for (int k = (m - 1), _b = (0); k >= _b; --k)
    if (s[i][k] == 'W') return k;
  return -1;
}
inline int left(int i) {
  for (int k = (0), _b = (m - 1); k <= _b; ++k)
    if (s[i][k] == 'W') return k;
  return -1;
}
inline int myabs(int x) { return x < 0 ? -x : x; }
int cache[160][160];
int calc(int r, int c) {
  int &ret = cache[r][c];
  if (ret >= 0) return ret;
  if (r == stop) return ret = 0;
  ret = INF;
  int extra = ((r + 1) >= stop) ? 0 : 1;
  if (r & 1) {
    int s = left(r);
    if (s == -1)
      for (int i = (c), _b = (0); i >= _b; --i)
        ret = min(ret, extra + calc(r + 1, i) + myabs(c - i));
    else if (c <= right(r))
      for (int i = (s), _b = (0); i >= _b; --i)
        ret = min(ret, extra + calc(r + 1, i) + myabs(c - i));
  } else {
    int s = right(r);
    if (s == -1)
      for (int i = (c), _b = (m - 1); i <= _b; ++i)
        ret = min(ret, extra + calc(r + 1, i) + myabs(c - i));
    else if (c >= left(s))
      for (int i = (s), _b = (m - 1); i <= _b; ++i)
        ret = min(ret, extra + calc(r + 1, i) + myabs(c - i));
  }
  return ret;
}
int main() {
  while (scanf("%d %d", &n, &m) == 2) {
    for (int i = 0, _n = (n); i < _n; ++i) {
      scanf("%s", s[i]);
      if (left(i) != -1) stop = i + 1;
    }
    for (int a = 0, _n = (160); a < _n; ++a)
      for (int b = 0, _n = (160); b < _n; ++b) cache[a][b] = -1;
    cout << calc(0, 0) << endl;
  }
  return 0;
}
