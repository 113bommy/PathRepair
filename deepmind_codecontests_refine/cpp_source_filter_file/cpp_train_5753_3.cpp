#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 50;
int n, a[N], m;
vector<int> oc[N];
int dp[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<int> xs;
    for (int i = 0; i < (n); ++i) cin >> a[i], xs.push_back(a[i]);
    sort(begin(xs), end(xs));
    xs.resize(unique(begin(xs), end(xs)) - xs.begin());
    m = (int)(xs).size();
    for (int i = 0; i < (m); ++i) oc[i].clear();
    for (int i = 0; i < (n); ++i) {
      a[i] = lower_bound(begin(xs), end(xs), a[i]) - xs.begin();
      oc[a[i]].push_back(i);
    }
    int res = 0;
    for (int i = 0; i < (n); ++i) {
      res = max(res, (int)(oc[i]).size());
      if (i + 1 < n)
        for (int j = 0; j < ((int)(oc[i]).size()); ++j) {
          res = max(res, j + 1 +
                             (int)(oc[i + 1].end() -
                                   lower_bound(begin(oc[i + 1]), end(oc[i + 1]),
                                               oc[i][j])));
        }
    }
    for (int i = 0; i + 1 < m; i++) {
      dp[i] = (int)(oc[i]).size();
      if (i > 0) {
        dp[i] += lower_bound(begin(oc[i - 1]), end(oc[i - 1]), oc[i][0]) -
                 oc[i - 1].begin();
        if (oc[i - 1].back() < oc[i][0])
          dp[i] = dp[i - 1] + (int)(oc[i]).size();
      }
      res = max(res, dp[i] + (int)(oc[i + 1].end() -
                                   lower_bound(begin(oc[i + 1]), end(oc[i + 1]),
                                               oc[i].back())));
    }
    cout << n - res << '\n';
  }
}
