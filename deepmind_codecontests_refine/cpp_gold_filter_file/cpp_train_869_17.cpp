#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
const int inf = (int)1e9 + 1;
const long long big = (long long)1e18 + 1;
const int P = 31;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const double eps = 1e-6;
const double pi = atan2(0, -1);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(20);
  int n, m;
  cin >> n >> m;
  n *= 3;
  int a[n];
  fill(a, a + n, -1);
  for (int i = 0; i < n / 3; i++) {
    cin >> a[n / 3 + i];
    a[n / 3 + i]--;
    double x;
    cin >> x;
  }
  int p = 0;
  int dp[2][n];
  int pref[2][n];
  int cnt[2][n];
  for (int i = 0; i < n; i++) dp[p][i] = 0;
  for (int i = 0; i < n; i++)
    if (a[i] == 0)
      cnt[p ^ 1][i] = 1;
    else
      cnt[p ^ 1][i] = 0;
  for (int i = 1; i < n; i++) cnt[p ^ 1][i] += cnt[p ^ 1][i - 1];
  for (int i = 0; i < n; i++) pref[p][i] = dp[p][i] + cnt[p ^ 1][i];
  for (int i = 1; i < n; i++) pref[p][i] = min(pref[p][i], pref[p][i - 1]);
  p ^= 1;
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < j + 1; i++) dp[p][i] = inf;
    for (int i = j + 1; i < n; i++)
      dp[p][i] = pref[p ^ 1][i] + cnt[p][n - 1] - cnt[p][i];
    if (j == m - 1) break;
    for (int i = 0; i < n; i++)
      if (a[i] == j + 1)
        cnt[p ^ 1][i] = 1;
      else
        cnt[p ^ 1][i] = 0;
    for (int i = 1; i < n; i++) cnt[p ^ 1][i] += cnt[p ^ 1][i - 1];
    for (int i = 0; i < n; i++) pref[p][i] = dp[p][i] + cnt[p ^ 1][i];
    for (int i = 1; i < n; i++) pref[p][i] = min(pref[p][i], pref[p][i - 1]);
    p ^= 1;
  }
  int ans = inf;
  for (int i = 0; i < n; i++) ans = min(ans, dp[p][i]);
  cout << ans << endl;
  return 0;
}
