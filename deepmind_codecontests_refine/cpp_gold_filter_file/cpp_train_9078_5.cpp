#include <bits/stdc++.h>
#pragma 03
using namespace std;
long long dp[5005][5005], cnt[5005], mx[5005], f[5005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (long long i = 0; i < 5005; i++) {
    for (long long j = 0; j < 5005; j++) dp[i][j] = 0;
    cnt[i] = 0;
    mx[i] = 0;
    f[i] = 0;
  }
  for (long long i = 1; i < 5005; i++) {
    for (long long j = 1; j < 5005; j++) dp[i][j] += dp[i - 1][j];
    long long x = i;
    for (long long j = 2; j <= x; j++) {
      while (x % j == 0 && x > 0) {
        x /= j;
        dp[i][j]++;
      }
    }
  }
  long long n, ans = 0;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long inp;
    cin >> inp;
    cnt[inp]++;
  }
  for (long long i = 1; i < 5005; i++) {
    for (long long j = 1; j <= i; j++) {
      if (dp[i][j]) {
        mx[i] = j;
        ans += (cnt[i] * dp[i][j]);
      }
    }
  }
  while (true) {
    for (long long i = 0; i < 5005; i++) f[i] = 0;
    for (long long i = 1; i < 5005; i++) f[mx[i]] += cnt[i];
    long long make_pair = 2;
    for (long long i = 2; i < 5005; i++) {
      if (f[i] > f[make_pair]) make_pair = i;
    }
    if (f[make_pair] * 2 <= n) break;
    ans += (n - 2 * f[make_pair]);
    for (long long i = 1; i < 5005; i++) {
      if (mx[i] != make_pair) mx[i] = 1;
      if (mx[i] == 1) continue;
      dp[i][make_pair]--;
      while (mx[i] > 1 && dp[i][mx[i]] == 0) mx[i]--;
    }
  }
  cout << ans << endl;
  return 0;
}
