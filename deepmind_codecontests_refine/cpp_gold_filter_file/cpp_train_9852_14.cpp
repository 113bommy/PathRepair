#include <bits/stdc++.h>
using namespace std;
const int MX = 1e5 + 6;
int n, m, c, ar[1030];
int main() {
  cin >> n >> m >> c;
  for (int i = 1; i <= n; i++) ar[i] = c + 1;
  while (m--) {
    int p;
    cin >> p;
    if (p * 2 > c) {
      for (int j = n; j >= 1; j--) {
        if (p > ar[j] || ar[j] == c + 1) {
          ar[j] = p;
          cout << j << endl;
          break;
        }
      }
    } else {
      for (int j = 1; j <= n; j++) {
        if (p < ar[j]) {
          ar[j] = p;
          cout << j << endl;
          break;
        }
      }
    }
    fflush(stdout);
    bool ok = 1;
    for (int i = 1; i <= n; i++) {
      if (ar[i] == c + 1) ok = 0;
    }
    if (ok) return 0;
  }
  return 0;
}
