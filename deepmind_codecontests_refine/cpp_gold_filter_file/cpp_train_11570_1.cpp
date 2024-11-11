#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] <= 7) {
      a[i] = 1;
    } else {
      if ((a[i] % 7) != 0)
        a[i] = a[i] / 7 + 1;
      else
        a[i] = a[i] / 7;
    }
  }
  for (i = 0; i < n; i++) {
    cout << a[i] << endl;
  }
  return 0;
}
