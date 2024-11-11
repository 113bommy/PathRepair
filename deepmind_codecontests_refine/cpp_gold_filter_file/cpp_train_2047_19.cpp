#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, k, r = 0, c = 1, x = 0, y = 0, z = 0;
  cin >> n >> m >> k;
  if (k == n * m - 1) {
    r = 0;
    c = 2;
  } else if (k <= n - 1)
    r += k;
  else {
    x = (k - n + 1) / (m - 1);
    y = (k - n + 1) % (m - 1);
    if (y > 0)
      r = n - x - 1;
    else
      r = n - x;
    if (x % 2 == 0) {
      c = 2 + max(y - 1, z);
    } else {
      c = m - max(z, y - 1);
    }
  }
  cout << r + 1 << " " << c;
}
