#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n;
long long c[105][105], a[105][105], A[105][105];
inline long long qpow(long long x, long long y, long long ans = 1) {
  for (; y; y >>= 1, x = x * x % mod)
    if (y & 1) ans = ans * x % mod;
  return ans;
}
inline long long Matrix_Tree(int n) {
  long long ans = 1;
  for (int i = 1; i <= n; ++i) {
    long long inv = qpow(a[i][i], mod - 2);
    ans = ans * a[i][i] % mod;
    for (int j = i + 1; j <= n; ++j)
      for (int k = n; k >= i; --k)
        a[j][k] = (a[j][k] - a[i][k] * a[j][i] % mod * inv) % mod;
  }
  return ans;
}
inline void Gauss(int n) {
  for (int i = 1, s; i <= n; ++i) {
    for (int j = i; j <= n; ++j)
      if (c[j][i]) {
        s = j;
        break;
      }
    swap(c[s], c[i]);
    long long inv = qpow(c[i][i], mod - 2);
    for (int j = 1; j <= n + 1; ++j) c[i][j] = c[i][j] * inv % mod;
    for (int j = 1; j <= n; ++j)
      if (j ^ i)
        for (int k = n + 1; k >= i; --k)
          c[j][k] = (c[j][k] - c[i][k] * c[j][i]) % mod;
  }
}
int main() {
  cin >> n;
  for (int i = 1, x, y; i < n; ++i)
    cin >> x >> y, A[x][x]++, A[y][y]++, A[x][y]--, A[y][x]--;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1, pw = 1; j <= n; ++j, pw = pw * i % mod) c[i][j] = pw;
    memset(a, 0, sizeof(a));
    for (int j = 1; j <= n; ++j)
      for (int k = 1; k <= n; ++k)
        if (j ^ k)
          if (!A[j][k]) a[j][k]--;
    for (int j = 1; j <= n; ++j)
      for (int k = 1; k <= n; ++k)
        if (j ^ k) a[j][k] += A[j][k] * i;
    for (int j = 1; j <= n; ++j) a[j][j] = (n - 1 - A[j][j]) + A[j][j] * i;
    c[i][n + 1] = Matrix_Tree(n - 1);
  }
  Gauss(n);
  for (int i = 1; i <= n; ++i) printf("%lld ", (c[i][n + 1] % mod + mod) % mod);
  return 0;
}
