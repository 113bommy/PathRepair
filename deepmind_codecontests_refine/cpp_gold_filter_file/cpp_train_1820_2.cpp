#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1510;
const long long MOD = 1e9 + 7;
inline long long in() {
  long long x = 0, flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  return x * flag;
}
long long n, m;
struct Matrix {
  int R, C;
  long long val[110][110];
  Matrix() {}
  Matrix(int _R, int _C) {
    R = _R, C = _C;
    memset(val, 0, sizeof val);
  }
  Matrix(int _R, int _C, int flag) {
    R = _R, C = _C;
    memset(val, 0, sizeof val);
    for (int i = 1; i <= 101; i++) val[i][i] = 1LL;
  }
  Matrix operator*(const Matrix b) const {
    Matrix ret(R, b.C);
    for (int i = 1; i <= R; i++)
      for (int j = 1; j <= b.C; j++)
        for (int k = 1; k <= C; k++)
          (ret.val[i][j] += val[i][k] * b.val[k][j]) %= MOD;
    return ret;
  }
  void print() {
    puts("---");
    for (int i = 1; i <= R; i++, puts(""))
      for (int j = 1; j <= C; printf("%lld", val[i][j]), j++)
        ;
  }
} Dp, Tr;
Matrix fpow(Matrix A, long long B) {
  if (!B) return A;
  Matrix ret(A.R, A.C, 1);
  while (B) {
    if (B % 2 == 1)
      ret = A * ret, B--;
    else
      A = A * A, B /= 2;
  }
  return ret;
}
long long ans = 1;
long long cnt[100010];
int main() {
  n = in();
  m = in();
  for (int i = 1; i <= n; i++) cnt[in()]++;
  Dp.val[100][1] = Dp.val[101][1] = 1LL;
  long long d = min(m, 100 * 1ll);
  d = 100;
  Dp.R = d + 1, Dp.C = 1;
  Tr.R = d + 1, Tr.C = d + 1;
  for (int i = 1; i < d; i++) Tr.val[i][i + 1] = 1LL;
  for (int i = 1; i <= d; i++) {
    Tr.val[d][d - i + 1] = Tr.val[d + 1][d - i + 1] = cnt[i];
  }
  Tr.val[d + 1][d + 1] = 1LL;
  Tr = fpow(Tr, m);
  if (m) Dp = Tr * Dp;
  printf("%lld\n", Dp.val[101][1]);
  return 0;
}
