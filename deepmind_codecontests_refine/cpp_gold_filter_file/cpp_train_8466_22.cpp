#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
unsigned long long n, t, low, ri, ct, x, p, p1, a[2 * N], b[2 * N];
int main() {
  cin >> n >> t;
  t -= n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  low = 1;
  ri = 1e18;
  while (low <= ri) {
    ct = 0;
    x = (low + ri) / 2;
    for (int i = 1; i <= n; i++) {
      ct += a[i] * x / b[i];
    }
    if (ct >= t) {
      ri = x - 1;
    } else {
      low = x + 1;
    }
  }
  p = low;
  low = 1;
  ri = 1e18;
  while (low <= ri) {
    ct = 0;
    x = (low + ri) / 2;
    for (int i = 1; i <= n; i++) {
      ct += a[i] * x / b[i];
    }
    if (ct > t) {
      ri = x - 1;
    } else {
      low = x + 1;
    }
  }
  p1 = low;
  if (p == 1 && p1 == 1e18) {
    cout << -1;
  } else {
    cout << p1 - p;
  }
}
