#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << 1;
  } else if (k == 1) {
    cout << 1;
  } else if ((k == 2) && (n >= 4)) {
    cout << 2;
  } else if (n >= 2 * k) {
    cout << k;
  } else {
    cout << n - k;
  }
  return 0;
}
