#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000000 + 7;
const int maxn = 100 + 55;
long long h, w, m;
int c[maxn][maxn];
int dp[maxn][maxn];
int pw(long long a, long long e) {
  if (e == 0)
    return 1;
  else if (e % 2 == 0) {
    long long first = pw(a, e / 2);
    return (first * first) % mod;
  } else {
    long long first = pw(a, e - 1);
    return (first * a) % mod;
  }
}
long long tmp[maxn];
long long speed[maxn][maxn];
int main() {
  c[0][0] = 1;
  for (int i = 1; i < maxn; ++i) {
    c[i][0] = c[i - 1][0];
    for (int j = 1; j <= i; ++j)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
  }
  cin >> h >> w >> m;
  for (int i = 0; i < maxn; ++i) {
    for (int k = 0; k < maxn; ++k) {
      speed[k][i] = pw(c[h][k], (w / h) + (i < w % h));
    }
  }
  dp[0][m] = 1;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j <= m; ++j) {
      for (int k = 0; k <= h; ++k) {
        if (k > j) break;
        dp[i + 1][j - k] = (dp[i + 1][j - k] + dp[i][j] * speed[k][i]) % mod;
      }
    }
  }
  printf("%d\n", dp[h][0]);
  return 0;
}
