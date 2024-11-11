#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int t, n;
string s;
void solve() {
  cin >> n >> s;
  for (int i = 0; i < (int)s.length(); ++i) {
    if (s[i] == '8' && (n - i + 1) >= 11) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
