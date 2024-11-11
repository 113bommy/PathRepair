#include <bits/stdc++.h>
using namespace std;
long double dp[1 << 21];
long long diff[1 << 21];
string inp[50];
int main() {
  int n, m;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> inp[i];
  m = inp[0].size();
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      int mask = 0;
      for (int k = 0; k < m; k++) mask |= (inp[i][k] == inp[j][k]) << k;
      diff[mask] |= 1 << i | 1 << j;
    }
  for (int mask = (1 << m) - 1; mask >= 0; mask--) {
    int cnt = 0;
    for (int p = 0; p < m; p++)
      if (!(mask & 1 << p)) cnt++, diff[mask] |= diff[mask | (1 << p)];
    if (!diff[mask]) continue;
    for (int p = 0; p < m; p++)
      if (!(mask & 1 << p))
        dp[mask] += dp[mask | (1 << p)] *
                    __builtin_popcountll(diff[mask | (1 << p)]) /
                    __builtin_popcountll(diff[mask]);
    dp[mask] = 1 + dp[mask] / cnt;
  }
  cout << fixed << setprecision(15) << dp[0] << endl;
  return 0;
}
