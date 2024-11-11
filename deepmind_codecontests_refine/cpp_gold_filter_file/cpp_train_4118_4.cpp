#include <bits/stdc++.h>
using namespace std;
struct Matrix {
  int A[2][2];
  Matrix() { memset(A, 0, sizeof A); }
  Matrix operator*(const Matrix &_) const {
    Matrix tmp;
    tmp.A[0][1] =
        ((long long)A[0][0] * _.A[0][1] + (long long)A[0][1] * _.A[1][1]) %
        1000000007;
    tmp.A[1][1] =
        ((long long)A[1][0] * _.A[0][1] + (long long)A[1][1] * _.A[1][1]) %
        1000000007;
    tmp.A[0][0] =
        ((long long)A[0][0] * _.A[0][0] + (long long)A[0][1] * _.A[1][0]) %
        1000000007;
    tmp.A[1][0] =
        ((long long)A[1][0] * _.A[0][0] + (long long)A[1][1] * _.A[1][0]) %
        1000000007;
    return tmp;
  }
  Matrix Pow(long long n, Matrix x) {
    Matrix res = *this;
    for (; n; n >>= 1, x = x * x)
      if (n & 1) res = res * x;
    return res;
  }
};
long long fast(long long x, long long n) {
  long long res = 1;
  for (; n; n >>= 1, x = 1ll * x * x % 1000000007)
    if (n & 1) res = 1ll * res * x % 1000000007;
  return res;
}
int main() {
  int n;
  long long son = 1, mom = 2;
  scanf("%d", &n);
  Matrix op, ans;
  ans.A[0][0] = 0;
  ans.A[0][1] = 1;
  op.A[0][1] = 2;
  op.A[0][0] = 1;
  op.A[1][0] = 1;
  for (int i = (1), i_END = (n); i <= i_END; i++) {
    long long x;
    scanf("%lld", &x);
    mom = fast(mom, x);
    ans = ans.Pow(x - 1, op);
    op = op.Pow(x - 1, op);
  };
  son = ans.A[0][0];
  printf("%lld/%lld\n", son, 1ll * mom * fast(2, 1000000007 - 2) % 1000000007);
  return 0;
}
