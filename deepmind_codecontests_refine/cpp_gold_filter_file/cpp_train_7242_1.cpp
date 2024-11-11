#include <bits/stdc++.h>
using namespace std;
string s;
map<char, int> mp;
int main() {
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    mp[s[i]]++;
  }
  int ans = 1e5;
  ans = min(ans, mp['B']);
  ans = min(ans, mp['u'] / 2);
  ans = min(ans, mp['l']);
  ans = min(ans, mp['b']);
  ans = min(ans, mp['a'] / 2);
  ans = min(ans, mp['s']);
  ans = min(ans, mp['r']);
  cout << ans << endl;
  return 0;
}
