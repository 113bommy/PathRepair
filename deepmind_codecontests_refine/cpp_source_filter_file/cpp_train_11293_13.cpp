#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, w, e, r, t;
  char a[101][101], s[101][101];
  cin >> w >> q;
  for (e = 0; e < q; e++) {
    cin >> a[e];
    for (r = 0; r < w; r++) s[r][q - e - 1] = a[e][r];
  }
  e = q;
  q = w;
  w = e;
  for (e = 0; e < q; e++)
    for (r = w / 2; r >= 0; r--) {
      t = s[e][r];
      s[e][r] = s[e][w - r - 1];
      s[e][w - r - 1] = t;
    }
  for (e = 0; e < q; e++) {
    for (r = 0; r < w; r++) cout << s[e][r] << s[e][r];
    cout << "\n";
    for (r = 0; r < w; r++) cout << s[e][r] << s[e][r];
    cout << "\n";
  }
  return 0;
}
