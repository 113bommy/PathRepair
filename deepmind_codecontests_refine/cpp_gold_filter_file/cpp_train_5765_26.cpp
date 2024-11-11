#include <bits/stdc++.h>
using namespace std;
inline int qr() {
  register int ret = 0, f = 0;
  register char c = getchar();
  while (c < 48 || c > 57) f |= c == 45, c = getchar();
  while (c >= 48 && c <= 57) ret = ret * 10 + c - 48, c = getchar();
  return f ? -ret : ret;
}
const int maxn = 1e3 + 5;
long double dp[maxn][maxn], ans;
const long double qt[] = {0, (long double)1.0 / 1, (long double)1.0 / 2,
                          (long double)1.0 / 3, (long double)1.0 / 4};
int cnt;
int n, m;
int x, y;
int main() {
  n = qr();
  m = qr();
  x = qr();
  y = qr();
  const int lit = 50000000 / (m) / (n - x + 1);
  for (register int t = n - 1; t >= x; --t) {
    for (register int t0 = 1; t0 <= lit; ++t0) {
      if (m > 1)
        dp[t][1] = qt[3] * (dp[t + 1][1] + dp[t][2] + dp[t][1]) + 1,
        dp[t][m] = qt[3] * (dp[t + 1][m] + dp[t][m - 1] + dp[t][m]) + 1;
      if (m == 1) dp[t][1] = qt[2] * (dp[t][1] + dp[t + 1][1]) + 1;
      for (register int i = 2; i < m; ++i)
        dp[t][i] =
            qt[4] * (dp[t + 1][i] + dp[t][i - 1] + dp[t][i] + dp[t][i + 1]) + 1;
    }
  }
  cout.precision(10);
  cout << dp[x][y] << endl;
  return 0;
}
