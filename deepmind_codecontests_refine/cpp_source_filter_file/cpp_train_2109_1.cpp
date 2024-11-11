#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, x = 0, y = 0;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 0) {
      x++;
    } else {
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 0) {
      y++;
    } else {
      break;
    }
  }
  if (x + y == n) {
    cout << s << endl;
  } else {
    string s1 = "";
    for (int i = 0; i < x; i++) {
      s1 += (char)('0');
    }
    s1 += (char)('0');
    for (int i = 0; i < y; i++) {
      s1 += (char)('1');
    }
    cout << s1 << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
