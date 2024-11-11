#include <bits/stdc++.h>
using namespace std;
void testCase() {
  long long n;
  cin >> n;
  vector<string> grid(n);
  vector<pair<long long, long long>> ans;
  for (string &s : grid) cin >> s;
  char t1 = grid[0][1];
  char t2 = grid[1][0];
  char b1 = grid[n - 1][n - 2];
  char b2 = grid[n - 2][n - 1];
  if (t1 == t2) {
    if (b1 == t2) ans.push_back({n - 1, n - 2});
    if (b2 == t2) ans.push_back({n - 2, n - 1});
  } else if (b1 == b2) {
    if (b1 == t1) ans.push_back({0, 1});
    if (b1 == t2) ans.push_back({1, 0});
  } else {
    if (t1 == '1') ans.push_back({0, 1});
    if (t2 == '1') ans.push_back({1, 0});
    if (b1 == '0') ans.push_back({n - 1, n - 2});
    if (b2 == '0') ans.push_back({n - 2, n - 1});
  }
  cout << (long long)(ans.size()) << endl;
  for (auto &it : ans) cout << it.first + 1 << " " << it.second + 1 << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cin.tie(nullptr);
  long long t_c = 1;
  cin >> t_c;
  while (t_c--) testCase();
}
