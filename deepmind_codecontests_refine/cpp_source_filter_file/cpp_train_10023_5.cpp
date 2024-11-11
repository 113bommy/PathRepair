#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    bool ok = 0;
    for (int i = 1; i <= n; ++i) {
      int a[4];
      for (int j = 0; j < 4; ++j) cin >> a[j];
      ok |= a[2] == a[1];
    }
    ok |= m % 2;
    cout << (ok ? "YES" : "NO") << endl;
  }
}
