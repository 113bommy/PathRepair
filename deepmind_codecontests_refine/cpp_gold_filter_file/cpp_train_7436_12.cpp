#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, l, m, n, a[100100] = {0};
  string s;
  cin >> n >> m;
  cin >> s;
  if (n >= (2 * m)) {
    for (i = m; i > 1; i--) {
      cout << "LEFT\n";
    }
    for (i = 1; i <= n; i++) {
      cout << "PRINT " << s[i - 1] << "\n";
      if (i != n) cout << "RIGHT\n";
    }
  } else {
    for (i = m; i < n; i++) cout << "RIGHT\n";
    for (i = n; i > 0; i--) {
      cout << "PRINT " << s[i - 1] << "\n";
      if (i != 1) cout << "LEFT\n";
    }
  }
  return 0;
}
