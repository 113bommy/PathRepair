#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
long long a, n, m, k, dp[2005][2005], rain[2005], umb[2005], weight[2005];
long long solve(long long pos, long long umbrellaIdx) {
  if (pos == a + 1) return 0;
  long long ans = dp[pos][umbrellaIdx];
  if (ans != -1) return ans;
  ans = inf;
  if (!rain[pos])
    ans = min({solve(pos + 1, 0),
               weight[umbrellaIdx] + solve(pos + 1, umbrellaIdx),
               weight[pos] + solve(pos + 1, pos)});
  else {
    if (weight[umbrellaIdx])
      ans = weight[umbrellaIdx] + solve(pos + 1, umbrellaIdx);
    if (weight[pos]) ans = min(ans, weight[pos] + solve(pos + 1, pos));
  }
  return dp[pos][umbrellaIdx] = ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> a >> n >> m;
  a++;
  vector<pair<long long, long long>> duo;
  long long l, r;
  for (long long i = 1; i <= n; i++) {
    cin >> l >> r;
    l++;
    duo.push_back({l, r});
  }
  for (int i = 0; i < duo.size(); i++) {
    l = duo[i].first;
    r = duo[i].second;
    for (long long j = l; j <= r; j++) rain[j] = 1;
  }
  for (int i = 1; i <= m; i++) {
    cin >> l >> r;
    l++;
    umb[l] = 1;
    if (!weight[l])
      weight[l] = r;
    else
      weight[l] = min(weight[l], r);
  }
  memset(dp, -1, sizeof(dp));
  if (solve(1, 0) < 1e18)
    cout << solve(1, 0);
  else
    cout << -1;
  return 0;
}
