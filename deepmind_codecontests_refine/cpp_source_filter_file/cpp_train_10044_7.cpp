#include <bits/stdc++.h>
using namespace std;
int dp[200001];
int main() {
  cout.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    int x, w;
    cin >> x >> w;
    v.push_back(make_pair(x - w, x + w));
  }
  sort(v.begin(), v.end());
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    int idx =
        lower_bound(v.begin(), v.end(), make_pair(v[i].second, -INT_MAX)) -
        v.begin();
    if (idx < n) {
      dp[idx] = max(dp[idx], dp[i] + 1);
    }
    if (i) dp[i + 1] = max(dp[i + 1], dp[i]);
  }
  cout << dp[n - 1] << endl;
}
