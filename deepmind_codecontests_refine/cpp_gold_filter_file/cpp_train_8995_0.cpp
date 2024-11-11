#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const double eps = 1e-9;
const int maxn = 6;
int in[maxn];
int out[maxn];
int a[maxn][maxn] = {{2, 1, 1, 0, 1, 0}, {1, 2, 0, 1, 1, 0},
                     {1, 1, 1, 0, 1, 0}, {1, 1, 0, 1, 1, 0},
                     {0, 0, 0, 0, 1, 1}, {0, 0, 0, 0, 0, 1}};
int n;
int res[maxn][maxn];
int c[maxn][maxn];
inline void multAA() {
  memset(c, 0, sizeof c);
  for (int i = 0; (i) < (maxn); ++i)
    for (int j = 0; (j) < (maxn); ++j)
      for (int k = 0; (k) < (maxn); ++k)
        c[i][j] = (c[i][j] + a[i][k] * (long long)a[k][j]) % n;
  for (int i = 0; (i) < (maxn); ++i)
    for (int j = 0; (j) < (maxn); ++j) a[i][j] = c[i][j];
}
inline void multresA() {
  memset(c, 0, sizeof c);
  for (int i = 0; (i) < (maxn); ++i)
    for (int j = 0; (j) < (maxn); ++j)
      for (int k = 0; (k) < (maxn); ++k)
        c[i][j] = (c[i][j] + res[i][k] * (long long)a[k][j]) % n;
  for (int i = 0; (i) < (maxn); ++i)
    for (int j = 0; (j) < (maxn); ++j) res[i][j] = c[i][j];
}
inline void getRes() {
  for (int i = 0; (i) < (maxn); ++i)
    for (int j = 0; (j) < (maxn); ++j)
      out[i] = (out[i] + in[j] * (long long)res[i][j]) % n;
}
int main() {
  int sx, sy, dx, dy;
  scanf("%d%d%d%d%d", &n, &sx, &sy, &dx, &dy);
  long long t;
  scanf("%I64d", &t);
  in[0] = sx, in[1] = sy, in[2] = dx, in[3] = dy, in[4] = 0, in[5] = 1;
  for (int i = 0; (i) < (maxn); ++i) in[i] = (in[i] % n + n) % n;
  for (int i = 0; (i) < (maxn); ++i) res[i][i] = 1;
  while (t > 0) {
    if (t & 1) multresA();
    multAA();
    t >>= 1;
  }
  getRes();
  int resX = out[0];
  int resY = out[1];
  if (resX == 0) resX += n;
  if (resY == 0) resY += n;
  printf("%d %d\n", resX, resY);
  return 0;
}
