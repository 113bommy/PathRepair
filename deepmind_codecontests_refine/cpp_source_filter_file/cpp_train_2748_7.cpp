#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long mod = 1000000007;
const long long p = 137;
const long long MAXN = 1e3 + 5;
long long n, m, no[MAXN][MAXN], ok[MAXN][MAXN], ans;
long long f(long long x) { return x ^ 1; }
int main() {
  while (~scanf("%lld %lld", &n, &m)) {
    for (long long i = 1; i <= m; i++) {
      long long u, v;
      scanf("%lld %lld", &u, &v);
      no[u][v] = 1;
    }
    for (long long i = 2; i <= n / 2; i++) {
      long long flag = 1, cnt = 0;
      for (long long j = 2; j < n; j++) {
        if (no[i][j]) {
          flag = 0;
          break;
        }
      }
      if (flag) {
        if (!no[i][1]) {
          ok[i][1] = 1;
        }
        if (!no[i][n]) {
          ok[i][n] = 1;
        }
      }
      flag = 1;
      for (long long j = 2; j < n; j++) {
        if (no[n - i + 1][j]) {
          flag = 0;
          break;
        }
      }
      if (flag) {
        if (!no[n - i + 1][1]) {
          ok[n - i + 1][1] = 1;
        }
        if (!no[n - i + 1][n]) {
          ok[n - i + 1][n] = 1;
        }
      }
      flag = 1;
      for (long long j = 2; j < n; j++) {
        if (no[j][i]) {
          flag = 0;
          break;
        }
      }
      if (flag) {
        if (!no[1][i]) {
          ok[1][i] = 1;
        }
        if (!no[n][i]) {
          ok[n][i] = 1;
        }
      }
      flag = 1;
      for (long long j = 2; j < n; j++) {
        if (no[j][n - i + 1]) {
          flag = 0;
          break;
        }
      }
      if (flag) {
        if (!no[1][n - i + 1]) {
          ok[1][n - i + 1] = 1;
        }
        if (!no[n][n - i + 1]) {
          ok[n][n - i + 1] = 1;
        }
      }
      long long cnt1 =
          ok[i][1] + ok[n - i + 1][n] + ok[1][n - i + 1] + ok[n][i];
      long long cnt2 =
          ok[n - i + 1][1] + ok[i][n] + ok[1][i] + ok[n][n - i + 1];
      ans += max(cnt1, cnt2);
    }
    if (n & 1) {
      long long flag = 1, cnt = 0;
      for (long long j = 2; j < n; j++) {
        if (no[n / 2 + 1][j]) {
          flag = 0;
          break;
        }
      }
      if (flag) {
        cnt++;
      }
      flag = 1;
      for (long long j = 2; j < n; j++) {
        if (no[j][n / 2 + 1]) {
          flag = 0;
          break;
        }
      }
      if (flag) {
        cnt++;
      }
      if (cnt > 0) {
        ans++;
      }
    }
    printf("%lld\n", ans);
  }
}
