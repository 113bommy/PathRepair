#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, k, m, n, t;
  cin >> n;
  string s[n];
  vector<pair<long long int, long long int>> v;
  for (i = 0; i < n; i++) cin >> s[i];
  for (i = 0; i < n; i++) {
    bool fl = false;
    for (j = 0; j < n; j++)
      if (s[i][j] == '.') {
        v.push_back({i, j});
        break;
      }
  }
  if (v.size() == n) {
    for (auto x : v) cout << x.first + 1 << ' ' << x.second + 1 << endl;
    return 0;
  }
  v.clear();
  for (i = 0; i < n; i++) {
    bool fl = false;
    for (j = 0; j < n; j++)
      if (s[j][i] == '.') {
        v.push_back({i, j});
        break;
      }
  }
  if (v.size() == n) {
    for (auto x : v) cout << x.first + 1 << ' ' << x.second + 1 << endl;
    return 0;
  }
  cout << -1;
}
