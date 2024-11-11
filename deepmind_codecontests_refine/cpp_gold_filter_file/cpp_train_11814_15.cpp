#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, l = 1, res = 0;
  cin >> m >> n;
  if (m >= 1 && n <= 16) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < n; k++) {
        l++;
        if (l % 2 != 0) {
          res++;
        }
      }
    }
    cout << res;
  }
}
