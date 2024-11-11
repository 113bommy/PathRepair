#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& x) {
  bool fu = 0;
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') fu = 1, c = getchar();
  for (x = 0; c > 32; c = getchar()) x = x * 10 + c - '0';
  if (fu) x = -x;
};
template <class T>
inline void read(T& x, T& y) {
  read(x);
  read(y);
}
template <class T>
inline void read(T& x, T& y, T& z) {
  read(x);
  read(y);
  read(z);
}
inline char getc() {
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  return c;
}
const int D = 86;
int T, i, j, k, l, p, d;
long long f[1111], s[1111], n, a[111];
long long g[D + 1][D + 1][D + 1];
int cnt[D + 1][D + 1][D + 1];
long long dp(int i, int x, int y) {
  if (i == 1) return x <= 1 && y == 0;
  if (x * f[i] + y * f[i - 1] >= s[i]) return 0;
  if (cnt[i][x][y] == T) return g[i][x][y];
  cnt[i][x][y] = T;
  g[i][x][y] = dp(i - 1, y + x, x + a[i - 2]);
  if (x) g[i][x][y] += dp(i - 1, y + x - 1, x - 1 + a[i - 2]);
  return g[i][x][y];
}
int main() {
  f[0] = 1;
  f[1] = 1;
  for (i = 2; i <= D; i++) f[i] = f[i - 1] + f[i - 2];
  for (i = 1; i <= D; i++) s[i] = s[i - 1] + f[i];
  for (read(T); T; T--) {
    read(n);
    d = 0;
    for (i = D; i >= 1; i--)
      if (n >= f[i]) {
        if (d == 0) d = i;
        a[i] = 1, n -= f[i];
      } else
        a[i] = 0;
    printf("%I64d\n", dp(d, 1, a[d - 1]));
  }
  return 0;
}
