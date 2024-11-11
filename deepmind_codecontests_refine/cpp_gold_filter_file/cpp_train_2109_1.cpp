#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    string s;
    int n;
    cin >> n;
    cin >> s;
    int x = 0, y = n - 1;
    while (s[x] == '0' && x < n) x++;
    while (s[y] == '1' && y >= 0) y--;
    if (y < x)
      cout << s << '\n';
    else {
      string ans = "";
      for (int i = 0; i < x; i++) ans += '0';
      ans += '0';
      for (int i = y; i < n - 1; i++) ans += '1';
      cout << ans << '\n';
    }
  }
}
