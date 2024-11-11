#include <bits/stdc++.h>
using namespace std;
string s, sn, svn;
int i, k;
bool x;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> k;
  cin >> s;
  if (s.size() % k != 0) {
    sn = "1";
    for (i = 1; i <= k - 1; i++) sn += "0";
    for (i = 1; i <= (s.size() + k - 1) / k; i++) cout << sn;
    cout << '\n';
    return 0;
  }
  for (i = 0; i < s.size(); i++)
    if (s[i] != '9') x = true;
  if (!x) {
    sn = "1";
    for (i = 1; i <= k - 1; i++) sn += "0";
    for (i = 1; i <= (s.size() + k - 1) / k; i++) cout << sn;
    cout << '\n';
    return 0;
  }
  sn = s.substr(0, k);
  for (i = 0; i < s.size() / k; i++) svn += sn;
  if (svn <= s) {
    for (i = sn.size() - 1; i >= 0; i--)
      if (sn[i] == '9')
        sn[i] = '0';
      else {
        sn[i]++;
        break;
      }
    for (i = 0; i < s.size() / k; i++) cout << sn;
    cout << '\n';
    return 0;
  }
  cout << svn << '\n';
  return 0;
}
