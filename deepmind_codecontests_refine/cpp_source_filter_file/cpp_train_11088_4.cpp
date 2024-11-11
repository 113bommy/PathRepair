#include <bits/stdc++.h>
using namespace std;
int main() {
  int ans = 0;
  string s;
  int n;
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      ++ans;
      ++i;
      while (i < n && s[i] == '0') ++i;
    }
    if (i < n && s[i] == '1') {
      ++ans;
      ++i;
      while (i < n && s[i] == '1') ++i;
    }
  }
  ans = min(n, ans + 2);
  cout << ans;
  return 0;
}
