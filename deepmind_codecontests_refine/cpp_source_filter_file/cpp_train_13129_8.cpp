#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, x, y, d;
    cin >> n >> x >> y >> d;
    int result = y % d;
    if (x % d == result) {
      cout << (y - x) / d << '\n';
    } else if ((1 % d) == result or (n % d) == result) {
      int temp_1 = INT_MAX, temp_2 = INT_MAX;
      if ((1 % d) == result) {
        if (x % d <= 1) {
          temp_1 = x / d + (y - 1) / d;
        } else {
          temp_1 = 1 + x / d + (y - 1) / d;
        }
      }
      if ((n % d) == result) {
        if ((n - x) % d <= 1) {
          temp_2 = (n - x) / d + (n - y) / d;
        } else {
          temp_2 = 1 + (n - x) / d + (n - y) / d;
        }
      }
      cout << min(temp_1, temp_2) << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
  return 0;
}
