#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[6];
  for (int i = 0; i < 6; i++) {
    cin >> a[i];
  }
  int ans = (a[0] + a[1] + a[2]) * (a[0] + a[1] + a[2]) - a[0] * a[0] -
            a[2] * a[2] - a[5] * a[5];
  cout << ans << endl;
  return 0;
}
