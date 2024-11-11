#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long BASE = 101;
bool is_enough(int h, int n, int m) {
  int n1 = h / 2;
  int m1 = h / 3;
  int mn1 = h / 6;
  if (n1 - mn1 >= n && m1 - mn1 >= m) {
    return true;
  }
  int need_n = max(0, n - (n1 - mn1));
  int need_m = max(0, m - (m1 - mn1));
  if (need_n + need_m <= mn1) {
    return true;
  }
  return false;
}
int main() {
  std::cout.precision(15);
  std::ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  if (m == 0) {
    cout << 2 * n;
    return 0;
  }
  if (n == 0) {
    cout << 3 * m;
    return 0;
  }
  int l = 2;
  int r = 6000000;
  while (r - l > 1000) {
    int mid = l + (r - l) / 2;
    if (is_enough(mid, n, m)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  for (int i = l; i <= r; ++i) {
    if ((i % 2 == 0 || i % 3 == 0) && is_enough(i, n, m)) {
      cout << i;
      break;
    }
  }
  return 0;
}
