#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9, mod = 1e9 + 7;
const int N = 2e6 + 5;
long long k, n, m, dp[N], cnt[N];
double P[N], pr[N];
string str[60];
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    cin >> str[i];
    str[i] = '0' + str[i];
  }
  m = str[1].size() - 1;
  P[0] = 1;
  for (int i = 1; i <= m; i++) P[i] = i * P[i - 1];
  for (int i = m; i >= 1; i--) pr[i] = 1.0 / P[i];
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      long long temp = 0;
      for (int k = 1; k <= m; k++)
        if (str[i][k] == str[j][k]) temp += (1 << k - 1);
      dp[temp] |= (1ll << i - 1ll);
      dp[temp] |= (1ll << j - 1ll);
    }
  for (int j = 0; j <= m - 1; j++)
    for (int i = (1 << m) - 1; i >= 0; i--)
      if ((i & (1 << j))) dp[i - (1 << j)] |= dp[i];
  long double ans = 0;
  for (int i = 0; i <= (1 << m) - 1; i++) {
    if (!dp[i]) continue;
    int cnt = __builtin_popcount(i);
    for (int j = 0; j <= m - 1; j++)
      if ((i & (1 << j)) == 0) {
        int t = __builtin_popcount(dp[i] ^ dp[i + (1 << j)]);
        ans += (cnt + 1) / (1.0 * n) *
               (P[cnt] * P[m - cnt] / P[m] * (1.0 * t / (m - cnt)));
      }
  }
  cout << setprecision(12) << fixed << ans << '\n';
  return 0;
}
