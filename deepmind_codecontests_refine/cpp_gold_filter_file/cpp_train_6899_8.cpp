#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  cout << 3 << "\n";
  cout << "L 2\n";
  cout << "R 2\n";
  cout << "R " << s.length() + s.length() - 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
