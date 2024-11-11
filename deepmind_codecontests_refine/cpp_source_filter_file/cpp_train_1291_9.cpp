#include <bits/stdc++.h>
using namespace std;
ifstream fin("A.in");
ofstream fout("A.out");
int r, h;
int main() {
  cin >> r >> h;
  if (h % r == 0) {
    cout << (h / r) * 2 + 1;
    return 0;
  }
  double d = double(h) / double(r);
  int z = h / r;
  double dd = z + 0.5;
  if (d >= dd) {
    if ((r / 2) * (r / 2) + ((d - dd) * r + r / 2) * ((d - dd) * r + r / 2) >=
        r * r)
      cout << 2 * z + 3;
    else
      cout << 2 * z + 2;
  } else {
    cout << 2 * z + 1;
  }
}
