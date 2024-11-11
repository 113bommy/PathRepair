#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 100005;
const ll INF = 100000000009;
const ll MOD = (ll)1e9 + 7;
ll m[MAXN];
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<ll, int>> maxS;
  ll curMax = -1;
  for (int i = 0; i < n; ++i) {
    cin >> m[i];
    if (m[i] > curMax) {
      curMax = m[i];
      maxS.emplace_back(make_pair(curMax, i));
    }
  }
  ll ans = 0;
  vector<ll> allS;
  int lastMaxPos = maxS.back().second;
  for (int j = lastMaxPos + 1; j < n; ++j) {
    ans += m[lastMaxPos] + 1 - m[j] - 1;
    allS.push_back(m[lastMaxPos] + 1);
  }
  int f1 = maxS.size() - 1;
  while (f1 > 0) {
    int f2 = f1 - 1;
    ll curRightVal = maxS[f1].first;
    int curRightPos = maxS[f1].second;
    while (f2 >= 0 &&
           curRightVal - maxS[f2].first > curRightPos - maxS[f2].second) {
      --f2;
    }
    ll curLeftVal = maxS[f2].first;
    int curLeftPos = maxS[f2].second;
    allS.push_back(m[curRightPos] + 1);
    int delta = int(curRightVal - curLeftVal);
    ll curVal = curRightVal + 1;
    for (int j = 1; j <= delta; ++j) {
      --curVal;
      allS.push_back(curVal);
      ans += curVal - m[curRightPos - j] - 1;
    }
    for (int j = curRightPos - delta - 1; j > curLeftPos; --j) {
      ans += curVal - m[j] - 1;
      allS.push_back(curVal);
    }
    f1 = f2;
  }
  reverse(allS.begin(), allS.end());
  cout << ans;
  return 0;
}
