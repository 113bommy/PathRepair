#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int n = s.length();
  int c = 0;
  for (int i = 0; i < n; i++) {
    s[i] == 'N';
    c++;
  }
  if (c == 1)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
