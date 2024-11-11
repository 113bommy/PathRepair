#include <bits/stdc++.h>
using namespace std;
int m, n, dp[102][102];
vector<pair<int, int> > v[102];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> m >> n;
  for (int i = (1); i <= (m); ++i) {
    int k;
    cin >> k;
    for (int j = (1); j <= (k); ++j) {
      int l, r;
      cin >> l >> r;
      for (int x = (l); x <= (r); ++x) v[x].push_back(make_pair(l, r));
    }
  }
  for (int l = (n); l >= (1); --l)
    for (int r = (l); r <= (n); ++r) {
      for (int k = (l); k <= (r); ++k) {
        int cnt = 0;
        for (auto p : v[k]) cnt += (l <= p.first && p.second <= r);
        dp[l][r] = max(dp[l][r], dp[l][k - 1] + dp[k + 1][r] + cnt * cnt);
      }
    }
  cout << dp[1][n];
  return 0;
}
