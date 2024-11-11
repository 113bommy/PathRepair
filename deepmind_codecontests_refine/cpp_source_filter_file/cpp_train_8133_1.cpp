#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int k;
  cin >> n >> k;
  if (k == n) {
    cout << 3 * k;
  } else {
    if (k == 1) {
      cout << 3 * n;
    } else {
      if (k > n / 2)
        cout << 3 * k + n - 1;
      else {
        cout << 3 * n + k - 1;
      }
    }
  }
  return 0;
}
