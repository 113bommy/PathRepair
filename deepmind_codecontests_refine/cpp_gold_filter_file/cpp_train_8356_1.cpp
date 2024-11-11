#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int i = 0, j = 0, k = 0;
    for (i = 0; i <= n / 7; i++) {
      int cnt = 5;
      for (j = 0; j <= n / 5; j++) {
        for (k = 0; k <= n / 3; k++) {
          if (i * 7 + j * 5 + k * 3 == n) {
            cnt = 0;
            break;
          }
        }
        if (!cnt) break;
      }
      if (!cnt) break;
    }
    if (i > n / 7)
      cout << -1 << endl;
    else
      cout << k << " " << j << " " << i << endl;
  }
  return 0;
}
