#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[1001], b[1001], c;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  c = a[1];
  for (int i = 2; i <= n; i++) {
    for (int j = 0;; j++) {
      if ((a[i] + b[i] * j) > c) {
        c = a[i] + b[i] * j;
        break;
      }
    }
  }
  cout << c;
}
