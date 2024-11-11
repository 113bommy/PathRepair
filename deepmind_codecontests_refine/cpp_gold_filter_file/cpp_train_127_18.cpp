#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, x, n, m, r[1001], s;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (x = 0; x < n; x++) cin >> r[x];
    for (x = 0; x < m; x++) {
      cin >> s;
      if (count(r, r + n, s)) break;
    }
    if (x < m) {
      for (x++; x < m; m--) cin >> n;
      cout << "YES\n1 " << s << endl;
    } else
      cout << "NO\n";
  }
}
