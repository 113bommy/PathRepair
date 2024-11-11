#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
using namespace std;
const long long N = 200, OO = 1e9 + 7, T = 1e6 + 10, mod = 1e9 + 7, P = 6151,
                SQ = 280, lg = 70;
long long dp[N][N], pw[N];
int32_t main() {
  long long n;
  string s;
  cin >> n >> s;
  pw[0] = 1;
  for (long long i = 1; i <= n; i++) pw[i] = pw[i - 1] * 2;
  long long m = (long long)s.size(), ans = 0;
  for (long long j = m; j >= 0; j--) {
    for (long long i = 0; i < n; i++) {
      if (i + m - 1 >= n) {
        long long h = (i + m) % n, p = m - h;
        bool u = true;
        for (long long k = 0; k < min(h, j); k++) {
          if (s[m - j + k] != s[p + k]) {
            u = false;
            continue;
          }
        }
        if (!u) continue;
        if (h > j) {
          dp[i][j] = dp[i][h];
          continue;
        }
      }
      if (i <= j) {
        string t = "";
        bool u = true;
        for (long long k = 0; k < i + m; k++) {
          if (k < i)
            t += s[m - j + k];
          else if (k < j) {
            if (s[m - j + k] != s[k - i])
              u = false;
            else
              t += s[m - j + k];
          } else
            t += s[k - i];
        }
        if (!u) continue;
        for (long long k = 0; k < (long long)t.size() - m; k++) {
          u = true;
          for (long long h = 0; h < m; h++) {
            if (s[h] != t[k + h]) {
              u = false;
              break;
            }
          }
          if (u) {
            dp[i][j] = -1;
            break;
          }
        }
        dp[i][j]++;
      } else {
        dp[i][j] = pw[i - j];
        for (long long k = 0; k < i; k++) {
          bool u = true;
          if (dp[k][j] == 0) continue;
          long long p = i - k;
          for (long long h = i; h < k + m; h++) {
            if (s[h - i] != s[h - i + p]) {
              u = false;
              break;
            }
          }
          if (u) dp[i][j] -= dp[k][j] * pw[max((long long)0, i - (k + m))];
        }
      }
    }
  }
  for (long long i = 0; i < n; i++)
    ans += dp[i][0] * pw[max((long long)0, n - (i + m))];
  cout << ans << endl;
  return 0;
}
