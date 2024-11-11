#include <bits/stdc++.h>
using namespace std;
void Filework(void) {
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
}
int x, y, z;
int xx, yy, zz;
int a1, a2, a3, a4, a5, a6;
int sum;
int main() {
  cin >> x >> y >> z >> xx >> yy >> zz >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
  if (z > zz) {
    sum += a2;
  } else if (0 <= z && z <= zz) {
  } else {
    sum += a1;
  }
  if (x > xx)
    sum += a6;
  else if (0 <= x && x <= xx) {
  } else
    sum += a5;
  if (y > yy)
    sum += a4;
  else if (0 <= y && y <= yy) {
  } else
    sum += a3;
  cout << sum << endl;
  return 0;
}
