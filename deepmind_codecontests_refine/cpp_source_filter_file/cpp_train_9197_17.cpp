#include <bits/stdc++.h>
int xx[] = {1, 1, 0, -1, -1, -1, 0, 1}, yy[] = {0, 1, 1, 1, 0, -1, -1, -1};
using namespace std;
struct matrix {
  long long mat[55][55];
};
matrix base;
matrix mat_mul(matrix a, matrix b, int lim) {
  int i, j, k;
  matrix ret;
  for (i = 1; i <= lim; i++) {
    for (j = 1; j <= lim; j++) {
      ret.mat[i][j] = 0;
      for (k = 1; k <= lim; k++) {
        ret.mat[i][j] =
            (ret.mat[i][j] + (a.mat[i][k] * b.mat[k][j])) % 1000000007;
      }
    }
  }
  return ret;
}
matrix mat_pwr(long long p, long long m) {
  matrix res = base;
  p--;
  matrix x = base;
  while (p) {
    if (p & 1) res = mat_mul(res, x, m);
    x = mat_mul(x, x, m);
    p >>= 1;
  }
  return res;
}
int main() {
  long long n, m, k;
  while (cin >> n >> m >> k) {
    long long i, j, now, x, y;
    char a, b;
    for (i = 1; i <= m; i++) {
      for (j = 1; j <= m; j++) base.mat[i][j] = 1;
    }
    for (i = 0; i < k; i++) {
      scanf(" %c%c", &a, &b);
      if (a >= 'a' && a <= 'z')
        x = a - 'a' + 1;
      else
        x = a - 'A' + 1;
      if (b >= 'a' && b <= 'z')
        y = b - 'a' + 1;
      else
        y = b - 'A' + 1;
      base.mat[x][y] = 0;
    }
    long long cnt = 0;
    if (n == 1)
      cnt = m;
    else {
      matrix ans = mat_pwr(n - 1, m);
      for (i = 1; i <= m; i++)
        for (j = 1; j <= m; j++) cnt = (cnt + ans.mat[i][j]) % 1000000007;
    }
    cout << cnt << endl;
  }
  return 0;
}
