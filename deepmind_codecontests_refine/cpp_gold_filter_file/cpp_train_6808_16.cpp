#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  string ans = "";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '-') {
      if (s[i + 1] == '.')
        ans += '1';
      else
        ans += '2';
      i++;
    } else
      ans += '0';
  }
  cout << ans << endl;
  return 0;
}
