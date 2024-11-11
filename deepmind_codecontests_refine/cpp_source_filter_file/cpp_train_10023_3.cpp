#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, m, a, b, c, d;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    int count = 0;
    for (int i = 0; i < 2 * n; i++) {
      cin >> a >> b >> c >> d;
      if (b == c) count++;
    }
    if (m % 2 != 0)
      cout << "NO\n";
    else {
      if (count > 0)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
