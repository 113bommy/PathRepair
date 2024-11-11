#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int f = 0;
    int k = 100;
    int j = 500;
    for (int i = 0; i < n; i++) {
      if (f == 0) {
        cout << k << " ";
        f = 1;
      } else {
        cout << j << " ";
        f = 0;
      }
    }
    cout << endl;
  }
}
