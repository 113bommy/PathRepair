#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  int t;
  long long x, y, p, q, r, r1, r2;
  cin >> t;
  while (t--) {
    cin >> x >> y >> p >> q;
    if (p == 0) {
      if (x == 0)
        cout << "0" << endl;
      else
        cout << "-1" << endl;
    } else if (p == q) {
      if (x == 0)
        cout << "0" << endl;
      else
        cout << "-1" << endl;
    } else {
      r1 = ceil((double)x / (double)p);
      r2 = ceil((double)(y - x) / (double)(q - p));
      r = max(r1, r2);
      cout << ((q * r) - y) << endl;
    }
  }
  return 0;
}
