#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7ll;
long long n, c, ans = 1, num;
struct matrix {
  long long n, m, mat[6][6];
  matrix operator*(const matrix b) const {
    matrix res = {n, b.m};
    memset(res.mat, 0, sizeof(res.mat));
    for (long long k = 1; k <= m; k++)
      for (long long i = 1; i <= n; i++)
        for (long long j = 1; j <= b.m; j++)
          res.mat[i][j] = (res.mat[i][j] + mat[i][k] * b.mat[k][j]) % M;
    return res;
  }
} f, st;
long long ksm(long long x, long long w) {
  long long s = 1;
  while (w) {
    if (w & 1) s = s * x % M;
    x = x * x % M;
    w >>= 1;
  }
  return s;
}
matrix ksm(matrix x, long long w) {
  matrix s = {5, 5};
  memset(s.mat, 0, sizeof(s.mat));
  s.mat[1][1] = s.mat[2][2] = s.mat[3][3] = s.mat[4][4] = s.mat[5][5] = 1;
  while (w) {
    if (w & 1) s = s * x;
    x = x * x;
    w >>= 1;
  }
  return s;
}
signed main() {
  cin >> n;
  f.n = f.m = 3;
  f.mat[1][1] = 1, f.mat[1][2] = 1, f.mat[1][3] = 1;
  f.mat[2][1] = 1, f.mat[2][2] = 0, f.mat[2][3] = 0;
  f.mat[3][1] = 0, f.mat[3][2] = 1, f.mat[3][3] = 0;
  st.n = 3, st.m = 1;
  cin >> num;
  st.mat[3][1] = 1;
  st = ksm(f, n - 3) * st;
  ans = ans * ksm(num, st.mat[1][1]) % M;
  st.n = 3, st.m = 1;
  memset(st.mat, 0, sizeof(st.mat));
  cin >> num;
  st.mat[2][1] = 1;
  st = ksm(f, n - 3) * st;
  ans = ans * ksm(num, st.mat[1][1]) % M;
  st.n = 3, st.m = 1;
  memset(st.mat, 0, sizeof(st.mat));
  cin >> num;
  st.mat[1][1] = 1;
  st = ksm(f, n - 3) * st;
  ans = ans * ksm(num, st.mat[1][1]) % M;
  cin >> c;
  st.n = 5, st.m = 1;
  memset(st.mat, 0, sizeof(st.mat));
  st.mat[4][1] = 3, st.mat[5][1] = 1;
  f.n = f.m = 5;
  memset(f.mat, 0, sizeof(f.mat));
  f.mat[1][1] = 1, f.mat[1][2] = 1, f.mat[1][3] = 1, f.mat[1][4] = 2,
  f.mat[1][5] = M - 4;
  f.mat[2][1] = 1, f.mat[2][2] = 0, f.mat[2][3] = 0, f.mat[2][4] = 0,
  f.mat[2][5] = 0;
  f.mat[3][1] = 0, f.mat[3][2] = 1, f.mat[3][3] = 0, f.mat[3][4] = 0,
  f.mat[3][5] = 0;
  f.mat[4][1] = 0, f.mat[4][2] = 0, f.mat[4][3] = 0, f.mat[4][4] = 1,
  f.mat[4][5] = 1;
  f.mat[5][1] = 0, f.mat[5][2] = 0, f.mat[5][3] = 0, f.mat[5][4] = 0,
  f.mat[5][5] = 1;
  st = ksm(f, n - 3) * st;
  ans = ans * ksm(c, st.mat[1][1]) % M;
  cout << ans << endl;
  return 0;
}
