#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;
const int mod = 1000000007;
long long int fastpow(long long int x, long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) {
      res = (res * x);
      y--;
    }
    x = (x * x);
    y /= 2;
  }
  return res;
}
int main() {
  long long int t, n, m, i, j, k, l, x, y, z;
  scanf("%lld %lld", &n, &m);
  long long int mat[n][m];
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j) scanf("%lld", &mat[i][j]);
  long long int ans = 0;
  for (i = 0; i < n; ++i) {
    long long int c0 = 0, c1 = 0;
    for (j = 0; j < m; ++j) {
      if (mat[i][j] == 0)
        c0++;
      else if (mat[i][j] == 1)
        c1++;
    }
    ans += fastpow(2, c0) - 1;
    ans += fastpow(2, c1) - 1;
  }
  for (j = 0; j < m; ++j) {
    long long int c0 = 0, c1 = 0;
    for (i = 0; i < n; ++i) {
      if (mat[i][j] == 0)
        c0++;
      else if (mat[i][j] == 1)
        c1++;
    }
    ans += fastpow(2, c0) - 1 - c0;
    ans += fastpow(2, c1) - 1 - c1;
  }
  printf("%lld\n", ans);
  return 0;
}
