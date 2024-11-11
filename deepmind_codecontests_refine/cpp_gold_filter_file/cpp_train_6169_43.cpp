#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  if (n % 4 == 0)
    cout << "YES\n";
  else
    cout << "NO\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  getline(cin, s);
  int _t = stoi(s);
  while (_t--) solve();
}
