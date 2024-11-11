#include <bits/stdc++.h>
using namespace std;
const int nm = 52;
const long long mod = 1000000007;
const int x[] = {-1, 0, 0, 1};
const int y[] = {0, -1, 1, 0};
struct bg {
  int k, x, y, t;
};
struct matrix {
  int m, n;
  long long a[nm][nm];
};
int m, n, q;
bg aaa[10010];
matrix c, v, mtdv, tmp;
int cat[nm][nm];
bool hople(int i, int j) { return i > 0 && i <= m && j > 0 && j <= n; }
void build() {
  c.m = c.n = m * n;
  for (int i = 1; i <= c.m; ++i) {
    for (int j = 1; j <= c.n; ++j) c.a[i][j] = 0;
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (!cat[i][j]) {
        c.a[(i - 1) * n + j][(i - 1) * n + j] = 1;
        for (int k = 0; k < 4; ++k) {
          int i2 = i + x[k], j2 = j + y[k];
          if (hople(i2, j2) && !cat[i2][j2]) {
            c.a[(i - 1) * n + j][(i2 - 1) * n + j2] = 1;
          }
        }
      }
    }
  }
}
matrix mul(matrix a, matrix b) {
  tmp.m = a.m;
  tmp.n = b.n;
  for (int i = 1; i <= tmp.m; ++i)
    for (int j = 1; j <= tmp.n; ++j) {
      tmp.a[i][j] = 0;
      for (int k = 1; k <= a.n; ++k)
        tmp.a[i][j] = (tmp.a[i][j] + (a.a[i][k] * b.a[k][j]) % mod) % mod;
    }
  return tmp;
}
matrix power(matrix a, int n) {
  if (!n) return mtdv;
  tmp = power(a, n >> 1);
  tmp = mul(tmp, tmp);
  if (n & 1) tmp = mul(tmp, a);
  return tmp;
}
int main() {
  scanf("%d%d%d", &m, &n, &q);
  for (int i = 1; i <= q; ++i) {
    scanf("%d%d%d%d", &aaa[i].k, &aaa[i].x, &aaa[i].y, &aaa[i].t);
  }
  v.m = m * n;
  v.n = 1;
  for (int i = 1; i <= v.m; ++i) v.a[i][1] = 0;
  v.a[1][1] = 1;
  mtdv.m = mtdv.n = m * n;
  for (int i = 1; i <= mtdv.m; ++i)
    for (int j = 1; j <= mtdv.n; ++j) mtdv.a[i][j] = (i == j);
  aaa[0].t = 1;
  for (int i = 1; i <= q; ++i) {
    build();
    c = power(c, aaa[i].t - aaa[i - 1].t);
    v = mul(c, v);
    if (aaa[i].k == 1) {
      printf("%I64d\n", v.a[(aaa[i].x - 1) * n + aaa[i].y][1]);
    } else if (aaa[i].k == 2) {
      cat[aaa[i].x][aaa[i].y] = 1;
    } else
      cat[aaa[i].x][aaa[i].y] = 0;
  }
}
