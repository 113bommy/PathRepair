#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k;
  string s;
  map<char, int> mp;
  s = "AHIMOTUVWXY";
  for (i = 0; i < s.length(); i++) mp[s[i]] = 1;
  cin >> s;
  for (i = 0; i < s.length(); i++) {
    if (!mp[s[i]]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  string t = s;
  reverse(s.begin(), s.end());
  if (s == t)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
