#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    char a[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }
    char k = a[0][1];
    char u = a[n - 1][n - 2];
    char l = a[1][0];
    char v = a[n - 2][n - 1];
    if (k == l) {
      if (u == v) {
        if (k == u) {
          cout << 2 << endl;
          cout << 1 << " " << 2 << endl;
          cout << 2 << " " << 1 << endl;
        } else
          cout << 0 << endl;
      } else {
        if (k == u) {
          cout << 1 << endl;
          cout << n << " " << n - 1 << endl;
        } else {
          cout << 1 << endl;
          cout << n - 1 << " " << n << endl;
        }
      }
    } else {
      if (u == v) {
        if (k == u) {
          cout << 1 << endl;
          cout << 1 << " " << 2 << endl;
        } else {
          cout << 1 << endl;
          cout << 2 << " " << 1 << endl;
        }
      } else {
        if (k == u) {
          cout << 2 << endl;
          cout << 1 << " " << 2 << endl;
          cout << n - 1 << " " << n << endl;
        } else {
          cout << 2 << endl;
          cout << 2 << " " << 1 << endl;
          cout << n - 1 << " " << n << endl;
        }
      }
    }
  }
  return 0;
}
