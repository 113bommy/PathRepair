#include <bits/stdc++.h>
using namespace std;
int main() {
  double l, r, x, y, k, ans;
  cin >> l >> r >> x >> y >> k;
  while (x < y) {
    ans = x * k;
    if (ans <= l && ans <= r) {
      cout << "YES";
      return 0;
    }
    x++;
  }
  cout << "NO";
  return 0;
}
