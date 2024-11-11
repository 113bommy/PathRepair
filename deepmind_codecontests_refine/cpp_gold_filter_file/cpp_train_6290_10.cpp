#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  while (cin >> s) {
    int ans = 1;
    string s1 = "", s2;
    s1 += s[0];
    int i;
    for (i = 1; i < s.size(); i++) {
      if (s[i] == '0')
        s1 += '0';
      else
        break;
    }
    int n = s.size();
    for (; i < n;) {
      s2 = "";
      s2 += s[i++];
      while (s[i] == '0' && i < n) {
        s2 += s[i++];
      }
      if (s1.size() < s2.size())
        ans = 1;
      else if (s1.size() == s2.size() && s1 < s2)
        ans = 1;
      else
        ans++;
      s1 += s2;
    }
    cout << ans << endl;
  }
  return 0;
}
