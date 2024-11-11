#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long row = 0, col = 0;
  vector<pair<long long, long long>> ans;
  for (long long i = 0; i < n; i++) {
    ans.push_back({row, col});
    ans.push_back({row + 1, col});
    ans.push_back({row, col + 1});
    row++;
    col++;
  }
  ans.push_back({row, col});
  cout << ans.size() << '\n';
  for (auto &i : ans) cout << i.first << " " << i.second << '\n';
  return 0;
}
