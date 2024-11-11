#include <bits/stdc++.h>
using namespace std;
int main() {
  int d1, d2, w, h, u1, u2;
  cin >> w >> h >> u1 >> d1 >> u2 >> d2;
  if (d1 < d2) {
    swap(u1, u2);
    swap(d1, d2);
  }
  w += h * (h + 1) / 2 - d1 * (d1 - 1) / 2 - u1;
  if (w < 0) w = 0;
  w += d1 * (d1 - 1) / 2 - u2 - d2 * (d2 - 1);
  if (w < 0) w = 0;
  w += d2 * (d2 - 1);
  cout << w;
  return 0;
}
