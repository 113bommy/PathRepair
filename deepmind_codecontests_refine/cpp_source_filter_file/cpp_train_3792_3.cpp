#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;
const int MAXM = 1e4 + 40;
const int Zero = 5e3 + 20;
const int Mod = 1e9 + 7;
long long dp[MAXN][MAXM];
long long y[MAXM];
long long z[MAXM];
int a[MAXN];
int ps[MAXN];
long long solve(int l, int r) {
  if (l == r) {
    return 0;
  }
  int mid = (l + r) / 2, sum = ((ps[r] - ps[l]) / 2) + 10;
  long long res = (solve(l, mid) + solve(mid + 1, r)) % Mod;
  for (int i = 0; i < MAXM; i++) {
    z[i] = 0;
    dp[mid][i] = 0;
  }
  dp[mid][Zero] = 1;
  for (int i = mid + 1; i <= r; i++) {
    for (int j = Zero - sum; j < Zero + sum; j++) {
      dp[i][j] = (j >= a[i] ? dp[i - 1][j - a[i]] : 0) +
                 (j + a[i] < MAXM ? dp[i - 1][j + a[i]] : 0);
      dp[i][j] %= Mod;
      z[j] += dp[i][j];
      z[j] %= Mod;
    }
  }
  for (int i = 0; i < MAXM; i++) {
    y[i] = 0;
    dp[mid + 1][i] = 0;
  }
  dp[mid + 1][Zero] = 1;
  for (int i = mid; i >= l; i--) {
    for (int j = Zero - sum; j < Zero + sum; j++) {
      dp[i][j] = (j >= a[i] ? dp[i + 1][j - a[i]] : 0) +
                 (j + a[i] < MAXM ? dp[i + 1][j + a[i]] : 0);
      dp[i][j] %= Mod;
      y[j] += dp[i][j];
      y[j] %= Mod;
    }
  }
  for (int i = 0; i < MAXM; i++) {
    res += z[i] * y[2 * Zero - i];
    res %= Mod;
  }
  return res;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ps[i] = ps[i - 1] + a[i];
  }
  cout << solve(1, n);
}
