#include <bits/stdc++.h>
using namespace std;
void next(string &s) {
  int i = s.size() - 1;
  while (s[i] == '9' && i >= 0) {
    s[i] = '0';
    i--;
  }
  if (i == -1) {
    s = '1' + s;
  } else {
    s[i]++;
  }
}
int dist(string t, string s) {
  int res = 0;
  for (int i = 0; i < 6; ++i) {
    res += (t[i] != s[i]);
  }
  return res;
}
int main() {
  string t;
  cin >> t;
  int ans = 1e9;
  string s = "000000";
  while (s != "999999") {
    if (s[0] + s[1] + s[2] == s[3] + s[4] + s[5]) {
      ans = min(ans, dist(t, s));
    }
    next(s);
  }
  cout << ans << endl;
  return 0;
}
