#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void checkmin(T& a, const T& b) {
  if (b < a) a = b;
}
template <class T>
inline void checkmax(T& a, const T& b) {
  if (b > a) a = b;
}
template <class T>
inline T sqr(const T& a) {
  return a * a;
}
long long c[1500 + 5][1500 + 5];
long long p[1500 + 5][1500 + 5];
int main() {
  long long lowest = ((long long)-10000) * 1500 * 1500 * 100;
  int n, m;
  scanf("%d%d", &n, &m);
  int tmp;
  for (int i = 0, _n = (n); i < _n; ++i)
    for (int j = 0, _n = (m); j < _n; ++j) {
      scanf("%d", &tmp);
      c[i][j] = tmp;
    }
  for (int i = 0, _n = (n); i < _n; ++i)
    for (int j = (1), _n = (m); j < _n; ++j) c[i][j] = c[i][j - 1] + c[i][j];
  long long cur_max_left[1500 + 5];
  long long cur_max_right[1500 + 5];
  for (int j = 0, _n = (m); j < _n; ++j) p[n - 1][j] = c[n - 1][j];
  for (int _n = (n - 2), _a = (0), i = _n; i >= _a; --i) {
    cur_max_left[0] = p[i + 1][0];
    for (int j = (1), _n = (m); j < _n; ++j) {
      cur_max_left[j] = p[i + 1][j];
      checkmax(cur_max_left[j], cur_max_left[j - 1]);
    }
    cur_max_right[m - 1] = p[i + 1][m - 1];
    for (int _n = (m - 2), _a = (0), j = _n; j >= _a; --j) {
      cur_max_right[j] = p[i + 1][j];
      checkmax(cur_max_right[j], cur_max_right[j + 1]);
    }
    if (i % 2 == 0) {
      for (int j = 0, _n = (m); j < _n; ++j) {
        p[i][j] = lowest;
        if (j > 0) checkmax(p[i][j], c[i][j] + cur_max_left[j - 1]);
      }
    } else {
      for (int j = 0, _n = (m); j < _n; ++j) {
        p[i][j] = lowest;
        if (j < m - 1) checkmax(p[i][j], c[i][j] + cur_max_right[j + 1]);
      }
    }
  }
  long long answer = p[0][1];
  for (int j = (1), _n = (m); j < _n; ++j) checkmax(answer, p[0][j]);
  printf("%lld\n", answer);
  return 0;
}
