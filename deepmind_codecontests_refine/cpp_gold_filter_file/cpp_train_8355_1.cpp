#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, x, y;
    cin >> n >> x >> y;
    int diff = abs(x - y);
    int gd = diff;
    for (int i = min(diff, n - 1); i > 1; i--) {
      if (diff % i == 0) {
        gd = diff / i;
        break;
      }
    }
    int k = 0;
    for (int i = y; i > 0 && k < n; i -= gd) {
      k++;
      cout << i << " ";
    }
    for (int i = y + gd; k < n; i += gd) {
      k++;
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
