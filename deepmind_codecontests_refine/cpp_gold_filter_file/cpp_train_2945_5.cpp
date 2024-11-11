#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int n;
  while (t--) {
    cin >> n;
    int ps[n][n];
    if (n % 2 == 0) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          ps[i][j] = 0;
          ps[i][i] = 1;
          ps[i][n - 1 - i] = 1;
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          cout << ps[i][j] << " ";
        }
        cout << endl;
      }
    } else {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          ps[i][j] = 0;
          ps[i][i] = 1;
          ps[i][n - 1 - i] = 1;
          ps[(n) / 2][0] = 1;
          ps[0][n / 2] = 1;
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          cout << ps[i][j] << " ";
        }
        cout << endl;
      }
    }
  }
  return 0;
}
