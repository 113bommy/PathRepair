#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  long long minutes = 0;
  while (1) {
    if (s[1] == s[3] && s[0] == s[4]) {
      break;
    }
    minutes++;
    s[4]++;
    if (s[4] - '9' == 1) {
      s[4] = '0';
      s[3]++;
    }
    if (s[3] == '6') {
      s[3] = '0';
      s[1]++;
    }
    if (s[0] == '2' && s[1] == '4') {
      s[1] = '0';
      s[0] = '0';
    } else if (s[1] - '9' == 1) {
      s[1] = '0';
      s[0]++;
    }
  }
  cout << minutes;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
