#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, k, a, b, c, i, j;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    if (n < k) {
      cout << "NO" << endl;
      continue;
    }
    if (n % 2 == 0) {
      if (k % 2 != 0) {
        if (n < 2 * k)
          cout << "NO" << endl;
        else {
          cout << "YES" << endl;
          for (i = 0; i < k - 1; i++) cout << 2 << " ";
          a = n - (k - 1) * 2;
          cout << a << endl;
        }
      } else {
        cout << "YES" << endl;
        for (i = 0; i < k - 1; i++) cout << 1 << " ";
        a = n - (k - 1);
        cout << a << endl;
      }
    }
    if (n % 2 != 0) {
      if (k % 2 == 0) {
        cout << "NO" << endl;
        continue;
      } else {
        cout << "YES" << endl;
        for (i = 0; i < k - 1; i++) cout << 1 << " ";
        a = n - (k - 1);
        cout << a << endl;
      }
    }
  }
}
