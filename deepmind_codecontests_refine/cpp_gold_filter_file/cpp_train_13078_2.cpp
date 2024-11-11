#include <bits/stdc++.h>
using namespace std;
int s[370];
int main() {
  int difmin = 360, n, i, x, j, dif;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> x;
    s[i] = s[i - 1] + x;
  }
  for (i = 1; i <= n; i++) {
    for (j = i; j <= n; j++) {
      dif = s[j] - s[i - 1];
      dif = dif - (360 - dif);
      if (dif < 0) dif = -dif;
      difmin = min(difmin, dif);
    }
  }
  cout << difmin;
  return 0;
}
