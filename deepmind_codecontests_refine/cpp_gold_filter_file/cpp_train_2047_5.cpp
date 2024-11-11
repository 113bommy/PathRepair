#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  int x = 0, y = 0;
  if (k < n) {
    x = 1 + k;
    y = 1;
  } else {
    k -= n;
    int nr = k / (2 * m - 2), nk = k % (2 * m - 2), m1 = nk / (m - 1),
        m2 = nk % (m - 1);
    if (m1 == 0) {
      y = 2 + m2;
    } else {
      y = m - m2;
    }
    x = n - 2 * nr - m1;
  }
  cout << x << " " << y;
  return 0;
}
