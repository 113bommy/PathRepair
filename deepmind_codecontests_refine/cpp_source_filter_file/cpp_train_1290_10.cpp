#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
long long n, i, j, k, q, x, y, w, a[20000000], pop, pat, h;
int main() {
  cin >> x >> y >> k;
  if (x >= k || y >= k) {
    cout << 0 << endl;
    return 0;
  }
  if (x <= 0 && y <= 0 && k > 0) {
    cout << -1 << endl;
    return 0;
  }
  if (x < k && y < k && k <= 0) {
    cout << -1 << endl;
    return 0;
  }
  if (x < y) {
    w = x;
    x = y;
    y = w;
  }
  if (x + y < 0) {
    pop = -y / x;
    pop++;
    pat += pop;
    y = y + pop * x;
  }
  a[1] = 1;
  a[2] = 1;
  if (x + y >= k) {
    cout << 1 + pat << endl;
    return 0;
  }
  for (i = 3;; i++) {
    a[i] = a[i - 1] + a[i - 2];
    h = a[i] * x + a[i - 1] * y;
    if (h >= k || h < 0) {
      cout << i - 1 + pat << endl;
      return 0;
    }
  }
  return 0;
}
