#include <bits/stdc++.h>
using namespace std;
long long MOD;
struct mat {
  long long a[30][30];
  int r, c;
  mat operator*(const mat &b) const {
    mat ret;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < b.c; j++) {
        ret.a[i][j] = 0;
        for (int k = 0; k < c; k++)
          ret.a[i][j] += a[i][k] * b.a[k][j], ret.a[i][j] %= MOD;
      }
    }
    ret.r = r;
    ret.c = b.c;
    return ret;
  }
  void init_unit(int x) {
    r = c = x;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (i == j)
          a[i][j] = 1;
        else
          a[i][j] = 0;
      }
    }
  }
} unit;
mat qmod(mat p, long long n) {
  unit.init_unit(p.c);
  mat ans = unit;
  while (n) {
    if (n & 1) ans = p * ans;
    p = p * p;
    n >>= 1;
  }
  return ans;
}
long long n, sx, sy, dx, dy, t;
int main() {
  scanf("%lld%lld%lld%lld%lld%lld", &n, &sx, &sy, &dx, &dy, &t);
  if (t == 0) {
    printf("%lld %lld\n", &sx, &sy);
    return 0;
  }
  MOD = n;
  mat A;
  A.r = A.c = 6;
  A.a[0][0] = 2;
  A.a[0][1] = 1;
  A.a[0][2] = 1;
  A.a[0][3] = 0;
  A.a[0][4] = 1;
  A.a[0][5] = 2;
  A.a[1][0] = 1;
  A.a[1][1] = 2;
  A.a[1][2] = 0;
  A.a[1][3] = 1;
  A.a[1][4] = 1;
  A.a[1][5] = 2;
  A.a[2][0] = 1;
  A.a[2][1] = 1;
  A.a[2][2] = 1;
  A.a[2][3] = 0;
  A.a[2][4] = 1;
  A.a[2][5] = 2;
  A.a[3][0] = 1;
  A.a[3][1] = 1;
  A.a[3][2] = 0;
  A.a[3][3] = 1;
  A.a[3][4] = 1;
  A.a[3][5] = 2;
  A.a[4][0] = 0;
  A.a[4][1] = 0;
  A.a[4][2] = 0;
  A.a[4][3] = 0;
  A.a[4][4] = 1;
  A.a[4][5] = 1;
  A.a[5][0] = 0;
  A.a[5][1] = 0;
  A.a[5][2] = 0;
  A.a[5][3] = 0;
  A.a[5][4] = 0;
  A.a[5][5] = 1;
  A = qmod(A, t);
  long long b[15];
  b[0] = sx - 1;
  b[1] = sy - 1;
  b[2] = dx;
  b[3] = dy;
  b[4] = 0;
  b[5] = 1;
  long long ansx = 0, ansy = 0;
  for (int i = 0; i < 6; i++)
    ansx = (ansx + A.a[0][i] * b[i] % MOD + MOD) % MOD;
  for (int i = 0; i < 6; i++)
    ansy = (ansy + A.a[1][i] * b[i] % MOD + MOD) % MOD;
  printf("%lld %lld\n", ansx + 1ll, ansy + 1ll);
  return 0;
}
