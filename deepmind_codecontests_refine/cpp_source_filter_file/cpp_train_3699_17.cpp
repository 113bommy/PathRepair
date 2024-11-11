#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, r = 0, g = 0, b = 0;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R')
      r++;
    else if (s[i] == 'G')
      g++;
    else
      b++;
  }
  if (r == n) {
    cout << "R";
    return;
  }
  if (r == n) {
    cout << "B";
    return;
  }
  if (r == n) {
    cout << "G";
    return;
  }
  if (b != n - 1) cout << "B";
  if (g != n - 1) cout << "G";
  if (r != n - 1) cout << "R";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
