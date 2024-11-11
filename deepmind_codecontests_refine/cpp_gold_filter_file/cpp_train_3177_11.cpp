#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int x, y, z;
  cin >> x >> y >> z;
  int q, w, e;
  q = a - x;
  w = b - y;
  e = c - z;
  int need = 0;
  int avail = 0;
  if (q > 0) {
    avail += q / 2;
  }
  if (w > 0) {
    avail += w / 2;
  }
  if (e > 0) {
    avail += e / 2;
  }
  if (q < 0) {
    need -= q;
  }
  if (w < 0) {
    need -= w;
  }
  if (e < 0) {
    need -= e;
  }
  if (need <= avail) {
    cout << "Yes";
    return 0;
  }
  cout << "No";
}
