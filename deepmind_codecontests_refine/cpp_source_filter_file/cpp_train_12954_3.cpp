#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (n / 2 > k || n == 1 && k > 0) {
    cout << -1;
  } else {
    if (n == 1) {
      cout << 1;
    } else {
      cout << (k - n / 2 + 1) << " " << 2 * (k - n / 2 + 1) << " ";
      for (int i = 0; i < n - 2; i++) {
        cout << 100000001 + i << " ";
      }
    }
  }
}
