#include <bits/stdc++.h>
using namespace std;
long long n, m, k, s[100005], t[100005], d[100005], w[100005], active[100005];
long long dp[100005][202];
vector<long long> op[100005], cl[100005];
long long go(long long pos, long long rem) {
  if (pos == n + 1) return 0;
  long long &ans = dp[pos][rem];
  if (ans != -1) return ans;
  if (active[pos] == 0) return ans = go(pos + 1, rem);
  ans = go(d[active[pos]] + 1, rem) + w[active[pos]];
  if (rem) ans = min(ans, go(pos + 1, rem - 1));
  return ans;
}
set<pair<pair<long long, long long>, long long>> st;
void solve() {
  memset(dp, -1, sizeof dp);
  cin >> n >> m >> k;
  for (long long i = 1; i < k + 1; i++) {
    cin >> s[i] >> t[i] >> d[i] >> w[i];
    op[s[i]].push_back(i);
    cl[t[i]].push_back(i);
  }
  for (long long i = 1; i < n + 1; i++) {
    for (auto j : op[i]) {
      st.insert({{w[j], -d[j]}, j});
    }
    if ((long long)st.size()) active[i] = (*st.rbegin()).second;
    for (auto j : cl[i]) {
      st.erase({{w[j], -d[j]}, j});
    }
  }
  cout << go(1, m) << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
