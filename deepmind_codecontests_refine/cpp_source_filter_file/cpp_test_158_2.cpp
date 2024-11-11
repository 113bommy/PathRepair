#include <bits/stdc++.h>
using namespace std;
int e[11];
vector<int> score(10010);
vector<int> ans;
string s[11];
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> e[i];
  for (int i = 1; i <= n; i++) cin >> s[i];
  int up = 1 << n;
  int mx = 0;
  vector<pair<int, int> > ev(m + 1);
  for (int i = 0; i < up; i++) {
    for (int j = 1; j <= m; j++) {
      ev[j].first = 0;
      ev[j].second = j;
    }
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= m; k++) {
        if (s[j][k - 1] == '1') ev[k].first += (i & 1 << j - 1) ? 1 : -1;
      }
    int sum = 0;
    for (int j = 1; j <= n; j++) sum += (i & 1 << j - 1) ? -e[j] : e[j];
    sort(ev.begin() + 1, ev.end());
    for (int j = 1; j <= m; j++) {
      score[ev[j].second] = j;
      sum += j * ev[j].first;
    }
    if (mx < sum) {
      mx = sum;
      ans = score;
    }
  }
  for (int i = 1; i <= m; i++) cout << ans[i] << " \n"[i == m];
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
