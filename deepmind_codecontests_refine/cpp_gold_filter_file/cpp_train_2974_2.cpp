#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<char> ans;
  for (int i = 0; i < s.size();) {
    if (s[i] != 'o') {
      ans.push_back(s[i]);
      ++i;
    } else {
      if (i + 2 < s.size() && s[i + 1] == 'g' && s[i + 2] == 'o') {
        i = i + 3;
        ans.push_back('*');
        ans.push_back('*');
        ans.push_back('*');
        while (i + 1 < s.size() && s[i] == 'g' && s[i + 1] == 'o') i = i + 2;
      } else {
        ans.push_back(s[i]);
        ++i;
      }
    }
  }
  for (int i = 0; i < ans.size(); i++) cout << ans[i];
  return 0;
}
