#include <bits/stdc++.h>
using namespace std;
int main() {
  long n;
  cin >> n;
  long a[n];
  for (long i = 0; i < n; ++i) cin >> a[i];
  long c = a[n - 1];
  long d = a[n - 1];
  for (long i = n - 2; i >= 0; --i) {
    if (a[i] < d) {
      c += a[i];
      d = a[i];
    } else {
      if (d > 0) {
        c += d - 1;
        d -= 1;
      }
    }
  }
  cout << c << '\n';
}
