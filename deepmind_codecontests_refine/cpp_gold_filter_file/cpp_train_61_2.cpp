#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n;
  cin >> n;
  vector<string> a(n);
  bool found = false;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    found |= a[i] == s;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      found |= a[i][0] == s[1] && a[j][1] == s[0];
    }
  }
  cout << (found ? "YES" : "NO") << '\n';
  return 0;
}
