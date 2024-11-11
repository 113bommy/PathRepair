#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, i, j, k, x;
  cin >> n >> k;
  if ((n / 2) > k) {
    cout << -1;
  } else {
    if (n == 1) {
      if (k != 0)
        cout << -1;
      else {
        cout << 1;
      }
    } else {
      t = n / 2;
      t -= 1;
      k -= t;
      cout << k << " " << k * 2 << " ";
      k = 2 * k + 1;
      for (i = 0; i < n - 2; i++) {
        cout << k << " ";
        k++;
      }
    }
  }
}
