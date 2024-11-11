#include <bits/stdc++.h>
int mod = 100000;
int negmod = -100000;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  cin >> q;
  while (q--) {
    cin >> n;
    int minx = -100000, maxx = 100000, miny = -100000, maxy = 100000;
    while (n--) {
      int posx, posy, f1, f2, f3, f4;
      cin >> posx >> posy >> f1 >> f2 >> f3 >> f4;
      if (f1 == 0) minx = max(posx, minx);
      if (f2 == 0) maxy = min(maxy, posy);
      if (f3 == 0) maxx = min(maxx, posx);
      if (f4 == 0) miny = min(miny, posy);
    }
    if (maxx < minx || miny > maxy)
      cout << "0" << endl;
    else {
      cout << "1"
           << " ";
      cout << minx << " " << miny << endl;
    }
  }
  return 0;
}
