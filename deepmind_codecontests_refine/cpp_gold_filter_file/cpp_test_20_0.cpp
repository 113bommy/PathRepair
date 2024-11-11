#include <bits/stdc++.h>
template <typename T>
inline T abs(T x) {
  return x < 0 ? -x : x;
}
template <typename T>
inline T ma(T &x, T y) {
  return x < y ? x = y : T();
}
template <typename T>
inline T mi(T &x, T y) {
  return x > y ? x = y : T();
}
using namespace std;
struct Read {
  template <typename T>
  inline const Read &operator()(T &x) const {
    int s = 1, d = getchar();
    x = 0;
    for (; !isdigit(d); d = getchar())
      if (!(d ^ '-')) s = -1;
    while (isdigit(d)) x = x * 10 + (d & 15), d = getchar();
    x *= s;
    return *this;
  }
} read;
inline int gi() {
  int x;
  read(x);
  return x;
}
template <class T>
void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int T = 1e2 + 10;
const int N = 4e2 + 10;
const int M = 6e5 + 10;
const int K = 3e2 + 10;
const int LG = 20;
const int Q = N * 2;
const int P = 19950501;
const int base = 19491001;
const int inf = ~0U >> 2;
const long long infll = ~0ULL >> 1;
const double eps = 1e-9;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int n, m, v1[N], v2[N], r, bl[N];
char a[N][N];
int main() {
  int t = gi();
  while (t--) {
    read(n)(m);
    r = n * m;
    for (int _a = (n), i = 0; i < _a; ++i) scanf("%s", a[i]);
    for (int _a = (n - 4), i = 0; i < _a; ++i) {
      for (int _a = (m), j = 0; j < _a; ++j) v1[j] = a[i][j] == '0', v2[j] = 0;
      for (int _a = (3), j = 1; j <= _a; ++j)
        for (int _a = (m), k = 0; k < _a; ++k)
          v1[k] += a[i + j][k] == '1', v2[k] += a[i + j][k] == '0';
      for (int _a = (n - 1), j = i + 4; j <= _a; ++j) {
        bl[0] = v2[0];
        for (int _a = (m - 1), k = 1; k <= _a; ++k) {
          if (k >= 3)
            mi(r, bl[k - 3] + v2[k] + v1[k - 1] + v1[k - 2] +
                      (a[j][k - 1] == '0') + (a[j][k - 2] == '0'));
          bl[k] = min(v2[k], bl[k - 1] + v1[k] + (a[j][k] == '0'));
        }
        for (int _a = (m), k = 0; k < _a; ++k)
          v1[k] += a[j][k] == '1', v2[k] += a[j][k] == '0';
      }
    }
    cout << r << endl;
  }
}
