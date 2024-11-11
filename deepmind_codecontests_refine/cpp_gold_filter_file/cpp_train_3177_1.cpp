#include <bits/stdc++.h>
using namespace std;
int main() {
  long long dmd = 0, a[3], i, b[3], supp = 0;
  for (i = 0; i < 3; i++) {
    cin >> a[i];
  }
  for (i = 0; i < 3; i++) {
    cin >> b[i];
  }
  for (i = 0; i < 3; i++) {
    if (a[i] > b[i]) {
      if ((a[i] - b[i]) % 2 == 0) {
        supp += a[i] - b[i];
      } else {
        dmd += 2;
        supp += (a[i] - b[i] + 1);
      }
    } else if (b[i] > a[i]) {
      dmd += (b[i] - a[i]) * 2;
    }
  }
  if (supp >= dmd)
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}
