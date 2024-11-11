#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int maxm = 2;
const int N = 20010;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 9;
long long n, m;
long long k;
int f[maxn];
struct Matrix {
  long long mat[2][2];
};
Matrix a;
Matrix Matmul(Matrix x, Matrix y) {
  int i, j;
  int g;
  Matrix C;
  for (i = 0; i < maxm; i++) {
    for (j = 0; j < maxm; j++) {
      C.mat[i][j] = 0;
      for (g = 0; g < maxm; g++) {
        C.mat[i][j] += x.mat[i][g] * y.mat[g][j];
        C.mat[i][j] %= mod;
      }
    }
  }
  return C;
}
Matrix Matpow(Matrix gg, long long t) {
  Matrix b;
  b.mat[0][0] = 2 * k;
  b.mat[0][1] = k;
  b.mat[1][0] = 0;
  b.mat[1][1] = 0;
  while (t > 0) {
    if (t & 1) b = Matmul(b, gg);
    gg = Matmul(gg, gg);
    t >>= 1;
  }
  return b;
}
int main() {
  int i, j;
  scanf("%I64d%I64d%I64d", &n, &m, &k);
  long long ans = 0;
  if (k > m) {
    printf("%I64d\n", m);
    return 0;
  }
  long long cnt = n - m;
  long long temp = m / (k - 1);
  long long gg = min(cnt + 1, temp);
  ans += gg * (k - 1);
  ans %= mod;
  long long ff = 0;
  temp = m - ans;
  ff = temp;
  temp /= k;
  long long pp = 0;
  f[0] = 0;
  f[1] = 2 * k;
  a.mat[0][0] = 2;
  a.mat[0][1] = 0;
  a.mat[1][0] = 2;
  a.mat[1][1] = 1;
  if (temp > 1) {
    a = Matpow(a, temp - 1);
    pp = a.mat[0][0];
  } else
    pp = f[temp];
  if ((ff % k) != 0 && (n - m) < gg) {
    ff %= k;
    pp = (pp + k) * 2;
    pp %= mod;
    ans -= k - ff;
  } else if (ff % k != 0 && (n - m) >= gg) {
    ff %= k;
    pp = ff;
  }
  printf("%I64d\n", (pp + ans) % mod);
  return 0;
}
