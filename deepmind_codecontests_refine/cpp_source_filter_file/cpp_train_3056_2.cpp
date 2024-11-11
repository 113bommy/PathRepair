#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int n = s.length();
  int i = 1;
  string ans = "/";
  while (i != n) {
    if (s[i] == '/' && s[i - 1] == '/') {
      i++;
    } else {
      ans += s[i];
      i++;
    }
  }
  n = ans.length();
  if (ans[n - 1] == '/') {
    ans = ans.substr(0, n - 1);
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
