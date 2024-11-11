#include <bits/stdc++.h>
using namespace std;
int main() {
  string name[51];
  int plus[52], minus[52], a[52], b[52], c[52], d[52], e[52], val[52],
      n = 0, i = 0, ans = 0, max = -9999999999999999999;
  cin >> n;
  for (i = 0; i < n; i++)
    cin >> name[i] >> plus[i] >> minus[i] >> a[i] >> b[i] >> c[i] >> d[i] >>
        e[i];
  for (i = 0; i < n; i++) {
    val[i] = 100 * plus[i] - 50 * minus[i] + a[i] + b[i] + c[i] + d[i] + e[i];
    if (val[i] > max) {
      max = val[i];
      ans = i;
    }
  }
  cout << name[ans];
  return 0;
}
