#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  if (k % 2 == 0)
    cout << "NO" << endl;
  else {
    if (k == 1) {
      cout << "YES" << endl;
      cout << "2 1" << endl;
      cout << "1 2" << endl;
    } else {
      cout << "YES" << endl;
      int n = 2 * k + 4;
      int m = (k + 2) * k;
      cout << n << " " << m << endl;
      cout << 1 << " " << (k + 3) << endl;
      for (int i = 2; i <= k; i++) cout << 1 << " " << i << endl;
      for (int i = 2; i < k; i++)
        for (int j = i + 1; j <= k; j++) {
          if (i % 2 == 0 && i + 1 == j) continue;
          cout << i << " " << j << endl;
        }
      for (int i = 2; i <= k; i++) {
        cout << i << " " << (k + 1) << endl;
        cout << i << " " << (k + 2) << endl;
      }
      cout << (k + 1) << " " << (k + 2) << endl;
      for (int i = k + 4; i <= 2 * k + 2; i++)
        cout << (k + 3) << " " << i << endl;
      for (int i = k + 4; i < 2 * k + 2; i++)
        for (int j = i + 1; j <= 2 * k + 2; j++) {
          if (i % 2 == 0 && i + 1 == j) continue;
          cout << i << " " << j << endl;
        }
      for (int i = k + 4; i <= 2 * k + 2; i++) {
        cout << i << " " << (2 * k + 3) << endl;
        cout << i << " " << (2 * k + 4) << endl;
      }
      cout << (2 * k + 3) << " " << (2 * k + 4) << endl;
    }
  }
  return 0;
}
