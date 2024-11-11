#include <bits/stdc++.h>
using namespace std;
const long long M = 1e13;
long long n, ans = 2e18;
inline long long mul(long long x, long long y) {
  long long re = 1;
  for (; y; y >>= 1, (x += x) %= M)
    if (y & 1) (re += x) %= M;
  return re;
}
struct Mat {
  long long z[2][2];
  inline Mat operator*(Mat A) {
    Mat R = {0, 0, 0, 0};
    for (int i = 0; i < 2; ++i)
      for (int k = 0; k < 2; ++k)
        for (int j = 0; j < 2; ++j) (R.z[i][j] += mul(z[i][k], A.z[k][j])) %= M;
    return R;
  }
};
inline Mat qpow(Mat B, long long k) {
  Mat R = {1, 0, 0, 1};
  for (; k; k >>= 1, B = B * B)
    if (k & 1) R = R * B;
  return R;
}
inline long long kth(long long k) { return qpow((Mat){1, 1, 1, 0}, k).z[0][1]; }
inline bool chk_kth(long long m, long long k) { return n % m == kth(k) % m; }
void dfs(long long x, long long m, long long p) {
  if (kth(x) == n)
    ans = min(ans, x);
  else {
    for (long long i = 0; i < 9; ++i) {
      if (chk_kth(m, i * p + x)) dfs(i * p + x, m * 10, p * 10);
    }
  }
}
int main() {
  cin >> n;
  for (long long i = 1; i <= 1500; ++i) {
    if (chk_kth(1000, i)) dfs(i, 10000, 1500);
  }
  cout << (ans > 1e18 ? -1 : ans);
}
