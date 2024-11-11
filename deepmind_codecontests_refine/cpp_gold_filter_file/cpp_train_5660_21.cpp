#include <bits/stdc++.h>
using namespace std;
inline long long sqr(long long x) { return x * x; }
const long long base = 1e9 + 7;
int n, k, cnt[111];
long long c[111][111], p[2][111][111];
long long m, dp[111][11111];
long long fast_power(long long x, long long mu) {
  if (mu == 0) return 1;
  if (mu == 1) return x % base;
  long long t = fast_power(x, mu / 2);
  t = (t * t) % base;
  if (mu % 2 != 0) t = (t * x) % base;
  return t;
}
void init() {
  for (int i = (0), _b = (100); i <= _b; ++i) {
    c[i][0] = 1;
    for (int j = (1), _b = (i); j <= _b; ++j)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % base;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  init();
  long long cnt = (m / (long long)n);
  for (int i = (0), _b = (100); i <= _b; ++i)
    for (int j = (0), _b = (i); j <= _b; ++j) {
      p[0][i][j] = fast_power(c[i][j], cnt);
      p[1][i][j] = fast_power(c[i][j], cnt + 1);
    }
  dp[0][0] = 1;
  for (int i = (0), _b = (n - 1); i <= _b; ++i)
    for (int j = (0), _b = (k); j <= _b; ++j)
      if (dp[i][j]) {
        int id = (i + 1 <= m % (long long)n) ? 1 : 0;
        for (int x = (0), _b = (n); x <= _b; ++x)
          if (j + x <= k)
            dp[i + 1][j + x] =
                (dp[i + 1][j + x] + (dp[i][j] * p[id][n][x]) % base) % base;
      }
  cout << dp[n][k];
  return 0;
}
