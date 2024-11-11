#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int k = 0; k < t; k++) {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = 1;
    }
    for (int i = 0; i < n; i++) {
      int p = i;
      while (a[i] != p + 1) {
        int q = a[i];
        i = q - 1;
        b[i] = b[i] + 1;
      }
      i = p;
    }
    for (int i = 0; i < n - 1; i++) {
      cout << b[i] << " ";
    }
    cout << b[n - 1] << endl;
  }
}
