#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void umax(T &x, T y) {
  if (y > x) x = y;
}
template <class T>
inline void umin(T &x, T y) {
  if (y < x) x = y;
}
const int N = 2e5 + 5, B = 0x7fffffff;
char a[3][4];
int main() {
  for (int i = 0; i < 3; i++) scanf("%s", a[i]);
  bool ok = 1;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (a[i][j] != a[2 - i][2 - j]) ok = 0;
  return puts(ok ? "YES" : "NO"), !1;
}
