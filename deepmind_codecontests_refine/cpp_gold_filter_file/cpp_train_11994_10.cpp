#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == s[i - 1]) {
      cout << "-1\n";
      return;
    }
    if (s[i] == '?') {
      for (char j = 'a'; j <= 'c'; j++) {
        if (s[i - 1] != j && s[i + 1] != j) {
          s[i] = j;
          break;
        }
      }
    }
  }
  cout << s << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
