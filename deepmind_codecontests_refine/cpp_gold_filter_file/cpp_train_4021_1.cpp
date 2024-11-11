#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> no(1000001, false);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int countb = 0;
    cout << "YES\n";
    for (int i = 1; i <= 1000000; i++) {
      if (!no[i]) {
        cout << i << " ";
        countb++;
        if (countb == n) {
          break;
        }
        for (int j = 0; j < n; j++) {
          for (int k = 0; k < n; k++) {
            if (i - a[j] + a[k] >= 0 && i - a[j] + a[k] <= 1000000) {
              no[i - a[j] + a[k]] = true;
            }
          }
        }
      }
    }
    cout << endl;
  }
  return 0;
}
