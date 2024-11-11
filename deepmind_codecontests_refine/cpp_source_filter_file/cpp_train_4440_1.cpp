#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, g, b;
  cin >> r >> g >> b;
  int rm = (3 * (r + 1) / 2) + 27;
  int gm = (3 * (g + 1) / 2) + 28;
  int bm = (3 * (b + 1) / 2) + 29;
  int v = max(rm, gm);
  cout << max(v, bm) << endl;
  return 0;
}
