#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, c = 0;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    c += a[i];
  }
  if (c % 360 == 0) {
    cout << "YES";
    return 0;
  }
  for (int j = 0; j < (1 << n); j++) {
    c = 0;
    for (i = 0; i < n; i++) {
      if ((1 << i) & j)
        c += a[i];
      else
        c -= a[i];
    }
    if (c % 360 == 0) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
