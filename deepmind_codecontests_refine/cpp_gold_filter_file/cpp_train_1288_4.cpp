#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (k * 3 <= n) {
    while (n > 0) {
      for (int i = 1; i <= k && (n > 0); i++) {
        if (n == 1) {
          cout << i << " ";
        } else {
          cout << i << " " << i << " ";
        }
        n -= 2;
      }
      for (int i = 1; i <= k && n > 0; i++) {
        cout << i << " ";
        n--;
      }
    }
  } else {
    cout << -1;
  }
  return 0;
}
