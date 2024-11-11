#include <bits/stdc++.h>
using namespace std;
int almostlucky(int n) {
  int k, a[10];
  a[0] = 4;
  a[1] = 7;
  a[2] = 44;
  a[3] = 47;
  a[4] = 74;
  a[5] = 77;
  a[6] = 444;
  a[7] = 447;
  a[8] = 474;
  a[9] = 477;
  for (int i = 0; i < 10; i++) {
    k = n % a[i];
    if (k == 0) {
      return 0;
      break;
    }
  }
  if (k = !0) {
    return 1;
  }
}
int main() {
  int n, k;
  cin >> n;
  if (almostlucky(n) == 0) {
    cout << "YES" << endl;
  } else {
    while (n > 0) {
      k = n - n / 10 * 10;
      if (k != 4 && k != 7) {
        cout << "NO" << endl;
        break;
      }
      n = n / 10;
    }
    if (n == 0) {
      cout << "YES" << endl;
    }
  }
  return 0;
}
