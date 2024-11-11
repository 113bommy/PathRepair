#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0;
  string s;
  cin >> n >> s;
  int idx = n;
  while (idx <= s.length()) {
    if (s[idx - 1] == s[idx - 2] && s[idx - 2] == s[idx - 3]) ans++;
    idx *= n;
  }
  cout << ans;
  return 0;
}
