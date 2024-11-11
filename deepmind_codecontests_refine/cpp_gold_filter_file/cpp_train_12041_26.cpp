#include <bits/stdc++.h>
using namespace std;
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  if (n <= 5) {
    cout << "-1\n";
  } else {
    for (int i = 2; i < n / 2 + 1; i++) {
      cout << 1 << " " << i + 1 << "\n";
    }
    for (int i = n / 2 + 1; i < n; i++) {
      cout << 2 << " " << i + 1 << "\n";
    }
    cout << 1 << " " << 2 << "\n";
  }
  for (int i = 0; i < n - 1; i++) {
    cout << i + 1 << " " << i + 2;
    if (i != n - 2) cout << "\n";
  }
}
