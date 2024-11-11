#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
struct matrix {
  long long m[32][32];
} A, I;
const int mod = 1e9 + 7;
int dir[6][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {0, 0}};
int cat[31][31];
int n, m, w, x, type, y, t, lastt;
int q;
inline matrix mul(matrix a, matrix b) {
  matrix c;
  for (int i = 0; i < w; i++)
    for (int j = 0; j < w; j++) {
      c.m[i][j] = 0;
      for (int k = 0; k < w; k++)
        c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % mod;
    }
  return c;
}
matrix pow(matrix a, int k) {
  matrix ret = I;
  for (; k; k >>= 1, a = mul(a, a))
    if (k & 1) ret = mul(ret, a);
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  w = n * m;
  scanf("%d", &q);
  int lastt = 1;
  matrix trans;
  for (int i = 0; i < w; i++) I.m[i][i] = 1;
  A = I;
  for (int i = 1; i <= q; i++) {
    scanf("%d%d%d%d", &type, &x, &y, &t);
    x--;
    y--;
    matrix b;
    for (int i = 0; i < w; i++)
      for (int j = 0; j < w; j++) b.m[i][j] = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (!cat[i][j]) {
          for (int k = 0; k < 5; k++) {
            int dx = i + dir[k][0];
            int dy = j + dir[k][1];
            if (dx >= 0 && dx < n && dy >= 0 && dy < m && !cat[dx][dy])
              b.m[dx * m + dy][i * m + j] = 1;
          }
        }
    A = mul(A, pow(b, t - lastt));
    if (type == 1)
      printf("%lld\n", A.m[0][x * m + y]);
    else if (type == 2) {
      cat[x][y] = 1;
      trans = I;
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          if (cat[i][j]) trans.m[i * m + j][i * m + j] = 0;
      A = mul(A, trans);
    } else
      cat[x][y] = 0;
    lastt = t;
  }
}
