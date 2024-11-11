#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  cin >> n;
  long long i, j = 0;
  long long x;
  long long a[n];
  long long max = 0;
  for (i = 0; i < n; i++) cin >> a[i];
  if (n == 1) {
    cout << 1;
    return 0;
  } else if (n == 2) {
    cout << 2;
    return 0;
  } else {
    for (i = 2; i < n; i++) {
      if (a[i] == (a[i - 1] + a[i - 2])) {
        j++;
      } else {
        j = 0;
      }
      if (j > max) max = j;
    }
  }
  cout << max + 2;
}
