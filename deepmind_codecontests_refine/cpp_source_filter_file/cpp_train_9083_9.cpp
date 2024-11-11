#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<pair<int, int>> s;
vector<vector<int>> dp;
vector<vector<int>> in;
int n;
int calc(int l, int r) {
  if (l > r) return 0;
  int &ret = dp[l][r];
  if (ret != -1) return ret;
  ret = calc(l + 1, r);
  for (int nr : in[l]) {
    if (nr >= r) break;
    ret = max(ret, calc(l, nr) + calc(nr + 1, r));
  }
  ret += count((in[l]).begin(), (in[l]).end(), r);
  return ret;
}
void solve() {
  cin >> n;
  s.clear();
  s.resize(n);
  vector<int> st;
  for (int i = 0; i < n; i++) {
    cin >> s[i].first >> s[i].second;
    st.push_back(s[i].first);
    st.push_back(s[i].second);
  }
  sort(st.begin(), st.end());
  st.resize(unique(st.begin(), st.end()) - st.begin());
  int cnt = st.size();
  dp.clear();
  in.clear();
  dp.resize(cnt + 1, vector<int>(cnt + 1, -1));
  in.resize(cnt + 1);
  for (int i = 0; i < s.size(); i++) {
    s[i].first = lower_bound(st.begin(), st.end(), s[i].first) - st.begin();
    s[i].second = lower_bound(st.begin(), st.end(), s[i].second) - st.begin();
    in[s[i].first].push_back(s[i].second);
  }
  for (int i = 1; i <= cnt; i++) sort((in[i]).begin(), (in[i]).end());
  cout << calc(0, cnt) << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
