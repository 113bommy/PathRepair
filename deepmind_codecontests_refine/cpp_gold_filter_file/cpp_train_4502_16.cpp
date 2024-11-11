#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  long n;
  cin >> t;
  int a[t];
  for (int i = 0; i < t; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < t; i++) {
    if (a[i] <= 2) {
      cout << 0 << endl;
    } else {
      n = (a[i] / 2.0);
      if (a[i] % 2 == 0) {
        cout << n - 1 << endl;
      } else {
        cout << n << endl;
      }
    }
  }
}
