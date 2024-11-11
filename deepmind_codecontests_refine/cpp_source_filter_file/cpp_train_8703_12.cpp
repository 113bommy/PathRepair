#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long int l, r, x, y, k;
  cin >> l >> r >> x >> y >> k;
  while (x < y) {
    if (x * k >= l && x * k <= r || y * k >= l && y * k <= r) {
      cout << "YES" << '\n';
      return 0;
    }
    x++, y--;
  }
  cout << "NO" << '\n';
  return 0;
}
