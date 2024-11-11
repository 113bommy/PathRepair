#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long d = a[n - 1] - a[0];
  cout << a[n - 1] - a[0] << " ";
  long long p = 1;
  long long q = 1;
  if (d != 0) {
    for (int i = 1; i < n; i++) {
      if (a[i] == a[0]) {
        p++;
      } else {
        break;
      }
    }
    for (int i = n - 2; i > 1; i--) {
      if (a[i] == a[n - 1]) {
        q++;
      } else {
        break;
      }
    }
  }
  if (d != 0) {
    cout << p * q;
  }
  if (d == 0) {
    cout << (n * (n - 1)) / 2;
  }
  return 0;
}
