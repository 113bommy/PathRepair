#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 0, d = 0, s1 = 0, s2 = 0, e = 0;
  cin >> n;
  int a[n][2];
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
    if (a[i][0] % 2 != 0 && a[i][1] % 2 == 0) c = 1;
    if (a[i][0] % 2 == 0 && a[i][1] % 2 != 0) d = 1;
    if (a[i][0] % 2 != 0 && a[i][1] % 2 != 0) e = 1;
    s1 = s1 + a[i][0];
    s2 = s2 + a[i][1];
  }
  if (s2 % 2 == 0 && s1 % 2 == 0)
    cout << "0";
  else {
    if (s1 % 2 != 0 && s1 % 2 != 0) {
      if (c == 1 || d == 1)
        cout << "1";
      else
        cout << "-1";
    } else
      cout << "-1";
  }
  return 0;
}
