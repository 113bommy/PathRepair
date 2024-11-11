#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return f * x;
}
const long long N = 1e6 + 7;
const long long M = 1e9 + 7;
const long long MAXN = 2e18 + 7;
const long long Mod = 998244353;
long long _, i, j, k, n, m, p, q, s, T, t, l, r, o, u, v, w, x, y, z, ans,
    nex[N], num, st, en, sx, sy, tx, ty, len, th, ma, mi, mod, sum, res, flag,
    cas, ret, mid, cnt, now, tmp;
long long a[N], c[N], dp[N][5];
char ch;
vector<long long> g[N], h;
string s1, s2, s3;
signed main() {
  ios::sync_with_stdio(false);
  long long T = 1;
  while (T--) {
    n = read();
    x = read();
    y = read();
    z = read();
    k = read();
    for (i = 1; i <= n; i++) a[i] = read();
    for (i = 1; i <= n; i++)
      for (j = 1; j < 5; j++) dp[i][j] = MAXN;
    dp[1][1] = a[1] * x + z + k;
    dp[1][3] = min(a[1] * x + z, min((a[1] + 2) * x, y + x)) + 2 * k;
    for (i = 2; i <= n; i++) {
      dp[i][1] = min(dp[i - 1][1], dp[i - 1][2]) + a[i] * x + z + k;
      dp[i][2] = min(dp[i - 1][3], dp[i - 1][4]) +
                 min(a[i] * x + z, min((a[i] + 2) * x, y + x)) + 2 * k;
      dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) +
                 min(a[i] * x + z, min((a[i] + 2) * x, y + x)) + 2 * k;
      dp[i][4] =
          dp[i - 1][3] + min(a[i] * x + z, min((a[i] + 2) * x, y + x)) + 3 * k;
    }
    ans = min(dp[n][1], dp[n][2]);
    c[n] = min(a[n] * x + z + k, min((a[n] + 2) * x, y + x) + 3 * k);
    for (i = n - 1; i >= 1; i--) {
      c[i] = c[i + 1] + min(a[i] * x + z, min((a[i] + 2) * x, y + x)) + 2 * k;
    }
    for (i = 1; i <= n; i++) {
      ans = min(ans, c[i] + min(dp[i - 1][1], dp[i - 1][2]));
    }
    printf("%lld\n", ans - k);
  }
  return 0;
}
