#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  if (k > 3 || k == 1) {
    cout << "-1" << endl;
  } else {
    if ((k == 3 && n < 4) || (k == 2 && n <= 4)) {
      cout << "-1" << endl;
    } else {
      if (k == 3 && n > 4) {
        cout << ((n - 5) * (n - 4)) / 2 + 5 << endl;
        cout << "1 2" << endl;
        cout << "2 3" << endl;
        cout << "3 4" << endl;
        cout << "1 5" << endl;
        cout << "5 3" << endl;
        int i, j;
        for (i = 5; i <= n; i++) {
          for (j = i + 1; j <= n; j++) {
            cout << i << " " << j << endl;
          }
        }
      } else if (k == 3 && n == 4) {
        cout << k << endl;
        cout << "1 2" << endl;
        cout << "2 3" << endl;
        cout << "3 4" << endl;
      } else if (k == 2) {
        int i;
        cout << n - 1 << endl;
        for (i = 1; i < n; i++) {
          cout << i << " " << i + 1 << endl;
        }
      }
    }
  }
  return 0;
}
