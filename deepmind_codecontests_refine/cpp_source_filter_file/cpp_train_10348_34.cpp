#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  if (n == 1 && m != 1) {
    cout << m << "\n";
    for (int i = 1; i <= m; i++) {
      cout << 1 << " " << i << "\n";
    }
  } else if (m == 1 && n != 1) {
    cout << n << "\n";
    for (int i = 1; i <= n; i++) {
      cout << i << " " << 1 << "\n";
    }
  } else if (m == 1 && n == 1) {
    cout << 1 << "\n" << 1 << " " << 1;
  } else {
    cout << n + m - 1 << "\n";
    for (int i = 1; i <= m; i++) {
      cout << 1 << " " << i << "\n";
    }
    for (int i = 2; i <= n; i++) {
      cout << i << " " << i << "\n";
    }
  }
  return 0;
}
