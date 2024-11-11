#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (n % 2 == 1) {
      if (k % 2 == 0 || n < k) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
        int d = n - k + 1;
        for (int i = 0; i < k - 1; i++) {
          cout << 1 << " ";
        }
        cout << d << endl;
      }
    } else {
      if (n < 2 * (k - 1)) {
        if (n < k) {
          cout << "NO\n";
        } else {
          int d = n - k + 1;
          if (d % 2 == 0)
            cout << "NO\n";
          else {
            cout << "YES\n";
            for (int i = 0; i < k - 1; i++) {
              cout << 1 << " ";
            }
            cout << d << endl;
          }
        }
      } else {
        int temp = n / 2;
        int d = temp - k + 1;
        cout << "YES\n";
        for (int i = 0; i < k - 1; i++) {
          cout << 2 << " ";
        }
        cout << (2 * d) << endl;
      }
    }
  }
}
