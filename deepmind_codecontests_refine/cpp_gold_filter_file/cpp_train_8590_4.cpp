#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, d, h;
  cin >> n >> d >> h;
  if (d > 2 * h || (d == 1 && h == 1 && n >= 3))
    cout << -1 << endl;
  else {
    int node = 1;
    for (int i = 1; i <= h; i++) {
      cout << node << " " << node + 1 << endl;
      node++;
    }
    if (d >= h && node < n) {
      if (d > h) {
        node++;
        cout << 1 << " " << node << endl;
      }
      for (int i = 1; i <= d - h - 1; i++) {
        cout << node << " " << node + 1 << endl;
        node++;
      }
      for (int i = node + 1; i <= n; i++) cout << h << " " << i << endl;
    }
  }
}
