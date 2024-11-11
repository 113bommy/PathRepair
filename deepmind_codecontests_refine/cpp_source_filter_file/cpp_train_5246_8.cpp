#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, rs = 0, re = 0, ls = 0, le = 0;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 1; i < s.size() - 1; i++) {
    if (s[i] == 'R' && s[i - 1] != 'R') {
      rs = i + 1;
    }
    if (s[i] == 'R' && s[i + 1] != 'R') {
      re = i + 1;
    }
    if (s[i] == 'L' && s[i - 1] != 'L') {
      ls = i + 1;
    }
    if (s[i] == 'L' && s[i + 1] != 'L') {
      le = i + 1;
    }
  }
  if (rs && re && !ls && !le) {
    cout << rs << " " << re + 1;
  } else if (rs && re) {
    cout << rs << " " << re;
  } else {
    cout << le << " " << ls;
  }
  return 0;
}
