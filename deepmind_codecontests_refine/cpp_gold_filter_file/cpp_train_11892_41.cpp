#include <bits/stdc++.h>
using namespace std;
int main() {
  const int delta = 1000000007;
  int m, n, k, mx;
  cin >> m >> n >> k;
  mx = max(m, n);
  long long a[mx][mx];
  for (int i = 0; i < mx; i++) {
    for (int j = 0; j < mx; j++) {
      if (j == 0) {
        a[i][j] = 1;
      } else if (j > i) {
        a[i][j] = 0;
      } else {
        a[i][j] = (a[i - 1][j - 1] + a[i - 1][j]) % delta;
      }
    }
  }
  if (m > 2 * k && n > 2 * k) {
    cout << (a[m - 1][2 * k] * a[n - 1][2 * k]) % delta;
  } else {
    cout << 0;
  }
}
