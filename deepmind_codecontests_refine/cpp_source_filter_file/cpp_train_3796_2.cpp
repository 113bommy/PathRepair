#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int x, y, z;
  ios::sync_with_stdio(false);
  while (cin >> n >> k) {
    x = ((n - 1) * 6 + 5) * k;
    y = 1;
    cout << x << endl;
    for (int i = 0; i < n; i++) {
      cout << y * k << " " << (++y) * k << " " << (++y) * k << " "
           << (y + 2) * k << endl;
      y += 3;
    }
  }
}
