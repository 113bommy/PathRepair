#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), pref(n), suf(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> dp(n + 1, INF);
  dp[0] = -INF;
  int mx_len = 1;
  for (int i = 0; i < n; i++) {
    int id = upper_bound((dp).begin(), (dp).end(), a[i]) - dp.begin();
    pref[i] = id;
    if (dp[id] > a[i]) dp[id] = a[i];
    mx_len = max(mx_len, id);
  }
  dp = vector<int>(n + 1, INF);
  dp[0] = -INF;
  map<pair<int, int>, int> mp;
  for (int i = n - 1; i >= 0; i--) {
    int id = upper_bound((dp).begin(), (dp).end(), -a[i]) - dp.begin();
    suf[i] = id;
    if (dp[id] > -a[i]) dp[id] = -a[i];
    mp[{pref[i], suf[i]}]++;
  }
  for (int i = 0; i < n; i++) {
    if (pref[i] + suf[i] - 1 != mx_len) {
      cout << 1;
      continue;
    }
    cout << (mp[{pref[i], suf[i]}] != 1 ? 2 : 3);
  }
}
int main() {
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(20);
  solve();
}
