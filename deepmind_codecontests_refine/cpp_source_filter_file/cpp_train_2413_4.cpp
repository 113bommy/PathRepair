#include <bits/stdc++.h>
using namespace std;
set<long long> Set;
map<long long, vector<long long>> mp;
const long long N = 2e5 + 11;
long long dp[2][N];
const long long inf = 1e9;
int32_t main() {
  for (long long i = 0; i < N; ++i) dp[0][i] = dp[1][i] = inf;
  long long n, m, k, q;
  cin >> n >> m >> k >> q;
  for (long long i = 0; i < k; ++i) {
    long long r, c;
    cin >> r >> c;
    mp[r].push_back(c);
  }
  while (q--) {
    long long b;
    cin >> b;
    Set.insert(b);
  }
  Set.insert(0);
  Set.insert(m + 1);
  mp[1].push_back(1);
  for (auto x : mp) {
    long long f = x.first;
    sort(mp[f].begin(), mp[f].end());
  }
  long long i = 1;
  long long f = mp[1].back();
  long long l = mp[1].back();
  dp[0][i - 1] = f - 1;
  dp[1][i - 1] = f - 1;
  long long prev = 1;
  for (auto x : mp) {
    long long ff = x.first;
    if (ff == 1) continue;
    long long f_elem = mp[ff][0];
    long long l_elem = mp[ff].back();
    auto it = Set.upper_bound(f);
    long long l1 = *it;
    --it;
    long long f1 = *it;
    it = Set.upper_bound(l);
    long long l2 = *it;
    --it;
    long long f2 = *it;
    if (f1 != 0)
      dp[0][i] =
          dp[0][i - 1] + abs(l_elem - f1) + abs(l_elem - f_elem) + abs(f1 - f);
    if (l1 != (m + 1))
      dp[0][i] = min(dp[0][i], dp[0][i - 1] + abs(l_elem - l1) +
                                   abs(l_elem - f_elem) + abs(l1 - f));
    if (f2 != 0)
      dp[0][i] = min(dp[0][i], dp[1][i - 1] + abs(l_elem - f2) +
                                   abs(l_elem - f_elem) + abs(f2 - l));
    if (l2 != (m + 1))
      dp[0][i] = min(dp[0][i], dp[1][i - 1] + abs(l_elem - l2) +
                                   abs(l_elem - f_elem) + abs(l2 - l));
    if (f1 != 0)
      dp[1][i] =
          dp[0][i - 1] + abs(f_elem - f1) + abs(l_elem - f_elem) + abs(f1 - f);
    if (l1 != (m + 1))
      dp[1][i] = min(dp[1][i], dp[0][i - 1] + abs(f_elem - l1) +
                                   abs(l_elem - f_elem) + abs(l1 - f));
    if (f2 != 0)
      dp[1][i] = min(dp[1][i], dp[1][i - 1] + abs(f_elem - f2) +
                                   abs(l_elem - f_elem) + abs(f2 - l));
    if (l2 != (m + 1))
      dp[1][i] = min(dp[1][i], dp[1][i - 1] + abs(f_elem - l2) +
                                   abs(l_elem - f_elem) + abs(l2 - l));
    f = mp[ff][0];
    l = mp[ff].back();
    dp[0][i] += (ff - prev);
    dp[1][i] += (ff - prev);
    prev = ff;
    i++;
  }
  long long ans = min(dp[0][i - 1], dp[1][i - 1]);
  cout << ans;
  return 0;
}
