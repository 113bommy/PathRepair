#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const long long INF = (long long)5e18;
const int MOD = 1e9 + 7;
int _abs(int x) { return x < 0 ? -x : x; }
int add(int x, int y) {
  x += y;
  return x >= MOD ? x - MOD : x;
}
int sub(int x, int y) {
  x -= y;
  return x < 0 ? x + MOD : x;
}
void Add(int &x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
void Sub(int &x, int y) {
  x -= y;
  if (x < 0) x += MOD;
}
void Mul(int &x, int y) { x = (long long)(x) * (y) % MOD; }
int qpow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = (long long)(ret) * (x) % MOD;
    x = (long long)(x) * (x) % MOD;
    y >>= 1;
  }
  return ret;
}
void checkmin(int &x, int y) {
  if (x > y) x = y;
}
void checkmax(int &x, int y) {
  if (x < y) x = y;
}
void checkmin(long long &x, long long y) {
  if (x > y) x = y;
}
void checkmax(long long &x, long long y) {
  if (x < y) x = y;
}
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return x * f;
}
const int N = 3000005;
int fac[N], ifac[N], inv[N];
int dp[N][4], n, q;
int main() {
  int n = 3000001;
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (long long)(fac[i - 1]) * (i) % MOD;
  ifac[n] = qpow(fac[n], MOD - 2);
  for (int i = n - 1; i >= 0; i--)
    ifac[i] = (long long)(ifac[i + 1]) * (i + 1) % MOD;
  inv[1] = 1;
  for (int i = 2; i <= n; i++)
    inv[i] = (long long)(MOD - MOD / i) * (inv[MOD % i]) % MOD;
  n = read();
  q = read();
  dp[1][1] = (long long)(inv[2]) * ((long long)(3 * n - 1) * (n) % MOD) % MOD;
  dp[1][2] = (long long)(inv[2]) * ((long long)(3 * n + 1) * (n) % MOD) % MOD;
  dp[1][3] = (long long)(inv[2]) * ((long long)(3 * n + 3) * (n) % MOD) % MOD;
  for (int i = 2; i <= n * 3; i++) {
    int tmp = (long long)(fac[3 * n + 1]) *
              ((long long)(ifac[3 * n - i]) * (inv[i + 1]) % MOD) % MOD;
    int tmp1 = (long long)(i) * (dp[i - 1][1]) % MOD,
        tmp2 = (long long)(i) * (dp[i - 1][2]) % MOD;
    dp[i][1] =
        (long long)(sub(tmp, add(tmp1, add(tmp1, tmp2)))) * (inv[3]) % MOD;
    dp[i][2] = add(dp[i][1], tmp1);
    dp[i][3] = add(dp[i][2], tmp2);
  }
  for (int i = 1; i <= n * 3; i++) Mul(dp[i][3], ifac[i]);
  while (q--) {
    printf("%d\n", dp[read()][3]);
  }
  return 0;
}
