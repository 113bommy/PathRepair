#include <bits/stdc++.h>
using namespace std;
int main() {
  bool beg = true;
  bool mid = false;
  bool posi = true;
  string s;
  cin >> s;
  int m;
  int l = -1;
  int n = (int)s.length();
  int i = 0;
  string ans;
  while (i < n) {
    if (beg) {
      if (s[i] == '@') {
        posi = false;
        break;
      }
      ans.push_back(s[i]);
      beg = false;
    } else if (mid) {
      if (s[i] == '@') {
        posi = false;
        break;
      }
      ans.push_back(s[i]);
      ans.push_back(',');
      l = (int)ans.length();
      beg = true;
      mid = false;
    } else {
      if (s[i] == '@') mid = true;
      ans.push_back(s[i]);
    }
    i++;
  }
  if (!posi or mid or l == -1) {
    cout << "No Solution" << endl;
    return 0;
  }
  m = (int)ans.length();
  ans = ans.erase(l - 1, 1);
  cout << ans << endl;
}
