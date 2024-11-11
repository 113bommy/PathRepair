#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e5 + 5;
const double eps = 1e-7;
const long long mod = 998244353;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + (c - '0');
    c = getchar();
  }
  return x * f;
}
long long C[505][505];
long long F[505][505];
inline long long quickpow(long long x, long long tim) {
  long long res = 1;
  while (tim) {
    if (tim & 1) res = res * x % mod;
    x = x * x % mod;
    tim >>= 1;
  }
  return res;
}
inline long long dfs(long long x, long long y) {
  long long sum = 0;
  if (x == 0) return 1;
  if (x == 1) return 0;
  if (F[x][y] >= 0) return F[x][y];
  if (y < x) return quickpow(y, x);
  for (long long i = 0; i <= x; i++)
    sum = (sum +
           (dfs(x - i, y - x + 1) * C[x][i] % mod * quickpow(x - 1, i) % mod)) %
          mod;
  return F[x][y] = sum;
}
int main() {
  long long n = read(), k = read();
  memset(F, -1, sizeof(F));
  for (long long i = 0; i <= 500; i++) C[i][0] = 1;
  for (long long i = 1; i <= 500; i++) {
    for (long long j = 1; j <= 500; j++)
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  }
  cout << dfs(n, k) << endl;
}
