#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k1, k2, a1, a2, k, l = 0, r = 0;
  cin >> a1 >> a2 >> k1 >> k2 >> n;
  if (k1 > k2) {
    swap(a1, a2);
    swap(k1, k2);
  }
  k = a1 * (k1 - 1) + a2 * (k2 - 1);
  if (k <= 0) {
    l = 0;
  } else {
    l = n - k;
  }
  if (n <= a1 * k1) {
    r = n / k1;
  } else {
    r = a1 + ((n - a1 * k1) / k2);
  }
  cout << l << " " << r;
  return 0;
}
