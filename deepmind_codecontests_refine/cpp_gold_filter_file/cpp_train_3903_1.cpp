#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == '4') {
      s[i] = '1';
    } else {
      s[i] = '2';
    }
  }
  int tot = 0;
  int cur = 1;
  for (int i = n - 1; i >= 0; i--) {
    tot += (s[i] - '0') * cur;
    cur *= 2;
  }
  cout << tot << '\n';
  return 0;
}
