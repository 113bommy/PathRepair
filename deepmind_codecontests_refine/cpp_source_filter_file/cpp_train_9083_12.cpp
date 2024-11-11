#include <bits/stdc++.h>
using namespace std;
bool chmin(int& a, int b) { return b < a ? a = b, true : false; }
bool chmax(int& a, int b) { return b > a ? a = b, true : false; }
bool chmin(long long& a, long long b) { return b < a ? a = b, true : false; }
bool chmax(long long& a, long long b) { return b > a ? a = b, true : false; }
const int inf = 1e09 + 5e3;
const long long linf = 2e18 + 5e3;
const int mod = 1e9 + 7;
const int mxn = 2e5 + 30;
int n, last;
vector<vector<int>> memo;
vector<pair<int, int>> ini;
vector<int> nxt;
int dp(int a, int e) {
  if (a == n || e < ini[a].second) return 0;
  if (~memo[a][e]) return memo[a][e];
  int ret = dp(a + 1, e);
  if (e >= ini[a].second)
    chmax(ret, 1 + dp(a + 1, ini[a].second) + dp(nxt[a], e));
  return memo[a][e] = ret;
}
void solve() {
  int temp, temp2;
  ini.clear();
  last = 0;
  cin >> n;
  map<int, pair<vector<int>, vector<int>>> mco;
  for (int i = 0; i < n; i++) {
    cin >> temp >> temp2;
    ini.push_back({temp, temp2});
    mco[temp].first.push_back(i);
    mco[temp2].second.push_back(i);
  }
  for (auto blah : mco) {
    for (auto bl : blah.second.first) ini[bl].first = last;
    for (auto bl : blah.second.second) ini[bl].second = last;
    last++;
  }
  memo.assign(n + 2, vector<int>(last + 5, -1));
  sort((ini).begin(), (ini).end(),
       [&](pair<int, int>& lhs, pair<int, int>& rhs) {
         return lhs.first == rhs.first ? lhs.second > rhs.second
                                       : lhs.first < rhs.first;
       });
  vector<pair<int, int>> vt;
  for (int i = 0; i < n; i++) {
    vt.push_back({ini[i].first, i});
  }
  vt.push_back({inf, n});
  sort((vt).begin(), (vt).end());
  nxt.assign(n, n);
  for (int i = 0; i < n; i++) {
    nxt[i] = (*upper_bound((vt).begin(), (vt).end(),
                           pair<int, int>(ini[i].second, inf)))
                 .second;
  }
  cout << dp(0, last + 1) << '\n';
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
