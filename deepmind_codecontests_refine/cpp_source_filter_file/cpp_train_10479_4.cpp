#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxr = 110;
const int I = 105;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
long long pow(long long a, long long n) {
  long long b = 1;
  while (n) {
    if (n & 1) (b *= a) %= mod;
    n >>= 1;
    (a *= a) %= mod;
  }
  return b;
}
long long R, a[4];
long long f[maxr * maxr][maxr], g[maxr * maxr];
int id[maxr][maxr];
int ct;
long long gauss() {
  for (int i = 0; i < ct; i++) {
    if (!f[i][I]) continue;
    long long inv = pow(f[i][I], mod - 2);
    for (int j = 0; j < I; j++) (f[i][j + I] *= inv) %= mod;
    (g[i] *= inv) %= mod;
    for (int k = i + 1; k <= i + I && k < ct; k++)
      if (f[k][I - k + i]) {
        long long t = (mod - f[k][I - k + i]) % mod;
        for (int j = 0; j < I; j++)
          (f[k][I - k + i + j] += t * f[i][I + j]) %= mod;
        (g[k] += t * g[i]) %= mod;
      }
  }
  for (int i = ct - 1; i >= 0; i--)
    if (f[i][I]) {
      for (int k = i - 1; k > 0 && k >= i - I; k--)
        if (f[k][I + i - k]) (g[k] -= f[k][I + i - k] * g[i]) %= mod;
      if (i == id[R][R]) return g[i];
      if (i < id[R][R]) break;
    }
  return 0;
}
int main() {
  cin >> R >> a[0] >> a[1] >> a[2] >> a[3];
  long long p = pow(a[0] + a[1] + a[2] + a[3], mod - 2);
  for (int i = 0; i <= 3; i++) (a[i] *= p) %= mod;
  for (int i = -R; i <= R; i++)
    for (int j = -R; j <= R; j++)
      if (i * i + j * j <= R * R) id[i + R][j + R] = ct++;
  for (int i = -R; i <= R; i++)
    for (int j = -R; j <= R; j++)
      if (i * i + j * j <= R * R) {
        int d = id[i + R][j + R];
        f[d][I] = 1;
        g[d] = 1;
        for (int k = 0; k <= 3; k++) {
          int x = i + dx[k], y = j + dy[k];
          if (x * x + y * y <= R * R)
            f[d][I - d + id[x + R][y + R]] = mod - a[k];
        }
      }
  long long ans = gauss();
  (ans += mod) %= mod;
  cout << ans << endl;
  return 0;
}
