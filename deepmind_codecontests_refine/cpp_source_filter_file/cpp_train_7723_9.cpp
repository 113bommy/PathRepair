#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = t; i > 0; i--) {
    int n, c = 0;
    cin >> n;
    int b = n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = n; i > 0; i--) {
      for (int i = 0; i < n; i++) {
        if ((a[i] / b) >= 1) {
          c++;
        }
      }
      if (c < b) {
        b = b - 1;
        c = 0;
      }
    }
    cout << b;
  }
}
