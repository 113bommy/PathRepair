#include <bits/stdc++.h>
using namespace std;
int n, k, s, ar[1 << 20];
int dp[3][200 * 200][200];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k >> s;
  for (int i = 1; i <= n; i++) cin >> ar[i];
  if (s > n * n / 2 + 10) s = n * n / 2 + 10;
  for (int done = 0; done <= s; done++)
    for (int pref = 0; pref <= k; pref++) dp[0][pref][done] = 1e9;
  dp[0][0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= s; j++)
      for (int q = 0; q <= k; q++) dp[i % 2][q][j] = 1e9;
    for (int pref = 0; pref < i && pref <= k; pref++)
      for (int done = 0; done <= s; done++) {
        dp[i % 2][pref][done] =
            min(dp[i % 2][pref][done], dp[1 - i % 2][pref][done]);
        int ndone = done + i - pref - 1;
        if (ndone <= s)
          dp[i % 2][pref + 1][ndone] = min(dp[i % 2][pref + 1][ndone],
                                           dp[1 - i % 2][pref][done] + ar[i]);
      }
  }
  int ans = 1e9;
  for (int i = 0; i <= s; i++) ans = min(ans, dp[n % 2][k][i]);
  cout << ans << endl;
  return 0;
}
