#include <bits/stdc++.h>
using namespace std;
int dp[305][100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int n, m, s, e;
  cin >> n >> m >> s >> e;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> b(m);
  for (int i = 0; i < m; i++) cin >> b[i];
  vector<pair<int, int> > v(m);
  for (int i = 0; i < m; i++) v[i] = make_pair(b[i], i);
  sort(v.begin(), v.end());
  for (int i = 0; i < 305; i++)
    for (int j = 0; j < 100005; j++) dp[i][j] = INT_MAX;
  int ans = 0;
  dp[0][0] = 0;
  for (int k = 0; k < 301; k++) {
    int ini = INT_MAX;
    for (int j = 0; j < n; j++) {
      ini = min(ini, dp[k][j]);
      if (ini == INT_MAX) continue;
      pair<int, int> key = make_pair(a[j], ini);
      vector<pair<int, int> >::iterator it =
          lower_bound(v.begin(), v.end(), key);
      if (it == v.end()) continue;
      int value = (*it).first;
      int index = (*it).second;
      int t = s - e * (k + 1) - j - index - 2;
      if (a[j] == value and t >= 0) {
        ans = k + 1;
        dp[k + 1][j + 1] = index + 1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
