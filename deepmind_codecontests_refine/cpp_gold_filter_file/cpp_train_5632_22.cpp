#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  cin >> m >> n;
  int a[n], b[100];
  for (int i = 0; i < 100; i++) {
    b[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i] - 1]++;
  }
  if (m > n) {
    cout << 0;
    return 0;
  }
  int count, x;
  for (x = 1;; x++) {
    count = 0;
    for (int i = 0; i < 100; i++) {
      count += b[i] / x;
    }
    if (count < m) {
      break;
    }
  }
  cout << x - 1 << endl;
  return 0;
}
