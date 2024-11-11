#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const int N = 55;
int n, c, l[N], r[N], w[N];
long long dp[N][2 * N][N], s[N][2 * N], inv[N], tot = 1;
struct s0rt {
  int x, id, f;
  friend bool operator<(s0rt a, s0rt b) { return a.x < b.x; }
} px[N];
long long Pow(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = ret * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return ret;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) inv[i] = Pow(i, MOD - 2);
  for (int i = 1; i <= n; i++) {
    cin >> px[2 * i - 1].x >> px[2 * i].x;
    px[2 * i].x++;
    tot = tot * (px[2 * i].x - px[2 * i - 1].x) % MOD;
    px[2 * i - 1].id = px[2 * i].id = n + 1 - i;
    px[2 * i - 1].f = 1;
    px[2 * i].f = 2;
  }
  sort(px + 1, px + 2 * n + 1);
  for (int i = 1; i <= 2 * n; i++) {
    if (i > 1 && px[i].x > px[i - 1].x) c++, w[c] = px[i].x - px[i - 1].x;
    if (px[i].f == 1)
      l[px[i].id] = c;
    else
      r[px[i].id] = c;
  }
  for (int j = 0; j <= c; j++) s[0][j] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = l[i] + 1; j <= r[i]; j++) {
      dp[i][j][1] = s[i - 1][j - 1];
      for (int k = 2; k <= i; k++) dp[i][j][k] = dp[i - 1][j][k - 1];
    }
    for (int j = l[i] + 1; j <= r[i]; j++) {
      s[i][j] = s[i][j - 1];
      long long cur = 1;
      for (int k = 1; k <= n; k++) {
        cur = cur * (w[j] + k - 1) % MOD;
        cur = cur * inv[k] % MOD;
        s[i][j] = (s[i][j] + dp[i][j][k] * cur) % MOD;
      }
    }
    for (int j = r[i] + 1; j <= c; j++) s[i][j] = s[i][r[i]];
  }
  cout << s[n][c] * Pow(tot, MOD - 2) % MOD << endl;
  return 0;
}
