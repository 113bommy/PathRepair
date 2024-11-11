#include <bits/stdc++.h>
using namespace std;
int main() {
  int r1, r2, c1, c2;
  cin >> r1 >> c1 >> r2 >> c2;
  cout << 2 - (r1 == r2) - (c1 == c2) << " "
       << ((r1 + c1) % 2 == (c2 + r2) % 2) *
              (2 - (((r1 + c1) == (c2 + r2)) || ((r1 - c1) == (r2 - c2)))) *
              (r1 != r2 || c1 != c2)
       << " " << max(abs(r1 - r2), abs(c1 - c2)) << endl;
  return 0;
}
