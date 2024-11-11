#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 28;
const int mod = (int)1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1.0);
int n, m, mx;
long long cnt[20], fac[20];
long long c[10][10];
long long dp[15][15];
void init() {
  dp[0][0] = 1;
  for (int i = 0; i <= 10; i++)
    for (int j = 0; j <= i; j++)
      if (dp[i][j]) {
        dp[i + 1][j] += 8 * dp[i][j];
        dp[i + 1][j + 1] += 2 * dp[i][j];
      }
  fac[0] = 1;
  for (int i = 1; i <= 9; i++) fac[i] = i * fac[i - 1];
  c[0][0] = 1;
  for (int i = 1; i <= 9; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j <= i; j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  }
}
int a[15], len;
void calc(long long n) {
  long long tmp = n;
  while (tmp) {
    a[++len] = tmp % 10;
    tmp /= 10;
  }
  int nn = 0;
  for (int i = len; i >= 1; i--) {
    for (int j = 0; j < i; j++) {
      if (a[i] > 7) {
        cnt[j + nn] += (a[i] - 2) * dp[i - 1][j];
        cnt[j + 1 + nn] += 2 * dp[i - 1][j];
      } else if (a[i] > 4) {
        cnt[j + nn] += (a[i] - 1) * dp[i - 1][j];
        cnt[j + 1 + nn] += dp[i - 1][j];
      } else {
        cnt[j + nn] += a[i] * dp[i - 1][j];
      }
    }
    if (a[i] == 4 || a[i] == 7) nn++;
  }
  int tt = 0;
  for (int i = 1; i <= len; i++)
    if (a[i] == 4 || a[i] == 7) tt++;
  cnt[tt]++;
  cnt[0]--;
  for (mx = 10; mx >= 0; mx--) {
    if (cnt[mx] != 0) break;
  }
}
long long p(long long n, long long m) {
  long long ans = 1;
  for (int i = 0; i < m; i++) ans = ans * (n - i) % mod;
  return ans;
}
long long num[15], tmp, ans;
void dfs(int step, int mx, int sum, int k) {
  if (step == 6) {
    tmp = 1;
    int nn = 6;
    for (int i = mx - 1; i >= 0; i--) {
      tmp = tmp * c[nn][num[i]] * p(cnt[i], num[i]) % mod;
      nn -= num[i];
    }
    ans = (ans + cnt[mx] * tmp) % mod;
    return;
  }
  for (int i = k; i >= 0; i--) {
    if (cnt[i] > num[i] && sum + i < mx) {
      num[i]++;
      dfs(step + 1, mx, sum + i, i);
      num[i]--;
    }
  }
}
int main() {
  init();
  while (cin >> m) {
    calc(m);
    ans = 0;
    for (int i = 1; i <= mx; i++) {
      dfs(0ll, i, 0ll, i);
    }
    cout << ans << endl;
  }
  return 0;
}
