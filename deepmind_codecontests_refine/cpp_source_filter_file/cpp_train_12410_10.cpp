#include <bits/stdc++.h>
using namespace std;
const double epsilon = 1e-7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int maxp1 = INT_MIN;
    int maxp2 = INT_MIN;
    int x;
    for (int i = 0; i < k1; i++) {
      cin >> x;
      maxp1 = max(maxp1, x);
    }
    for (int i = 0; i < k1; i++) {
      cin >> x;
      maxp2 = max(maxp2, x);
    }
    cout << ((maxp1 > maxp2) ? "YES\n" : "NO\n");
  }
  return 0;
}
