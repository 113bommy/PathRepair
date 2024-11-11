#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, p = 0, q, w, h, r;
  cin >> n;
  string a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == "ABSINTH" || a[i] == "BEER" || a[i] == "BRANDY" ||
        a[i] == "CHAMPAGNE" || a[i] == "GIN" || a[i] == "RUM" ||
        a[i] == "SAKE" || a[i] == "TEQUILA" || a[i] == "WHISKEY" ||
        a[i] == "VODKA" || a[i] == "WINE") {
      p++;
    }
    if (a[i].length() == 1) {
      q = a[i][0] - 48;
      if (q >= 0 && q < 10) p++;
    }
    if (a[i].length() == 2) {
      q = a[i][0] - 48;
      w = a[i][1] - 48;
      h = 10 * q + w;
      if (h < 18 && h >= 10) p++;
    }
  }
  cout << p;
}
