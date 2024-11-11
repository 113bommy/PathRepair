#include <bits/stdc++.h>
using namespace std;
long long int n, t[102], d[102], p[102];
pair<pair<long long int, long long int>, pair<long long int, long long int> >
    pts[102];
pair<long long int, long long int> dp[102][2002];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  long long int ct = 0;
  for (long long int i = 1; i <= n; ++i) {
    cin >> t[i] >> d[i] >> p[i];
    if (t[i] < d[i])
      pts[++ct] = make_pair(make_pair(d[i], i), make_pair(t[i], p[i]));
  }
  if (!ct) {
    cout << 0 << '\n' << 0 << '\n';
    return 0;
  }
  n = ct;
  sort(pts + 1, pts + n + 1);
  for (long long int i = 1; i <= n; ++i)
    for (long long int sum = 0; sum <= 2001; ++sum) dp[i][sum] = {-1LL, -1LL};
  dp[1][pts[1].second.second] = {pts[1].second.first, 1LL};
  for (long long int i = 2; i <= n; ++i)
    for (long long int sum = 1; sum <= 2000; ++sum) {
      dp[i][sum] = dp[i - 1][sum];
      if (sum == pts[i].second.second) {
        if (dp[i][sum] != make_pair(-1LL, -1LL))
          dp[i][sum] = min(dp[i][sum], make_pair(pts[i].second.first, i));
        else
          dp[i][sum] = {pts[i].second.first, i};
      } else if (sum > pts[i].second.second) {
        if (dp[i - 1][sum - pts[i].second.second] != make_pair(-1LL, -1LL) &&
            pts[i].first.first > dp[i - 1][sum - pts[i].second.second].first +
                                     pts[i].second.first) {
          if (dp[i][sum] == make_pair(-1LL, -1LL))
            dp[i][sum] = make_pair(dp[i - 1][sum - pts[i].second.second].first +
                                       pts[i].second.first,
                                   i);
          else
            dp[i][sum] =
                min(dp[i][sum], {dp[i - 1][sum - pts[i].second.second].first +
                                     pts[i].second.first,
                                 i});
        }
      }
    }
  long long int ans = 2000;
  while (ans >= 1 && dp[n][ans] == make_pair(-1LL, -1LL)) ans--;
  if (ans == 0) {
    cout << 0 << '\n' << 0 << '\n';
    return 0;
  }
  cout << ans << '\n';
  vector<long long int> cur;
  long long int st = n, cans = ans;
  while (cans) {
    cur.push_back(pts[dp[st][cans].second].first.second);
    long long int pre = cans;
    cans -= pts[dp[st][cans].second].second.second;
    st = dp[st][pre].second - 1;
  }
  cout << cur.size() << '\n';
  reverse(cur.begin(), cur.end());
  for (long long int v : cur) cout << v << " ";
  cout << '\n';
}
