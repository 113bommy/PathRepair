#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T& x) {
  static char c;
  static int f;
  for (c = getchar(), f = 1; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -f;
  for (x = 0; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + (c & 15);
  x *= f;
}
template <typename T>
void write(T x) {
  static char q[65];
  int cnt = 0;
  if (x < 0) putchar('-'), x = -x;
  q[++cnt] = x % 10, x /= 10;
  while (x) q[++cnt] = x % 10, x /= 10;
  while (cnt) putchar(q[cnt--] + '0');
}
const int maxn = 55;
int Ma[maxn][maxn];
int query(int x, int y, int x_, int y_) {
  if (x > x_ || y > y_) swap(x, x_), swap(y, y_);
  printf("? %d %d %d %d\n", x, y, x_, y_);
  fflush(stdout);
  int re;
  read(re);
  return re;
}
int erus(int x, int y, int x_, int y_) {
  return Ma[x_][y_] ^ query(x, y, x_, y_) ^ 1;
}
void sure(int x, int y, int x_, int y_) { Ma[x][y] = erus(x, y, x_, y_); }
int main() {
  int n;
  read(n);
  memset(Ma, -1, sizeof Ma);
  Ma[1][1] = 1, Ma[n][n] = 0;
  Ma[n][n - 1] = 0;
  sure(n - 1, n - 2, n, n - 1);
  sure(n - 1, n, n - 1, n - 2);
  for (int i = n; i >= 1; --i) {
    for (int j = n; j >= 1; --j) {
      if (~Ma[i][j]) continue;
      if (i < n && j < n)
        sure(i, j, i + 1, j + 1);
      else if (i + 1 < n)
        sure(i, j, i + 2, j);
      else
        sure(i, j, i, j + 2);
    }
  }
  int az = n;
  while (Ma[az][az] == Ma[az - 2][az - 2]) az -= 2;
  int rv = false;
  if (Ma[az][az - 2] != Ma[az - 1][az - 1] ||
      Ma[az - 1][az - 2] != Ma[az - 2][az - 1]) {
    rv = (Ma[az][az - 1] ^ erus(az, az - 1, az - 2, az - 2));
  } else if (Ma[az - 2][az] != Ma[az - 1][az - 1] ||
             Ma[az - 1][az] != Ma[az][az - 1]) {
    rv = (Ma[az - 2][az - 1] ^ erus(az - 2, az - 1, az, az));
  } else {
    int tmp = query(az - 2, az - 2, az, az - 1);
    if (tmp)
      rv = (Ma[az - 2][az - 2] ^ Ma[az][az - 1]);
    else {
      if (Ma[az][az - 1] ^ Ma[az - 1][az - 2] ^ Ma[az - 1][az - 1]) {
        rv = (Ma[az][az - 1] ^ Ma[az][az]);
      } else {
        rv = (Ma[az - 1][az - 2] ^ erus(az - 1, az - 2, az, az));
      }
    }
  }
  if (rv) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if ((i + j) & 1) Ma[i][j] ^= 1;
      }
    }
  }
  puts("!");
  for (int i = 1; i <= n; ++i, putchar('\n'))
    for (int j = 1; j <= n; ++j) write(Ma[i][j]);
  fflush(stdout);
  return 0;
}
