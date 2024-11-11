#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void R(T &xx) {
  xx = 0;
  char ch = getchar();
  bool F = 0;
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') F = 1, ch = getchar();
  while (ch >= '0' && ch <= '9')
    xx = xx + xx + (xx << 3) + ch - 48, ch = getchar();
  if (F) xx = -xx;
}
template <class T>
inline void add(int &x, T y) {
  for (x += y; x >= 51123987; x -= 51123987)
    ;
}
int f[11111][33], x, y, z;
int dp(int x, int y) {
  int &t = f[x][y];
  if (~t) return t;
  if (pow(x, y) + .5 > z) return 2;
  if (y > 31) return 1;
  if (y == 1 && x * x >= z) return t = ((z - x + 1) & 1) << 1;
  return t = 2 - min(dp(x + 1, y), dp(x, y + 1));
}
int main() {
  memset(f, -1, sizeof(f));
  R(x), R(y), R(z);
  int tmp = dp(x, y);
  puts((!tmp) ? "Stas" : ((tmp == 1) ? "Missing" : "Masha"));
  return 0;
}
