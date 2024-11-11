#include <bits/stdc++.h>
using namespace std;
vector<int> l[26];
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) l[s[i] - 'a'].push_back(i);
  string ans = "";
  int m = -1;
  for (int i = 25; i >= 0; i--) {
    for (int j = 0; j < l[i].size(); j++)
      if (l[i][j] > m) {
        ans += (char)('a' + i);
        m = max(m, l[i][j]);
      }
  }
  cout << ans;
}
