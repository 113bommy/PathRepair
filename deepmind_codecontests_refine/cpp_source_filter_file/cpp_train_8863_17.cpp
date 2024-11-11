#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 998244353;
const double PI = acos(-1);
const double eps = 1e-7;
long long read() {
  long long n = 0;
  char a = getchar();
  bool flag = 0;
  while (a > '9' || a < '0') {
    if (a == '-') flag = 1;
    a = getchar();
  }
  while (a <= '9' && a >= '0') {
    n = n * 10 + a - '0', a = getchar();
  }
  if (flag) n = -n;
  return n;
}
long long ksm(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = a * ans % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
int f[4010][2010][2];
int getfac(int x) {
  int ans = 1;
  for (int i = 2; i <= x; i++) ans = 1ll * ans * i % mod;
  return ans;
}
int main() {
  int n = read(), m = read(), l = read();
  f[0][0][0] = 1;
  for (int i = 0; i < 2 * n + 1; i++) {
    for (int j = 0; j <= i; j++) {
      if (j >= m) (f[i + 1][j][1] += f[i][j][0]) %= mod;
      for (int k = 0; k < 2; k++) {
        (f[i + 1][j + 1][k] += f[i][j][k]) %= mod;
        if (j) (f[i + 1][j - 1][k] += 1ll * f[i][j][k] * j % mod) %= mod;
      }
    }
  }
  int ans = f[2 * n + 1][0][1];
  ans = 1ll * ans * getfac(n) % mod * ksm(2, n) % mod *
        ksm(getfac(2 * n + 1), mod - 2) % mod;
  ans = 1ll * ans * l % mod;
  cout << ans << endl;
}
