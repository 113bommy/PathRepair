#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    bool ch1 = false;
    if (m % 2 == 0) ch1 = true;
    bool ch2 = false;
    for (int i = 0; i < n; i++) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      if (b == c) {
        ch2 = true;
      }
    }
    if (ch1 && ch2) {
      cout << "YES\n";
    } else {
      cout << "N0\n";
    }
  }
  return 0;
}
