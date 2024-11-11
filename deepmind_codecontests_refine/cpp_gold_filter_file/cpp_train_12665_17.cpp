#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& x) {
  char c;
  bool fu = 0;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') fu = 1, c = getchar();
  for (x = 0; c > 32; c = getchar()) x = x * 10 + c - '0';
  if (fu) x *= -1;
}
template <class T>
inline void read(T& x, T& y) {
  read(x);
  read(y);
}
template <class T>
inline void read(T& x, T& y, T& z) {
  read(x, y);
  read(z);
}
template <class T>
inline void MAX(T& x, T y) {
  if (x < y) x = y;
}
template <class T>
inline void MIN(T& x, T y) {
  if (x > y) x = y;
}
const int N = 111;
int n, L;
char s[N][N];
int a[N][N], b[N][N];
int main() {
  read(n, L);
  for (int _tmp = n, i = 1; i <= _tmp; ++i) {
    scanf("%s", s[i] + 1);
    for (int _tmp = n, j = 1; j <= _tmp; ++j)
      if (s[i][j] == '#')
        a[i][j] = 0;
      else
        a[i][j] = 1;
  }
  for (int _tmp = n, i = 1; i <= _tmp; ++i) {
    for (int _tmp = n, j = 1; j <= _tmp; ++j) {
      int l = i, r = i + L - 1;
      if (r <= n) {
        bool ok = 1;
        for (int _tmp = r, k = l; k <= _tmp; ++k)
          if (a[k][j] == 0) {
            ok = 0;
            break;
          }
        if (ok)
          for (int _tmp = r, k = l; k <= _tmp; ++k) b[k][j]++;
      }
      l = j, r = j + L - 1;
      if (r <= n) {
        bool ok = 1;
        for (int _tmp = r, k = l; k <= _tmp; ++k)
          if (a[i][k] == 0) {
            ok = 0;
            break;
          }
        if (ok)
          for (int _tmp = r, k = l; k <= _tmp; ++k) b[i][k]++;
      }
    }
  }
  int px = 1, py = 1, an = 0;
  for (int _tmp = n, i = 1; i <= _tmp; ++i) {
    for (int _tmp = n, j = 1; j <= _tmp; ++j)
      if (b[i][j] > an) {
        an = b[i][j];
        px = i;
        py = j;
      }
  }
  printf("%d %d\n", px, py);
  return 0;
}
