#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
inline int naive(int n, int m) {
  int ans = 0;
  for (int i1 = 0; i1 <= n; ++i1)
    for (int j1 = 0; j1 <= m; ++j1)
      for (int i2 = 0; i2 <= n; ++i2)
        for (int j2 = 0; j2 <= m; ++j2)
          for (int i3 = 0; i3 <= n; ++i3)
            for (int j3 = 0; j3 <= m; ++j3) {
              int sq =
                  i1 * j2 - i2 * j1 + i2 * j3 - i3 * j2 + i3 * j1 - i1 * j3;
              if (sq != 0 && sq % 2 == 0) ++ans;
            }
  return ans;
}
int f[2][2];
inline int gcd(int first, int second) {
  while (first && second)
    if (first >= second)
      first %= second;
    else
      second %= first;
  return first + second;
}
unsigned long long ans = 0;
const long long mod = 1000000007;
inline long long solve(int n, int m) {
  f[0][0] = (1 + n / 2) * (1 + m / 2);
  f[0][1] = (1 + n / 2) * (m / 2 + m % 2);
  f[1][0] = (n / 2 + n % 2) * (1 + m / 2);
  f[1][1] = (n / 2 + n % 2) * (m / 2 + m % 2);
  ans = 0;
  for (int i1 = 0; i1 <= 1; ++i1)
    for (int j1 = 0; j1 <= 1; ++j1)
      for (int i2 = 0; i2 <= 1; ++i2)
        for (int j2 = 0; j2 <= 1; ++j2)
          for (int i3 = 0; i3 <= 1; ++i3)
            for (int j3 = 0; j3 <= 1; ++j3) {
              int sq =
                  i1 * j2 - i2 * j1 + i2 * j3 - i3 * j2 + i3 * j1 - i1 * j3;
              if (sq % 2 == 0) {
                unsigned long long val =
                    (((long long)f[i1][j1] * f[i2][j2]) % mod * f[i3][j3]) %
                    mod;
                ans = (ans + val) % mod;
              }
            }
  for (int dx = 1; dx <= n; ++dx) {
    for (int dy = 1; dy <= m; ++dy) {
      ans = (ans + mod -
             ((long long)(n + 1 - dx) * (m + 1 - dy) * (gcd(dx, dy)) * 6 * 2) %
                 mod) %
            mod;
    }
  }
  for (int dx = 1; dx <= n; ++dx) {
    int dy = 0;
    ans = (ans + mod -
           ((long long)(n + 1 - dx) * (m + 1 - dy) * (gcd(dx, dy)) * 6 * 1) %
               mod) %
          mod;
  }
  for (int dy = 1; dy <= m; ++dy) {
    int dx = 0;
    ans = (ans + mod -
           ((long long)(n + 1 - dx) * (m + 1 - dy) * (gcd(dx, dy)) * 6 * 1) %
               mod) %
          mod;
  }
  ans = (ans + mod - (n + 1) * (m + 1) % mod) % mod;
  return ans;
}
int n, m;
int main() {
  cin >> n >> m;
  cout << solve(n, m) << endl;
}
