#include <bits/stdc++.h>
using namespace std;
std::vector<int> v = {1, 2, 3, 4, 6, 12};
string s;
void solve() {
  cin >> s;
  std::vector<int> ans;
  for (int i = 0; i < 6; ++i) {
    std::vector<int> p(12 / v[i], 1);
    for (int j = 0; j < s.size(); ++j) {
      if (p[j % (12 / v[i])] && s[j] == 'X') continue;
      p[j % (12 / v[i])] = 0;
    }
    for (auto k : p)
      if (k) {
        ans.push_back(v[i]);
        break;
      }
  }
  cout << ans.size();
  for (auto&& i : ans) {
    cout << " " << i << "x" << 12 / i;
  }
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
