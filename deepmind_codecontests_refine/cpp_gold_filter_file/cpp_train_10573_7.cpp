#include <bits/stdc++.h>
using namespace std;
int main() {
  int_fast64_t k2, k3, k5, k6, t = 0;
  cin >> k2 >> k3 >> k5 >> k6;
  if (k2 <= k5 && k2 <= k6) {
    cout << (k2 * 256);
  } else if (k2 >= k5 && k5 <= k6) {
    t = k5 * 256;
    k2 = k2 - k5;
    if (k2 < k3) {
      t = t + (k2 * 32);
    } else {
      t = t + (k3 * 32);
    }
    cout << t;
  } else {
    t = k6 * 256;
    k2 = k2 - k6;
    if (k2 < k3)
      t = t + (k2 * 32);
    else
      t = t + (k3 * 32);
    cout << t;
  }
}
