#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int value = 1;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] < a[i - 1] && i > 0) {
        value = 0;
      }
    }
    if (value) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
