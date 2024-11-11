#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long mx = a[0], mn = a[0];
  long long c = 0, d = 0;
  for (long long i = 1; i < n; i++) {
    if (a[i] < a[i - 1]) {
      if (!d) c++;
      d = 1;
    }
    if (a[i] > a[i - 1]) d = 0;
  }
  if (!c) return cout << "yes" << endl << "1 1", 0;
  if (c > 1) return cout << "No" << endl, 0;
  d = 0;
  long long x = 0, y = n - 1;
  for (long long i = 1; i < n; i++) {
    if (a[i] < a[i - 1] && d == 0) x = i - 1, d = 1;
    if (a[i] > a[i - 1] && d) {
      y = i - 1;
      break;
    }
  }
  if ((y == n - 1 ? 1 : (a[x] <= a[y + 1])) && (x ? (a[y] >= a[x - 1]) : 1))
    cout << "yes" << endl << x + 1 << " " << y + 1 << endl;
  else
    cout << "no";
  return 0;
}
