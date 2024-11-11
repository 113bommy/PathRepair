#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, r, x, y, k, i;
  cin >> l >> r >> x >> y >> k;
  for (i = l; i < r; i++) {
    if (i % k == 0 && i / k >= x && i / k <= y) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
