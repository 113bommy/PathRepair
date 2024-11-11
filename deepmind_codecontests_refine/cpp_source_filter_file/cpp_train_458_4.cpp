#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x;
  cin >> n >> m >> x;
  n -= 2 * (x - 1);
  m -= 2 * (x - 1);
  if (n > 0 && m > 0) {
    int k =
        ((n + 1) / 2) * ((m + 1) / 2) + (n - (n + 1) / 2) * (m - (m + 1) / 2);
    n -= 2;
    m -= 2;
    if (n > 0 && m > 0) {
      k = k - ((n + 1) / 2) * ((m + 1) / 2) +
          (n - (n + 1) / 2) * (m - (m + 1) / 2);
    }
    cout << k;
  } else {
    cout << 0;
  }
  return 0;
}
