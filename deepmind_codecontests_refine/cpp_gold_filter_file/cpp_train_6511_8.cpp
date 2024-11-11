#include <bits/stdc++.h>
using namespace std;
long long inputArr[101], arrSize, seqSize;
struct matrix {
  long long m[101][101];
  matrix() { memset(m, 0, sizeof(m)); }
  matrix operator*(matrix b) {
    matrix c = matrix();
    for (long long i = 0; i < 101; ++i) {
      for (long long j = 0; j < 101; ++j) {
        for (long long k = 0; k < 101; ++k) {
          c.m[i][j] =
              (c.m[i][j] % 1000000007 + m[i][k] * b.m[k][j] % 1000000007) %
              1000000007;
        }
      }
    }
    return c;
  }
} dp_z, dp_g, unit;
matrix modPow(matrix m, long long n) {
  if (n == 0) {
    return unit;
  }
  matrix half = modPow(m, n / 2);
  matrix out = half * half;
  if (n % 2) {
    out = out * m;
  }
  return out;
}
long long ans = 0;
signed main(void) {
  for (long long i = 0; i < 101; ++i) {
    unit.m[i][i] = 1;
  }
  cin >> arrSize >> seqSize;
  for (long long i = 0; i < arrSize; ++i) {
    cin >> inputArr[i];
  }
  for (long long i = 0; i < arrSize; ++i) {
    for (long long j = 0; j < arrSize; ++j) {
      if (__builtin_popcountll(inputArr[i] ^ inputArr[j]) % 3 == 0) {
        dp_g.m[i][j] = 1;
      }
    }
  }
  for (long long j = 0; j < arrSize; ++j) {
    dp_z.m[0][j] = 1;
  }
  dp_z = dp_z * modPow(dp_g, seqSize - 1);
  for (long long j = 0; j <= arrSize; ++j) {
    ans = (ans + dp_z.m[0][j]);
  }
  cout << ans % 1000000007;
  return 0;
}
