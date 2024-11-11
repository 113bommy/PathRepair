#include <bits/stdc++.h>
using namespace std;
long long a[100100], n, i, d, cnt, ii;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  if (n == 1) {
    printf("-1\n");
    return 0;
  }
  sort(a, a + n);
  if (n == 2) {
    if (a[0] == a[1]) {
      cout << 1 << endl;
      cout << a[0];
    } else {
      d = a[1] - a[0];
      if (d % 2 == 0) {
        cout << 3 << endl;
        cout << a[0] - d << " " << a[0] + d / 2 << " " << a[1] + d;
      } else {
        cout << 2 << endl;
        cout << a[0] - d << " " << a[1] + d;
      }
    }
  }
  if (n > 2) {
    d = 1e9;
    for (i = 1; i < n; i++)
      if (a[i] - a[i - 1] < d) d = a[i] - a[i - 1];
    for (i = 1; i < n; i++)
      if (a[i] - a[i - 1] != d) {
        cnt++;
        ii = i;
      }
    if (cnt == 0 && d == 0) {
      cout << 1 << endl;
      cout << a[0];
    } else if (cnt == 0 && d != 0) {
      cout << 2 << endl;
      cout << a[0] - d << " " << a[n - 1] + d;
    } else if (cnt == 1 && a[ii] - a[ii - 1] == d * 2) {
      cout << 1 << endl;
      cout << a[ii] - d;
    } else {
      cout << 0;
    }
  }
  return 0;
}
