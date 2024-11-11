#include <bits/stdc++.h>
using namespace std;
long long mod;
long long n, k, l;
void at(long long& x) { x %= mod; }
struct Matrix {
  int n, m;
  long long arr[2][2];
  void clear() {
    n = m = 0;
    memset(arr, 0, sizeof(arr));
  }
  friend Matrix operator*(const Matrix& a, const Matrix& b) {
    Matrix tmp;
    tmp.clear();
    tmp.n = a.n, tmp.m = b.m;
    assert(a.m == b.n);
    for (int i = 0; i < a.n; ++i)
      for (int j = 0; j < b.m; ++j)
        for (int k = 0; k < a.m; ++k) {
          tmp.arr[i][j] += a.arr[i][k] * b.arr[k][j];
          at(tmp.arr[i][j]);
        }
    return tmp;
  }
  void init() {
    for (int i = 0; i < n; ++i) arr[i][i] = 1;
  }
};
Matrix pow_mod(Matrix a, long long k) {
  Matrix tmp;
  tmp.clear();
  tmp.n = a.n, tmp.m = a.m;
  tmp.init();
  while (k) {
    if (k & 1) tmp = tmp * a;
    a = a * a;
    k >>= 1;
  }
  return tmp;
}
long long pow_mod(long long a, long long k) {
  long long tmp = 1;
  while (k) {
    if (k & 1) {
      tmp = tmp * a;
      at(tmp);
    }
    a = a * a;
    at(a);
    k >>= 1;
  }
  return tmp;
}
int main() {
  while (scanf("%I64d %I64d %I64d %I64d", &n, &k, &l, &mod) == 4) {
    if (l < 63 && k >= ((long long)1 << l) || mod == 1) {
      printf("0\n");
      continue;
    }
    Matrix tmp, ans;
    tmp.clear();
    tmp.n = tmp.m = 2;
    tmp.arr[0][0] = 1, tmp.arr[0][1] = 1;
    tmp.arr[1][0] = 1, tmp.arr[1][1] = 0;
    ans.clear();
    ans.n = 2, ans.m = 1;
    ans.arr[0][0] = 3;
    ans.arr[1][0] = 2;
    tmp = pow_mod(tmp, n - 2);
    ans = tmp * ans;
    long long s1 = ans.arr[0][0];
    long long s2 = ((pow_mod(2, n) - s1) % mod + mod) % mod;
    long long all = (k & 1) == 0 ? s1 : s2;
    all %= mod;
    for (long long i = 1; i < l; ++i) {
      all *= ((k >> i) & 1) == 0 ? s1 : s2;
      all %= mod;
    }
    if (l == 0) {
      if (k == 0)
        printf("1\n");
      else
        printf("0\n");
      continue;
    }
    printf("%I64d\n", all);
  }
}
