#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int x, ans = 0;
    cin >> x;
    for (int j = 7; j > 1; --j) {
      ans += x / j;
      x %= j;
    }
    if (x) ++ans;
    cout << ans << '\n';
  }
  return 0;
}
