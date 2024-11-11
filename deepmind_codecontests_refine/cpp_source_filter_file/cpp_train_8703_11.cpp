#include <bits/stdc++.h>
using namespace std;
int main() {
  long long l, r, x, y, k, i, j;
  cin >> l >> r >> x >> y >> k;
  for (j = x; j <= y; j++) {
    i = j * k;
    if (i > l && i < r) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}
