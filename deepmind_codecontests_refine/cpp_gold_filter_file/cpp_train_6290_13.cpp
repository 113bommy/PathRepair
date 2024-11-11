#include <bits/stdc++.h>
using namespace std;
int z[100009];
bool compare(string a, string b) {
  if (a.size() > b.size()) return true;
  if (b.size() > a.size()) return false;
  return a >= b;
}
int main() {
  int lst, ans = 0;
  string s, t;
  cin >> s;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '0')
      z[lst] = i - lst;
    else
      lst = i;
  for (int i = 0; i < s.size();) {
    if (!z[i]) {
      if (!t.size())
        t += s[i], ans++;
      else if (t.size() == 1) {
        if (t[0] - '0' >= s[i] - '0')
          t += s[i], ans++;
        else
          t += s[i], ans = 1;
      } else
        t += s[i], ans++;
      i++;
    } else {
      string x = s.substr(i, z[i] + 1);
      if (t.size()) {
        if (compare(t, x)) {
          ans++;
          t += x;
        } else {
          t += x;
          ans = 1;
        }
      } else {
        t = x;
        ans = 1;
      }
      i += z[i] + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
