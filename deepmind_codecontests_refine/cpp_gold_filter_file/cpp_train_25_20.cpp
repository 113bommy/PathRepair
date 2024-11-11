#include <bits/stdc++.h>
const int INF = 1 << 29;
const double PI = acos(-1.0);
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<string> v(n);
  vector<pair<int, int>> ans;
  for (string &it : v) cin >> it;
  char a = v[0][1], b = v[1][0], c = v[n - 1][n - 2], d = v[n - 2][n - 1];
  if (a == '1' && b == '1') {
    if (c != '0') ans.push_back(make_pair(n, n - 1));
    if (d != '0') ans.push_back(make_pair(n - 1, n));
  } else if (a == '0' && b == '0') {
    if (c != '1') ans.push_back(make_pair(n, n - 1));
    if (d != '1') ans.push_back(make_pair(n - 1, n));
  } else if (c == d) {
    if (c == '0') {
      if (a == '0')
        ans.push_back(make_pair(1, 2));
      else if (b == '0')
        ans.push_back(make_pair(2, 1));
    } else {
      if (a == '1')
        ans.push_back(make_pair(1, 2));
      else if (b == '1')
        ans.push_back(make_pair(2, 1));
    }
  } else {
    if (a == '0')
      ans.push_back(make_pair(1, 2));
    else if (b == '0')
      ans.push_back(make_pair(2, 1));
    if (c == '1')
      ans.push_back(make_pair(n, n - 1));
    else if (d == '1')
      ans.push_back(make_pair(n - 1, n));
  }
  cout << ans.size() << endl;
  for (auto it : ans) cout << it.first << ' ' << it.second << endl;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
