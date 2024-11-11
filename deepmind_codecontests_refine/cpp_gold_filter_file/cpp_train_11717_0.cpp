#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int n;
long long a[maxn];
long long qpow(long long a, int N) {
  long long res = 1;
  while (N) {
    if (N & 1) res = (res * a) % mod;
    a = a * a % mod;
    N >>= 1;
  }
  return res;
}
struct Mat {
  long long m[2][2];
  int n;
  Mat(){};
  void init(int a) {
    n = a;
    memset(m, 0, sizeof(m));
  }
  Mat(int n) { init(n); };
  void setone() {
    for (int i = 0; i < n; ++i) m[i][i] = 1;
  }
  Mat operator*(const Mat& rhs) {
    Mat ret(n);
    for (int k = 0; k < n; ++k)
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          ret.m[i][j] = (ret.m[i][j] + m[i][k] * rhs.m[k][j] % mod + mod) % mod;
    return ret;
  }
};
Mat pow(Mat& x, long long y) {
  Mat b(x.n);
  b.setone();
  while (y) {
    if (y & 1) b = b * x;
    x = x * x;
    y >>= 1;
  }
  return b;
}
int main() {
  scanf("%d", &n);
  Mat A(2), B(2);
  B.m[0][0] = -1, B.m[0][1] = 1, B.m[1][0] = 0, B.m[1][1] = 2;
  A.m[0][0] = 0, A.m[1][0] = 1;
  long long t = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    a[i] %= (mod - 1);
    t *= a[i];
    t %= (mod - 1);
  }
  t += mod - 1;
  t %= (mod - 1);
  B = pow(B, t);
  A = B * A;
  long long inv2 = qpow(2, mod - 2);
  long long ans2 = A.m[1][0] * inv2 % mod;
  long long ans1 = (ans2 - A.m[0][0] + mod) % mod;
  printf("%lld/%lld\n", ans1, ans2);
  return 0;
}
