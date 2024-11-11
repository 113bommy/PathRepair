#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
void solve() {
  int n;
  cin >> n;
  if (n <= 26) {
    for (int i = 1; i <= 26; ++i) {
      cout << ('a' + i - 1);
    }
    cout << endl;
    return;
  }
  if (n & 1) {
    for (int i = 1; i <= n / 2; ++i) cout << "a";
    cout << "bc";
    for (int i = n / 2 + 2; i <= n; ++i) cout << "a";
  } else {
    for (int i = 1; i <= n / 2; ++i) cout << "a";
    cout << "b";
    for (int i = n / 2 + 1; i <= n; ++i) cout << "a";
  }
  cout << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
