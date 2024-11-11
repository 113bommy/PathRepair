#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (n % 2 != 0) {
      if ((n - (k - 1)) % 2 == 0 || k > n) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
        for (int i = 0; i < (k - 1); i++) {
          cout << 1 << " ";
        }
        cout << n - (k - 1) << endl;
      }
    } else {
      if ((k > (n / 2)) && k <= n) {
        if ((n - (k - 1)) % 2 == 0)
          cout << "NO" << endl;
        else {
          cout << "YES" << endl;
          for (int i = 0; i < k - 1; i++) cout << 1 << " ";
          cout << n - (k - 1) << endl;
        }
      } else if (k < (n / 2)) {
        cout << "YES" << endl;
        for (int i = 0; i < k - 1; i++) cout << 2 << " ";
        int temp = 2 * (k - 1);
        cout << n - temp << endl;
      } else
        cout << "NO" << endl;
    }
  }
  return 0;
}
