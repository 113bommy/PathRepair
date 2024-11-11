#include <bits/stdc++.h>
using namespace std;
int w[5] = {};
string x, s[5] = {"UL", "UR", "DL", "DR", "ULDR"};
int main(void) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    for (int j = 0; j < 5; j++)
      if (s[j] == x) ++w[j];
  }
  int a = w[0], b = w[1], c = w[2], d = w[3], e = w[4];
  int Px = (a + b), Py = (d - c), Qx = -(c + d), Qy = (a - b);
  int Ax = (Px + Py), Ay = (Px - Py), Bx = (Qx + Qy), By = (Qx - Qy);
  int Cx = abs((Bx - Ax) / 2) + 1 + e, Cy = abs((By - Ay) / 2) + 1 + e;
  printf("%I64d\n", Cx * 1LL * Cy);
  return 0;
}
