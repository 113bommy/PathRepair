#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;
const int INF = 1e9;
long long n, k;
long long h[200001];
long long kol[200001];
pair<long long, int> dp[200001][2];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  long long maxx = -1;
  long long minn = INF;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    maxx = max(maxx, h[i]);
    minn = min(minn, h[i]);
  }
  if (minn == maxx) {
    cout << "0";
    return 0;
  }
  sort(h + 1, h + n + 1);
  int j = 0;
  for (int i = minn; i <= maxx; i++) {
    while (h[j + 1] < i && j < n) j++;
    kol[i] = n - j;
  }
  for (int i = 1; i <= maxx; i++) dp[i][0].second = dp[i][1].second = -1;
  dp[minn][0].second = 0;
  for (int i = minn + 1; i <= maxx; i++) {
    if (dp[i - 1][0].first <= k && dp[i - 1][0].second != -1)
      dp[i][0] = make_pair(kol[i], dp[i - 1][0].second + 1);
    if (dp[i - 1][1].first <= k &&
        (dp[i - 1][1].second + 1 < dp[i][0].second || dp[i][0].second == -1) &&
        dp[i - 1][1].second != -1)
      dp[i][0] = make_pair(kol[i], dp[i - 1][1].second + 1);
    if (i > minn + 1) {
      if (dp[i - 1][0].first + kol[i] <= k && dp[i - 1][0].second != -1)
        dp[i][1] = make_pair(dp[i - 1][0].first + kol[i], dp[i - 1][0].second);
      if (dp[i - 1][1].first + kol[i] <= k &&
          (dp[i - 1][1].second < dp[i][1].second || dp[i][1].second == -1) &&
          dp[i - 1][1].second != -1)
        dp[i][1] = make_pair(dp[i - 1][1].first + kol[i], dp[i - 1][1].second);
    }
  }
  int ans = INF;
  if (dp[maxx][1].second != -1) ans = dp[maxx][1].second;
  if (dp[maxx][0].second != -1) ans = min(ans, dp[maxx][0].second);
  cout << ans;
  return 0;
}
