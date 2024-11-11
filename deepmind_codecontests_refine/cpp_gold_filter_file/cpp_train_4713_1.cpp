#include <bits/stdc++.h>
using namespace std;
int T, x, n;
string s;
void solve() {
  cin >> s >> x;
  n = s.length();
  bool a[n], ans = 0;
  for (int i = 0; i < n; i++) a[i] = 1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      if (i - x >= 0) a[i - x] = 0;
      if (i + x < n) a[i + x] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      if (!((i - x >= 0 && a[i - x]) || (i + x < n && a[i + x]))) {
        ans = 1;
        break;
      }
    }
  }
  if (ans)
    cout << -1;
  else
    for (int i = 0; i < n; i++) cout << a[i];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    solve();
    cout << '\n';
  }
}
