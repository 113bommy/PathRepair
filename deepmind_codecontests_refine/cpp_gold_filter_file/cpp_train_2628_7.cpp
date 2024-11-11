#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e5 + 5;
const long long INF = 1e18;
const long long mod = 1e9 + 7;
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    if (n == 1 || m == 1) {
      cout << "YES" << endl;
    } else {
      if (n == 2 && m == 2) {
        cout << "YES" << endl;
      } else
        cout << "NO" << endl;
    }
  }
}
