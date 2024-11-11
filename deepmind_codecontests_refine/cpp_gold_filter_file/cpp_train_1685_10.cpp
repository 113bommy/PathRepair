#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, i, minimum = 0, c = 0;
    cin >> n;
    long long a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    minimum = a[n - 1];
    for (i = n - 2; i >= 0; i--) {
      if (a[i] < minimum) {
        minimum = a[i];
      } else if (a[i] > minimum) {
        c++;
      }
    }
    cout << c << endl;
  }
}
