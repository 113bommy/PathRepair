#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int SIZE = 1e6 + 10;
int n;
long long a[66][111], A[66][111][111], K, d[111];
bool f(long long x) {
  int v = 0;
  while (x) {
    v += x & 1;
    x >>= 1;
  }
  return v % 3 == 0;
}
int main() {
  cin >> n >> K;
  for (int i = 0; i < (n); ++i) cin >> d[i], a[0][i] = 1;
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (n); ++j) {
      if (f(d[i] ^ d[j])) A[0][i][j] = 1;
    }
  int lv = 0;
  while (K) {
    if (K & 1) {
      for (int i = 0; i < (n); ++i)
        for (int j = 0; j < (n); ++j)
          a[lv + 1][i] = (a[lv + 1][i] + A[lv][i][j] * a[lv][j]) % MOD;
    } else
      for (int i = 0; i < (n); ++i) a[lv + 1][i] = a[lv][i];
    for (int i = 0; i < (n); ++i)
      for (int j = 0; j < (n); ++j)
        for (int k = 0; k < (n); ++k)
          A[lv + 1][i][k] = (A[lv + 1][i][k] + A[lv][i][j] * A[lv][j][k]) % MOD;
    K >>= 1;
    lv++;
  }
  long long an = 0;
  for (int i = 0; i < (n); ++i) an += a[lv][i];
  return 0 * printf("%I64d", an % MOD);
}
