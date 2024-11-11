#include <bits/stdc++.h>
using namespace std;
int j, k, l, m, n, i;
int main() {
  for (i = 1; i <= 25; i++) {
    cin >> n;
    if (n == 1) k = i;
  }
  if (k == 13) {
    cout << 0;
    return 0;
  }
  if (k > 10 && k < 16) {
    cout << abs(k - 13);
    return 0;
  }
  if (k == 3 || k == 8 || k == 18 || k == 23) {
    if (k == 3 || k == 23) {
      cout << 2;
      return 0;
    } else {
      cout << 1;
      return 0;
    }
  }
  if (k < 6) {
    k = k + 10;
    cout << abs(k - 13) + 2;
    return 0;
  }
  if (k >= 6 && k < 13) {
    k = k + 5;
    cout << abs(k - 13) + 1;
    return 0;
  }
  if (k > 13 && k <= 19) {
    k = k - 5;
    cout << abs(k - 13) + 1;
    return 0;
  }
  if (k > 18 && k <= 25) {
    k = k - 10;
    cout << abs(k - 13) + 2;
    return 0;
  }
}
