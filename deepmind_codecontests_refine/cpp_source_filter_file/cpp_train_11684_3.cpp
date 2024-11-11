#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int i, j, sum = 0, n;
    cin >> n;
    int ara[n];
    for (i = 0; i < n; i++) {
      cin >> ara[i];
    }
    if (n == 1 && ara[0] % 2 != 0) {
      cout << -1 << endl;
    } else {
      for (i = 0; i <= 1; i++) {
        sum = sum + ara[i];
        if (ara[i] % 2 == 0) {
          cout << 1 << endl;
          cout << i + 1 << endl;
          break;
        } else if (sum % 2 == 0) {
          cout << 2 << endl;
          cout << 1 << " " << 2;
        }
      }
    }
  }
  return 0;
}
