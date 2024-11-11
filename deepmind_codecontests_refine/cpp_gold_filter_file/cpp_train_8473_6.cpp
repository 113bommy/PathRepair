#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k = -1, c = 0, v = 0, r = 0, v1 = 0, v2 = 0, r1 = 0, r2 = 0;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if ((a[i] == 5) || (a[i] == 7)) {
      k = 0;
    } else if (a[i] == 1) {
      c++;
    } else if ((a[i] == 2) || (a[i] == 3)) {
      v++;
      if (a[i] == 2) {
        v1++;
      } else {
        v2++;
      }
    } else if ((a[i] == 4) || (a[i] == 6)) {
      r++;
      if (a[i] == 4) {
        r1++;
      } else {
        r2++;
      }
    }
  }
  if ((k == 0) || (c != (n / 3)) || (v != (n / 3)) || (r != (n / 3)) ||
      (r2 < v2)) {
    cout << -1 << endl;
  } else {
    k = n / 3;
    for (int i = 0; i < k; i++) {
      cout << "1 ";
      if (r1 != 0) {
        cout << "2 4" << endl;
        v1--;
        r1--;
      } else if (v1 != 0) {
        cout << "2 6" << endl;
        v1--;
      } else {
        cout << "3 6" << endl;
      }
    }
  }
}
