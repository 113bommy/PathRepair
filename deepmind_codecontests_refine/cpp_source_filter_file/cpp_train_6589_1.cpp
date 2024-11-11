#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int x[2] = {0}, f = 0;
  for (int i = 0; i < n; i++) {
    x[i / (n / 2)] += s[i] - '0';
    f += (s[i] != '4' && s[i] != '7');
  }
  cout << (x[0] == x[1] && f ? "YES" : "NO") << '\n';
}
void t(int t) {
  if (!t) {
    cin >> t;
  }
  while (t--) {
    solve();
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  t(1);
  return 0;
}
