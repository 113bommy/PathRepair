#include <bits/stdc++.h>
using namespace std;
inline long long in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline long long lin() {
  long long x;
  scanf("%lld", &x);
  return x;
}
inline string get() {
  char ch[2000010];
  scanf("%s", ch);
  return ch;
}
inline void read(long long *a, long long n) {
  for (long long i = 0; i < n; i++) a[i] = in();
}
template <class blank>
inline void out(blank x) {
  cout << x << "\n";
  exit(0);
}
const long long maxn = 1500 + 10;
const long long maxm = 1e6 + 10;
const long long maxlg = 20;
const long long base = 29;
const long long base2 = 31;
const long long mod2 = 1e9 + 9;
const long long mod = 1e9 + 7;
const long long INF = 1e18 + 10;
const long long SQ = 317 + 5;
long long a[maxn][maxn];
long long pref[maxn][maxn], suf[maxn][maxn];
long long prefSum[maxn][maxn];
long long dp[maxn];
int32_t main() {
  long long n = in(), m = in();
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      a[i][j] = in();
      prefSum[i][j] = prefSum[i][j - 1] + a[i][j];
    }
  }
  for (long long i = 1; i <= n; i++) {
    memset(dp, -63, sizeof dp);
    for (long long j = 1; j <= m; j++) {
      if (i % 2) {
        dp[j] = max(dp[j], pref[i - 1][j - 1] + prefSum[i][j]);
      } else {
        dp[j] = max(dp[j], suf[i - 1][j + 1] + prefSum[i][j]);
      }
    }
    for (long long j = 1; j <= m; j++) {
      pref[i][j] = max(j > 1 ? pref[i][j - 1] : -INF, dp[j]);
    }
    for (long long j = m; j >= 1; j--) {
      suf[i][j] = max(j == n ? -INF : suf[i][j + 1], dp[j]);
    }
    suf[i][m + 1] = -INF;
    pref[i][0] = -INF;
  }
  cout << pref[n][m] << "\n";
}
