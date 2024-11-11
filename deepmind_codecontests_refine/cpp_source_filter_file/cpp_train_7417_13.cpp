#include <bits/stdc++.h>
using namespace std;
int solve() {
  int n, x, count = 1;
  string s;
  cin >> s;
  cout << s[0];
  for (int i = 1; i < s.size(); i++) {
    if (s[i] != s[i - 1] || count > 1) {
      cout << s[i];
      count = 1;
    } else
      count++;
  }
  return (0);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    int c = solve();
    cout << endl;
  }
}
