#include <bits/stdc++.h>
using namespace std;
int n;
string s;
void solve() {
  cin >> n;
  cin >> s;
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a')
      x++;
    else
      y++;
  }
  if (x == 0 || y == 0) {
    cout << -1 << " " << -1 << endl;
    return;
  }
  for (int i = 0; i + 1 < s.length(); i++) {
    if (s[i] != s[i + 1]) {
      cout << i << " " << i + 1 << endl;
      return;
    }
  }
}
int main() {
  int T = 1;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
