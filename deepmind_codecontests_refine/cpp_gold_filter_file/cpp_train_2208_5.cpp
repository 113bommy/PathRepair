#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e9;
const long long base = 998244353;
long long mod = 1e9 + 7;
void solve() {
  string s;
  cin >> s;
  int n = s.length();
  string cur_s = "";
  vector<int> ans;
  vector<int> pos(30);
  for (int i = 0; i < n; ++i) {
    cur_s.push_back(s[i]);
    pos[s[i] - 'a'] = i;
    if (cur_s.length() >= 3) {
      string last = cur_s.substr(cur_s.length() - 3, 3);
      if (last == "one") {
        char last_sym = cur_s.back();
        cur_s.pop_back();
        char to_ans = cur_s.back();
        cur_s.pop_back();
        cur_s.push_back(last_sym);
        ans.push_back(pos[to_ans - 'a'] + 1);
      } else if (last == "two") {
        if (i == n - 1) {
          ans.push_back(n);
        } else if (s[i + 1] != 'o') {
          ans.push_back(i + 1);
          cur_s.pop_back();
        } else {
          ans.push_back(pos['w' - 'a'] + 1);
          cur_s.pop_back();
          cur_s.pop_back();
          cur_s.push_back('o');
        }
      }
    }
  }
  cout << ans.size() << '\n';
  for (auto c : ans) {
    cout << c << ' ';
  }
  cout << '\n';
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  auto start = clock();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  std::cerr << double(clock() - start) / CLOCKS_PER_SEC << std::endl;
  return 0;
}
