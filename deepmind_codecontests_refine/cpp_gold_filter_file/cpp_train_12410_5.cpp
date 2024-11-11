#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int mx1 = 0, mx2 = 0;
    for (int i = 1; i <= k1; i++) {
      int tt;
      cin >> tt;
      mx1 = max(mx1, tt);
    }
    for (int i = 1; i <= k2; i++) {
      int tt;
      cin >> tt;
      mx2 = max(mx2, tt);
    }
    if (mx1 > mx2)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
