#include <bits/stdc++.h>
using namespace std;
void testCase() {
  long long n;
  cin >> n;
  vector<string> grid(n);
  vector<pair<long long, long long>> ans;
  for (string &s : grid) cin >> s;
  if (grid[0][1] == grid[1][0]) {
    if (grid[n - 1][n - 2] == grid[0][1]) ans.push_back({n - 1, n - 2});
    if (grid[n - 2][n - 1] == grid[0][1]) ans.push_back({n - 2, n - 1});
  } else if (grid[n - 1][n - 2] == grid[n - 2][n - 1]) {
    if (grid[n - 1][n - 2] == grid[0][1]) ans.push_back({0, 1});
    if (grid[n - 1][n - 2] == grid[1][0]) ans.push_back({1, 0});
  } else {
    if (grid[0][1] == '1') ans.push_back({0, 1});
    if (grid[1][0] == '1') ans.push_back({1, 0});
    if (grid[n - 1][n - 2] == '0') ans.push_back({n - 1, n - 2});
    if (grid[n - 2][n - 1] == '0') ans.push_back({n - 2, n - 1});
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
