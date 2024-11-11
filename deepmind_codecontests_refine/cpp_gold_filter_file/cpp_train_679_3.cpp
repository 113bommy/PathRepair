#include <bits/stdc++.h>
using namespace std;
const int32_t MOD = 1e9 + 7;
const int32_t N = 1e5 + 3000;
int32_t a, b, k, t;
int64_t dem = 0, d = 0;
int64_t f[2 * N], s[2 * N];
int main() {
  cin >> a >> b >> k >> t;
  f[N] = 1;
  for (int32_t i = 1; i <= t; i++) {
    for (int32_t j = -k * i; j <= k * i; j++)
      s[j + N] = (s[j - 1 + N] + f[j + N]) % MOD;
    for (int32_t j = -k * i; j <= k * i; j++) {
      int32_t x = min(k + j, k * i);
      int32_t y = max(j - k, -k * i) - 1;
      f[j + N] = (s[x + N] - s[y + N] + MOD) % MOD;
    }
  }
  for (int32_t i = b - a - k * t; i <= k * t; i++) {
    d = (d + f[N + i + a - b - 1]) % MOD;
    dem = (dem + d * f[N + i]) % MOD;
  }
  cout << dem;
}
