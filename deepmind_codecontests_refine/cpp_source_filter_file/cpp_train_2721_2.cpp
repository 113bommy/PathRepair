#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m = 0, a[100000], i, b, s = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n % 2 == 0) {
    b = n / 2;
  } else {
    b = (n / 2) + 1;
  }
  for (i = 0; i < n - 1; i++) {
    if (a[i] > 0) {
      m++;
    } else if (a[i] < 0) {
      s++;
    }
  }
  if (m >= b) {
    cout << 1;
  } else if (s >= b) {
    cout << -1;
  } else {
    cout << 0;
  }
  return 0;
}
