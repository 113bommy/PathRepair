#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string ans;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1' || s[i] == '0')
      continue;
    else if (s[i] == '2')
      ans += '2';
    else if (s[i] == '3')
      ans += '3';
    else if (s[i] == '4')
      ans += "322";
    else if (s[i] == '5')
      ans += '5';
    else if (s[i] == '6')
      ans += "53";
    else if (s[i] == '7')
      ans += '7';
    else if (s[i] == '8')
      ans += "7222";
    else
      ans += "7332";
  }
  sort(ans.rbegin(), ans.rend());
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
