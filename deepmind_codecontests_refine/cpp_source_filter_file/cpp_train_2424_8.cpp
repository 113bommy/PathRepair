#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int a[n];
    for (int j = 0; j < n; j++) {
      cin >> a[j];
    }
    for (int k = n - 1; k >= 0; k--) {
      if (k % 2 == 0) {
        cout << -a[k] << " ";
      }
      if (k % 2 != 0) {
        cout << a[k];
      }
    }
    cout << endl;
  }
}
