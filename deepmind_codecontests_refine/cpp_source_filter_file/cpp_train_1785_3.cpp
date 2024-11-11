#include <bits/stdc++.h>
using namespace std;
long long ff[2005][2005];
const int MX = 1000005;
const int M = 1000000007;
long long inv[MX], f[MX], g[MX];
void init() {
  int i;
  inv[1] = 1;
  for (i = 2; i < MX; i++) inv[i] = inv[M % i] * (M - M / i) % M;
  f[0] = g[0] = 1;
  for (i = 1; i < MX; i++) {
    f[i] = f[i - 1] * i % M;
    g[i] = g[i - 1] * inv[i] % M;
  }
}
inline long long C(int n, int k) {
  if (k < 0 || k > n) return 0;
  return f[n] * g[k] % M * g[n - k] % M;
}
long long powmod(int n, int m) {
  long long tmp = n, ans = 1;
  while (m) {
    if (m & 1) ans = ans * tmp % 1000000007;
    m >>= 1;
    tmp = tmp * tmp % 1000000007;
  }
  return ans;
}
void calc() {
  init();
  ff[1][1] = 1;
  for (int i = 2; i < 2005; i++) {
    for (int j = 1; j < 2005; j++) {
      ff[i][j] = j * ff[i - 1][j] + j * ff[i - 1][j - 1];
      ff[i][j] %= 1000000007;
    }
  }
}
long long ans;
int main() {
  calc();
  int n, m, k;
  cin >> n >> m >> k;
  if (m == 1) {
    cout << powmod(n, k) << endl;
    return 0;
  }
  for (int i = 1; i <= min(n, k); i++) {
    for (int j = 0; j <= i; j++) {
      long long tmp = 1;
      if (m - 2) {
        tmp = tmp * (C(k, i) * ff[n][i] % 1000000007) % 1000000007;
        tmp =
            tmp * (powmod(j, n * (m - 2)) * C(i, j) % 1000000007) % 1000000007;
        tmp = tmp * (C(k - i, i - j) * ff[n][i] % 1000000007) % 1000000007;
        ans += tmp % 1000000007;
      } else {
        tmp = tmp * (C(k, i) * ff[n][i] % 1000000007) % 1000000007;
        tmp = tmp * C(i, j) % 1000000007;
        tmp = tmp * (C(k - i, i - j) * ff[n][i] % 1000000007) % 1000000007;
        ans += tmp % 1000000007;
      }
    }
  }
  cout << ans % 1000000007 << endl;
  return 0;
}
