#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void solve() {
  long long n, m;
  cin >> n >> m;
  string a[n];
  for (string &i : a) cin >> i;
  vector<vector<int> > ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '1') {
        pair<int, int> r, d, c;
        r.second = ((j == m) ? j - 1 : j + 1);
        r.first = i;
        d.first = ((i) ? i - 1 : i + 1);
        d.second = ((j == m) ? j - 1 : j + 1);
        c.first = ((i) ? i - 1 : i + 1);
        c.second = j;
        ans.push_back({i, j, r.first, r.second, c.first, c.second});
        ans.push_back({i, j, r.first, r.second, d.first, d.second});
        ans.push_back({i, j, c.first, c.second, d.first, d.second});
      }
    }
  }
  cout << ans.size() << '\n';
  for (vector<int> &i : ans) {
    for (int j : i) cout << j + 1 << ' ';
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve(), cout << '\n';
}
