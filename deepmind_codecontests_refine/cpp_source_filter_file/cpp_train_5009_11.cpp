#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL * 1000 * 1000 * 1000 * 1000 * 1000;
const long long MOD = 998244353;
bool cmp1(const pair<long long, long long>& one,
          const pair<long long, long long>& two) {
  return max(one.first, one.second) < max(two.first, two.second);
}
bool cmp2(const pair<long long, long long>& one,
          const pair<long long, long long>& two) {
  return one.first == two.first ? one.second < two.second
                                : one.first < two.first;
}
long long getLen(long long x, long long q, long long y, long long z,
                 vector<vector<pair<long long, long long>>>& b) {
  return abs(b[x][q ? b[x].size() - 1 : 0].first -
             b[y][z ? b[y].size() - 1 : 0].first) +
         abs(b[x][q ? b[x].size() - 1 : 0].second -
             b[y][z ? b[y].size() - 1 : 0].second);
}
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end(), cmp1);
  vector<vector<pair<long long, long long>>> b;
  b.push_back({{0, 0}});
  for (long long i = 0; i < n; i++) {
    if (b.empty() || max(b[b.size() - 1][0].first, b[b.size() - 1][0].second) !=
                         max(a[i].first, a[i].second)) {
      b.push_back({a[i]});
    } else {
      b[b.size() - 1].push_back(a[i]);
    }
  }
  for (long long i = 0; i < b.size(); i++) {
    sort(b[i].begin(), b[i].end(), cmp2);
  }
  long long ans = 0;
  vector<vector<long long>> dp(b.size(), vector<long long>(2));
  vector<long long> len(b.size());
  for (long long i = 0; i < b.size(); i++) {
    len[i] = getLen(i, 0, i, 1, b);
    ans += len[i];
  }
  for (long long i = b.size() - 2; i >= 0; i--) {
    dp[i][0] = min(dp[i + 1][0] + getLen(i, 0, i + 1, 1, b),
                   dp[i + 1][1] + getLen(i, 0, i + 1, 0, b));
    dp[i][1] = min(dp[i + 1][1] + getLen(i, 1, i + 1, 0, b),
                   dp[i + 1][0] + getLen(i, 1, i + 1, 1, b));
  }
  ans += min(dp[0][0], dp[0][1]);
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.precision(12);
  solve();
}
