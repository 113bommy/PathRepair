#include <bits/stdc++.h>
using namespace std;
int n, m, k, st[1000005], dr[1000005], fr[1000005], dp[1000005][2], s[1000005],
    put[1000005];
int main() {
  int i, p = 0, L, R, maxx = -1000000000, minn = 1000000000;
  cin.sync_with_stdio(0);
  cin >> n >> m >> k;
  put[0] = 1;
  for (i = 1; i <= 1000000; ++i) put[i] = (1LL * put[i - 1] * 2) % 1000000007;
  for (i = 1; i <= m; ++i) {
    cin >> st[i] >> dr[i];
    if (dr[i] - st[i] != 1 && dr[i] - st[i] != k + 1) {
      cout << '0';
      return 0;
    }
    if (dr[i] - st[i] == k + 1) {
      ++p;
      st[p] = st[i];
      dr[p] = dr[i];
      fr[dr[i] - (k + 1)] = true;
      minn = min(minn, dr[i] - (k - 1));
      maxx = max(maxx, dr[i] - (k - 1));
    }
  }
  if (maxx - minn > k) {
    cout << '0';
    return 0;
  }
  n -= k + 1;
  for (i = 1; i <= n; ++i) s[i] = s[i - 1] + (fr[i] == false);
  if (!n) {
    cout << '1';
    return 0;
  }
  ++k;
  if (!fr[1]) {
    dp[1][0] = dp[1][1] = 1;
  } else {
    dp[1][0] = 0;
    dp[1][1] = 1;
  }
  for (i = 2; i <= n; ++i) {
    if (!fr[i]) {
      dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
      if (dp[i][0] >= 1000000007) dp[i][0] -= 1000000007;
      R = i - 1;
      L = max(i - k + 1, 1);
      if (s[L - 1] == L - 1) dp[i][1] = put[s[R] - s[L - 1]];
    } else {
      dp[i][0] = 0;
      R = i - 1;
      L = max(i - k + 1, 1);
      if (s[L - 1] == L - 1) dp[i][1] = put[s[R] - s[L - 1]];
    }
  }
  dp[n][0] += dp[n][1];
  if (dp[n][0] >= 1000000007) dp[n][0] -= 1000000007;
  cout << dp[n][0];
  return 0;
}
