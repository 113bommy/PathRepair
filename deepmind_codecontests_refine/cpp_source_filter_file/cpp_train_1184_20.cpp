#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long n, k, m, r, l, i, j, s = 0;
  cin >> n >> k;
  if (n == 1) {
    cout << 0;
    return 0;
  }
  if (n <= k) {
    cout << 1;
    return 0;
  }
  if (n - 1 > (k - 1) * k / 2) {
    cout << -1;
    return 0;
  }
  if (n - 1 == (k - 1) * k / 2) {
    cout << k - 1;
    return 0;
  }
  k--;
  n--;
  r = k;
  l = 1;
  while (l <= r) {
    m = (l + r + 1) / 2;
    s = (k + m) * (k - m + 1) / 2;
    if (n > s)
      r = m - 1;
    else if (n < s)
      l = m + 1;
    else {
      cout << k - r;
      return 0;
    }
  }
  cout << k - r + 1;
  return 0;
}
