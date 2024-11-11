#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int zero = 0, one = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'n')
      one++;
    else if (s[i] == 'r')
      zero++;
  }
  string ans;
  for (int i = 0; i < one; ++i) {
    ans += '1';
  }
  for (int i = 0; i < zero; ++i) {
    ans += '0';
  }
  cout << ans;
}
