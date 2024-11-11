#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, h, m, a[1000];
int main() {
  cin >> n >> k;
  m = k / 2 + k % 2;
  if (m == n)
    cout << n;
  else {
    m = k - (2 * n);
    if (m < n)
      cout << n - m;
    else
      cout << 0;
  }
  return 0;
}
