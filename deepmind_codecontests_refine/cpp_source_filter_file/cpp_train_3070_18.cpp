#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s, t;
  int i;
  cin >> s >> t;
  bool flag = false;
  int len = s.length();
  string ans = "";
  for (i = 0; i < len; i++) {
    if (s[i] != t[i]) {
      if (flag == true) {
        ans += '1';
        flag = false;
      } else {
        ans += '0';
        flag = true;
      }
    } else
      ans += s[i];
  }
  if (flag == true)
    cout << "impossible" << endl;
  else
    cout << ans << endl;
  return 0;
}
