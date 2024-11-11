#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  vector<pair<long long, long long> > ans;
  long long cnt1 = 0, cnt2 = 0;
  for (long long i = 0; i < n; ++i) {
    if (s[i] == 'a') ++cnt1;
    if (t[i] == 'a') ++cnt2;
  }
  if ((cnt1 + cnt2) % 2) {
    cout << -1;
    return;
  }
  vector<long long> ab, ba;
  for (long long i = 0; i < n; ++i) {
    if (s[i] == 'a' && t[i] == 'b') ab.push_back(i);
    if (s[i] == 'b' && t[i] == 'a') ba.push_back(i);
  }
  for (long long i = 0; i + 1 < ab.size(); i += 2)
    ans.push_back({ab[i], ab[i + 1]});
  for (long long i = 0; i + 1 < ba.size(); i += 2)
    ans.push_back({ba[i], ba[i + 1]});
  if (ab.size() % 2) {
    ans.push_back({ab[ab.size() - 1], ab[ab.size() - 1]});
    ans.push_back({ab[ab.size() - 1], ba[ab.size() - 1]});
  }
  cout << ans.size() << '\n';
  for (long long i = 0; i < ans.size(); ++i)
    cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
