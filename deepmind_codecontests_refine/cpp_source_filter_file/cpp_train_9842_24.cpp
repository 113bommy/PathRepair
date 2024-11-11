#include <bits/stdc++.h>
using namespace std;
int main() {
  int d, h, v, e;
  double H_bg, H_dc, H_ic;
  while (cin >> d >> h >> v >> e) {
    H_bg = h;
    H_dc = v / (d * d * 3.1415926535897932 / 4);
    H_ic = e;
    if (H_dc <= H_ic)
      cout << "NO" << endl;
    else if (H_bg / (H_dc - H_ic) <= 1000)
      cout << "YES" << endl << H_bg / (H_dc - H_ic) << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
