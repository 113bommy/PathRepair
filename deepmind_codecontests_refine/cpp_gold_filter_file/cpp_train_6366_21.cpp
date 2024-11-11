#include <bits/stdc++.h>
using namespace std;
template <typename T>
T read1() {
  T t = 0;
  char k;
  bool vis = 0;
  do (k = getchar()) == '-' && (vis = 1);
  while ('0' > k || k > '9');
  while ('0' <= k && k <= '9')
    t = (t << 3) + (t << 1) + (k ^ '0'), k = getchar();
  return vis ? -t : t;
}
const int n = read1<long long>(), k = read1<long long>(),
          m = read1<long long>(), s = 1 << m;
const unsigned M = k + 1 << m;
struct Mat {
  int f[208][208], M;
  Mat(const unsigned n) : f() { M = n; }
  int* operator[](unsigned x) { return f[x]; }
  Mat operator*(Mat b) {
    Mat x(M);
    for (int i = 0; i < M; ++i)
      for (int j = 0; j < M; ++j)
        if (f[i][j])
          for (int k = 0; k < M; ++k)
            x[i][k] = (x[i][k] + 1ll * f[i][j] * b[j][k]) % 1000000007;
    return x;
  }
  Mat& operator*=(Mat b) { return *this = *this * b; }
  void set() {
    for (int i = 0; i < M; ++i) f[i][i] = 1;
  }
};
Mat To(M), Fi(M);
int Hash(int x, int z) { return x << m | z; }
Mat qkpow(Mat x, int n) {
  Mat t(M);
  t.set();
  for (; n; n >>= 1, x *= x)
    if (n & 1) t *= x;
  return t;
}
int main() {
  for (int i = 0; i < s; ++i)
    for (int j = 0; j <= k; ++j) {
      To[Hash(j, i)][Hash(j, (i << 1) & s - 1)] = 1;
      if (j != k)
        To[Hash(j, i)][Hash(j + 1, (i << 1 | 1) & s - 1)] =
            __builtin_popcount(i) + 1;
    }
  Fi[0][0] = 1;
  Fi *= qkpow(To, n);
  int ans = 0;
  for (int i = 0; i < s; ++i) ans = (ans + Fi[0][Hash(k, i)]) % 1000000007;
  cout << ans;
  return 0;
}
