#include <bits/stdc++.h>
using namespace std;
int P;
int add(int a, int b) {
  if ((a += b) >= P) a -= P;
  return a;
}
int sub(int a, int b) {
  if ((a -= b) < 0) a += P;
  return a;
}
int mul(int a, int b) { return 1ll * a * b % P; }
int kpow(int a, int b) {
  int r = 1;
  for (; b; b >>= 1, a = mul(a, a)) {
    if (b & 1) r = mul(r, a);
  }
  return r;
}
const int N = 2;
long long l, r, L, R, mid, k, pos, cnt, x;
struct Mat {
  long long r[N][N];
  Mat() { memset(r, 0, sizeof(r)); }
  Mat operator*(Mat b) {
    Mat c;
    for (int i = (0); i < (N); i++)
      for (int j = (0); j < (N); j++)
        for (int k = (0); k < (N); k++)
          c.r[i][j] = add(c.r[i][j], mul(r[i][k], b.r[k][j]));
    return c;
  }
};
Mat kpow(Mat a, long long k) {
  Mat b;
  for (int i = (0); i < (N); i++) b.r[i][i] = 1;
  for (; k; k >>= 1, a = a * a)
    if (k & 1) b = b * a;
  return b;
}
bool check(long long mid) { return R / mid - (L - 1) / mid >= k; }
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> P >> L >> R >> k;
  for (long long i = 1; i <= R; i = r + 1) {
    r = R / (R / i);
    cnt = R / i;
    if (cnt >= k) {
      cnt -= k;
      x = (L - 1) / (cnt + 1) + 1;
      if (x <= r) pos = r;
    }
  }
  Mat a;
  a.r[0][0] = a.r[0][1] = 1;
  a.r[1][0] = 1;
  if (pos <= 2)
    cout << 1;
  else {
    a = kpow(a, pos - 2);
    cout << add(a.r[0][0], a.r[0][1]);
  }
  return 0;
}
