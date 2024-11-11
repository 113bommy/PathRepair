#include <bits/stdc++.h>
const int INF = 2e9;
const int mod = 1e9 + 7;
using namespace std;
void solve() {
  vector<pair<int, long long> > ans;
  ans.emplace_back(-1e9, 0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int t;
    long long s = ans.back().second + 20;
    cin >> t;
    auto it = prev(
        upper_bound(ans.begin(), ans.end(), pair<int, long long>(t - 90, -1)));
    s = min(s, it->second + 50);
    it = prev(upper_bound(ans.begin(), ans.end(),
                          pair<int, long long>(t - 1440, -1)));
    s = min(s, it->second + 120);
    printf("%I64d\n", s - ans.back().second);
    ans.emplace_back(t, s);
  }
}
int main() {
  solve();
  return 0;
}
