#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  if (((n <= k / 2) && (k % 2 == 0)) || ((n < k / 2) && (k % 2 != 0)) ||
      (k < 3))
    cout << 0;
  else {
    if (n < k) {
      if (k % 2 == 0) cout << (k / 2 - 1) - (k - n - 1);
      if (k % 2 != 0) cout << (k / 2) - (k - n - 1);
    }
    if (n > k) {
      if (k % 2 == 0) cout << k / 2 - 1;
      if (k % 2 != 0) cout << k / 2;
    }
  }
  return 0;
}
