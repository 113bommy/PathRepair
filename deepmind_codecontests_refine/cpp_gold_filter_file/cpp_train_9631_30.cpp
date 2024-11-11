#include <bits/stdc++.h>
using namespace std;
const long long INF = 1 << 28;
const long long LINF = 1ll << 61;
const long long mod = 1e9 + 7;
unsigned long long base = 1000000007;
char a[2][2011], s[2011];
int n, m;
unsigned long long hsl[2][2011], hsr[2][2011], hss[2011], pw[2011];
unsigned long long gethsl(int i, int x, int y) {
  return hsl[i][y] - hsl[i][x - 1] * pw[y - x + 1];
}
unsigned long long gethsr(int i, int x, int y) {
  return hsr[i][y] - hsr[i][x + 1] * pw[x - y + 1];
}
unsigned long long gethss(int x, int y) {
  return hss[y] - hss[x - 1] * pw[y - x + 1];
}
long long dp[2][2011][2], pre[2][2011][2];
long long solve() {
  for (int i = 0; i < 2; i++) {
    hsl[i][0] = 0;
    for (int j = 1; j <= n; j++) hsl[i][j] = hsl[i][j - 1] * base + a[i][j];
    hsr[i][n + 1] = 0;
    for (int j = n; j >= 1; j--) hsr[i][j] = hsr[i][j + 1] * base + a[i][j];
  }
  long long ans = 0;
  memset(dp, 0, sizeof(dp));
  for (int p = 1; p <= m; p++) {
    for (int i = 0; i < 2; i++)
      for (int j = 1; j <= n; j++)
        for (int t = 0; t < 2; t++) pre[i][j][t] = dp[i][j][t];
    memset(dp, 0, sizeof(dp));
    if (p % 2 == 0 && p > 2 && p < m) {
      int len = p >> 1;
      for (int i = 0; i < 2; i++) {
        for (int j = len + 1; j <= n + 1; j++) {
          if (gethsr(i, j - 1, j - len) * pw[len] +
                  gethsl(!i, j - len, j - 1) !=
              gethss(1, p))
            continue;
          dp[!i][j - 1][1] = 1;
        }
      }
    } else if (p == 1) {
      for (int i = 0; i < 2; i++)
        for (int j = 1; j <= n; j++) dp[i][j][0] = (s[1] == a[i][j]);
    }
    for (int i = 0; i < 2; i++) {
      for (int j = 1; j <= n; j++) {
        if (a[i][j] != s[p]) continue;
        dp[i][j][0] = (dp[i][j][0] + pre[i][j - 1][0] + pre[i][j - 1][1]) % mod;
        dp[i][j][1] = (dp[i][j][1] + pre[!i][j][0]) % mod;
      }
    }
    if ((m - p) % 2 == 0 && m - p > 2) {
      int len = (m - p) >> 1;
      for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n - len; j++) {
          if (gethsl(i, j + 1, j + len) * pw[len] +
                  gethsr(!i, j + len, j + 1) !=
              gethss(p + 1, m))
            continue;
          for (int t = 0; t < 2; t++) ans = (ans + dp[i][j][t]) % mod;
        }
      }
    } else if (p == m) {
      for (int i = 0; i < 2; i++)
        for (int j = 1; j <= n; j++)
          for (int t = 0; t < 2; t++) ans = (ans + dp[i][j][t]) % mod;
    }
  }
  return ans;
}
int main() {
  pw[0] = 1;
  for (int i = 1; i <= 2005; i++) pw[i] = pw[i - 1] * base;
  scanf("%s", a[0] + 1);
  scanf("%s", a[1] + 1);
  n = strlen(a[0] + 1);
  scanf("%s", s + 1);
  m = strlen(s + 1);
  if (m == 1) {
    int cnt = 0;
    for (int i = 0; i < 2; i++)
      for (int j = 1; j <= n; j++) cnt += (a[i][j] == s[1]);
    cout << cnt << endl;
    return 0;
  } else if (m == 2) {
    int cnt = 0;
    for (int i = 0; i < 2; i++)
      for (int j = 1; j <= n; j++) cnt += (a[i][j] == s[1] && a[!i][j] == s[2]);
    for (int i = 0; i < 2; i++)
      for (int j = 1; j <= n; j++)
        cnt += (a[i][j] == s[1] && a[i][j + 1] == s[2]) +
               (a[i][j] == s[1] && a[i][j - 1] == s[2]);
    cout << cnt << endl;
    return 0;
  }
  for (int i = 1; i <= m; i++) hss[i] = hss[i - 1] * base + s[i];
  long long ans = solve();
  reverse(a[0] + 1, a[0] + n + 1);
  reverse(a[1] + 1, a[1] + n + 1);
  ans = (ans + solve()) % mod;
  if (m % 2 == 0) {
    int len = m >> 1;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j <= n - len; j++) {
        ans +=
            (gethsl(i, j + 1, j + len) * pw[len] + gethsr(!i, j + len, j + 1) ==
             gethss(1, m));
      }
    }
    for (int i = 0; i < 2; i++) {
      for (int j = len + 1; j <= n + 1; j++) {
        ans +=
            (gethsr(i, j - 1, j - len) * pw[len] + gethsl(!i, j - len, j - 1) ==
             gethss(1, m));
      }
    }
  }
  cout << ans % mod << endl;
  return 0;
}
