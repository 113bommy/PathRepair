#include <bits/stdc++.h>
using namespace std;
const int MAX = 200005;
int main() {
  string s, t;
  cin >> s >> t;
  string ans;
  ans += s[0];
  bool flag = false;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] > t[0]) {
      ans += t[0];
      flag = true;
      break;
    }
    ans += s[i];
  }
  if (flag == false) {
    ans += t[0];
  }
  cout << ans << endl;
  return 0;
}
