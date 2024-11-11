#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1, a2, a3, b1, b2, b3, n, as, bs, asc, bsc, mas, mbs;
  cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;
  as = (a1 + a2 + a3) * 2;
  asc = as / 10;
  bs = (b1 + b2 + b3);
  bsc = bs / 10;
  mas = as % 10;
  mbs = bs % 10;
  if (mas != 0) {
    bsc = bsc + 1;
    if (mbs != 0) bsc = bsc + 1;
  } else if (mbs != 0) {
    bsc = bsc + 1;
    if (mas != 0) bsc = bsc + 1;
  }
  if ((bsc + asc) <= n) {
    cout << "YES";
  } else
    cout << "No";
}
