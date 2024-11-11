#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, tests, n, d, operations, maxi;
  cin >> tests;
  while (tests--) {
    cin >> n >> operations;
    long long syn[n];
    for (i = 0; i < n; i++) {
      cin >> syn[i];
    }
    maxi = syn[0];
    for (i = 0; i < n; i++) {
      if (syn[i] > maxi) {
        maxi = syn[i];
      }
    }
    if (operations % 2 == 0) {
      for (i = 0; i < n; i++) {
        syn[i] == abs(maxi - syn[i]);
      }
      maxi = syn[0];
      for (i = 0; i < n; i++) {
        if (syn[i] > maxi) {
          maxi = syn[i];
        }
      }
      for (i = 0; i < n; i++) {
        cout << abs(maxi - syn[i]) << " ";
      }
      cout << endl;
    } else {
      for (i = 0; i < n; i++) {
        cout << abs(maxi - syn[i]) << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
