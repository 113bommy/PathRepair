#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) cout << s[i];
  }
  cout << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
