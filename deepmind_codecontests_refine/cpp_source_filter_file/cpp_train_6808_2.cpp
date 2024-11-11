#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  vector<int> ans;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '-' && s[i + 1] == '.') {
      ans.push_back(1);
      i = i + 1;
    } else if (s[i] == '.')
      ans.push_back(0);
    else if (s[i] == '-' && s[i + 1] == '-') {
      ans.push_back(2);
      i = i + 1;
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
