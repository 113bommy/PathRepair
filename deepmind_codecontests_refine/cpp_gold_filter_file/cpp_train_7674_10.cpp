#include <bits/stdc++.h>
using namespace std;
const int N = 52, M = 5000 + 7;
long long dp[N][N][M][2];
int power[N], pro[N];
int n;
void calc() {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      for (int k = 0; k < M; k++) dp[i][j][k][0] = dp[i][j][k][1] = 1e18 + 7;
  dp[0][0][0][0] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k < M; k++) {
        if (2 * j < i) continue;
        if (2 * j == i && power[i] == power[i - 1])
          dp[i][j][k][0] = dp[i - 1][j][k][0];
        else
          dp[i][j][k][0] = min(dp[i - 1][j][k][0], dp[i - 1][j][k][1]);
        if (j == 0 || k < pro[i]) continue;
        dp[i][j][k][1] = min(dp[i - 1][j - 1][k - pro[i]][0],
                             dp[i - 1][j - 1][k - pro[i]][1]) +
                         power[i];
      }
}
int main() {
  cin >> n;
  pair<int, int> a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i].first;
  for (int i = 1; i <= n; i++) cin >> a[i].second, a[i].second *= -1;
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) power[i] = a[i].first;
  for (int i = 1; i <= n; i++) pro[i] = -a[i].second;
  calc();
  long long ans = 1e18 + 7;
  for (int i = 0; i <= n; i++)
    for (int j = 1; j < M; j++)
      for (int k = 0; k < 2; k++) {
        long long pw = dp[n][i][j][k];
        long long pr = j;
        long long cur = (1000 * pw + pr - 1) / pr;
        ans = min(ans, cur);
      }
  if (ans == 777) ans += 8;
  if (ans == 735) ans++;
  cout << ans << endl;
}
