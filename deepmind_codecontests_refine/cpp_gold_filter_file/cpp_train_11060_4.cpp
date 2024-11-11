#include <bits/stdc++.h>
using namespace std;
void code_init() {}
void solve() {
  int n;
  cin >> n;
  if (n % 4 != 0) {
    cout << "NO" << endl;
    return;
  } else {
    cout << "YES" << endl;
    for (int i = 1, _i = (n / 2 + 1); i < _i; ++i) cout << i * 2 << " ";
    for (int i = 0, _i = (n / 2 - 1); i < _i; ++i) cout << i * 2 + 1 << " ";
    cout << n + n / 2 - 1 << endl;
  }
}
int main() {
  code_init();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
