#include <bits/stdc++.h>
using namespace std;
long long f[1 << 10], M = 1000000;
long long l, r, k;
class Matrix {
 public:
  long long a[3][3];
  Matrix(int fib = 0) {
    memset(a, 0, sizeof(a));
    if (fib) a[1][2] = a[2][1] = a[2][2] = 1;
  }
  Matrix operator*(const Matrix &v) {
    Matrix ret;
    for (int i = 1; i <= 2; ++i)
      for (int j = 1; j <= 2; ++j)
        for (int k = 1; k <= 2; ++k)
          ret.a[i][k] = (ret.a[i][k] + a[i][j] * v.a[j][k]) % M;
    return ret;
  }
  void print() { cout << a[1][2] << endl; }
};
Matrix one(1);
long long solve(long long l, long long r, long long v) {
  l = (l - 1) / v + 1;
  r = r / v;
  return r - l + 1;
}
Matrix fib(long long u) {
  if (u == 1) return one;
  Matrix cache = fib(u / 2);
  cache = cache * cache;
  if (u % 2) cache = cache * one;
  return cache;
}
int main() {
  cin >> M >> l >> r >> k;
  long long ans = 1;
  if (k >= 1000000) {
    ans = (r - l + 1) / (k - 1) + 2;
    while (solve(l, r, ans) < k) --ans;
  } else {
    for (int i = 1; i + k - 1 <= 1000000; ++i) {
      long long tl = (l - 1) / i + 1, tr = r / (i + k - 1);
      if (tl <= tr) ans = max(ans, tr);
    }
  }
  fib(ans).print();
  return 0;
}
