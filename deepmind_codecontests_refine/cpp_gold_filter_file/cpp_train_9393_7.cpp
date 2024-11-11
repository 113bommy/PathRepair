#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  ;
  int T = 1;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n == 1)
      cout << -1 << endl;
    else {
      cout << 2;
      for (int i = 0; i < n - 1; ++i) cout << 3;
    }
    cout << endl;
  }
}
