#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[3][2];
  int i;
  cin >> n;
  for (i = 0; i < 3; i++) {
    cin >> a[i][0] >> a[i][1];
  }
  n -= a[0][0] + a[1][0] + a[2][0];
  for (i = 0; n; i++) {
    if (a[i][1] - a[i][0] >= n) {
      a[i][0] += n;
      n = 0;
    } else {
      n -= a[i][1] - a[i][0];
      a[i][0] = a[i][1];
    }
  }
  cout << a[0][0] << " " << a[1][0] << " " << a[2][0];
  return 0;
}
